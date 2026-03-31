#include <DataFrame/DataFrame.h>
#include <DataFrame/DataFrameStatsVisitors.h>
#include <DataFrame/Utils/DateTime.h>
#include <algorithm>
#include <cstdint>
#include <drogon/HttpController.h>
#include <drogon/drogon.h>
#include <string>

using namespace drogon;
using namespace hmdf;

class DataChart : public HttpController<DataChart> {
  StdDataFrame<uint64_t> global_df;

public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(DataChart::get_chart_data, "/chart", Get);
  METHOD_LIST_END

  void get_chart_data(const HttpRequestPtr &req,
                      std::function<void(const HttpResponsePtr &)> &&callback) {

    /* Data Size */
    auto &offset_str = req->getParameter("offset");
    auto &limit_str = req->getParameter("limit");

    Pagination page;
    page.offset = std::stoul(offset_str.empty() ? "0" : offset_str);
    page.limit = std::stoul(limit_str.empty() ? "100" : limit_str);

    try {

      if (global_df.empty()) {
        global_df.read("spotify_songs.csv", io_format::csv2);
      }

      const auto &full_index = global_df.get_index();

      size_t end_idx = std::min(page.offset + page.limit, full_index.size());
      std::vector<uint64_t> view_index(full_index.begin() + page.offset,
                                       full_index.begin() + end_idx);

      auto sliced_df = global_df.get_view_by_idx(view_index);

      const auto &pop = sliced_df.get_column<int>("track_popularity");
      const auto &genre = sliced_df.get_column<std::string>("playlist_genre");
      const auto &subgenre =
          sliced_df.get_column<std::string>("playlist_subgenre");
      const auto &key = sliced_df.get_column<int>("key");
      const auto &loud = sliced_df.get_column<double>("loudness");
      const auto &acoustic = sliced_df.get_column<double>("acousticness");
      const auto &dur = sliced_df.get_column<double>("duration_ms");

      Json::Value json_res(Json::arrayValue);

      for (size_t i = 0; i < pop.size(); ++i) {
        Json::Value item;
        item["track_popularity"] = pop[i];
        item["playlist_genre"] = genre[i];
        item["playlist_subgenre"] = subgenre[i];
        item["key"] = key[i];
        item["loudness"] = loud[i];
        item["acousticness"] = acoustic[i];
        item["duration_ms"] = dur[i];
        json_res.append(item);
      }
      Json::Value data_array(Json::objectValue);

      data_array["data"] = json_res;
      Json::Value meta;
      meta["offset"] = (Json::UInt64)page.offset;
      meta["limit"] = (Json::UInt64)page.limit;
      meta["total"] = (Json::UInt64)full_index.size();
      meta["has_more"] = (page.offset + page.limit) < full_index.size();

      data_array["meta"] = meta;

      auto resp = HttpResponse::newHttpJsonResponse(data_array);
      callback(resp);

    } catch (const std::exception &e) {

      auto resp = HttpResponse::newHttpResponse();
      resp->setStatusCode(drogon::k500InternalServerError);
      resp->setBody(std::string("Error processing data: ") + e.what());
      callback(resp);
    }
  }
};
