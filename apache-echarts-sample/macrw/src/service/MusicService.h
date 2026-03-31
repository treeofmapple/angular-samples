#pragma once

#include "model/Pagination.h"
#include <DataFrame/DataFrame.h>
#include <DataFrame/DataFrameTypes.h>
#include <DataFrame/DataFrameMLHelpers.h>
#include <DataFrame/DataFrameHeaders.h>
#include <DataFrame/DataFrameStatsVisitor.h>
#include <DataFrame/DataFrameIO.h>
#include <algorithm>
#include <iostream>
#include <json/json.h>
#include <string>

class MusicService {
private:
  hmdf::StdDataFrame<uint64_t> global_df;
  bool is_loaded = false;

  MusicService() = default;

public:
  static MusicService &instance() {
    static MusicService instance;
    return instance;
  }

  void load_data(const std::string &file_path) {
    if (!is_loaded) {
      try {
        global_df.read_csv<int, double, std::string>(file_path.c_str());
        is_loaded = true;
      } catch (const std::exception &e) {
        std::cerr << "Failed to load CSV: " << e.what() << std::endl;
      }
    }
  }

  Json::Value get_paginated_music(const Pagination &pg) {

    size_t total_rows = global_df.get_index().size();

    if (pg.start() >= total_rows) {
      return Json::Value(Json::arrayValue);
    }

    size_t start = pg.start();
    size_t end = std::min(pg.end(), total_rows);

    auto sliced_df = global_df.get_view(global_df.get_index().begin() + start,
                                        global_df.get_index().begin() + end);

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
    return json_res;
  }
};
