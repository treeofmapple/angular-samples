#pragma once
#include "music.h"
#include "pagination.h"
#include <hmdf/DataFrame.cpp>
#include <json/json.h>

class MusicService {
private:
  hmdf::StdDataFrame<uint64_t> global_df;
  bool is_loaded = false;
  MusicService() = default;

public:
  static MusicService &instance();

  void load_data(const std::string &file_path);
  Json::Value get_paginated_music(const Pagination &pg);
}
