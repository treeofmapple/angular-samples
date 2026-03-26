#include <DataFrame/DataFrame.h>
#include <DataFrame/DataFrameMLHelpers.h>
#include <drogon/drogon.h>
#include <drogon/HttpController.h>
#include <vector>
#include <cstdint>
#include <string.h>

using namespace drogon;
using namespace hmdf;

struct Pagination {
  size_t offset;
  size_t limit;
};

class DataChart : public HttpController<DataChart> {
    StdDataFrame<uint64_t> global_df;
public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(DataChart::get_chart_data,
                "/chart_data?offset={offset}&limit={limit}", Get);
  METHOD_LIST_END

  void get_chart_data(const HttpRequestPtr &req,
                      std::function<void(const HttpRequestPtr &)> &&callback) {

    auto &offset_str = req->getParameter("offset");
    auto &limit_str = req->getParameter("limit");

    size_t offset = std::stoul(offset_str.empty() ? "0" : offset_str);
    size_t limit = std::stoul(limit_str.empty() ? "100" : limit_str);

    try {

      global_df.read_csv<int, double, std::string>("spotify_songs.csv");

      auto sliced_df = global_df.get_view(std::IndexView<uint64_t>{offset, offset + limit});

      const auto &pop = sliced_df.get_column<int>("track_popularity");
      const auto &genre = sliced_df.get_column<std::string>("playlist_genre");
      const auto &subgenre = sliced_df.get_column<std::string>("playlist_subgenre");
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

      auto resp = HttpResponse::newHttpJsonResponse(json_res);
      callback(resp);
    } catch (const std::exception &e) {
      auto resp = HttpResponse::newHttpResponse();
      resp->setStatusCode(drogon::k500InternalServerError);
      resp->setBody(std::string("Error processing data: ") + e.what());
      callback(resp);
    }
  }
};
