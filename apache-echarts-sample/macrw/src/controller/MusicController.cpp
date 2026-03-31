#include "MusicController.h"
#include "MusicService.h"

void MusicController::fetchList(
    const HttpRequestPtr &req,
    std::function<void(const HttpResponsePtr &)> &&callback, size_t offset,
    size_t limit) {

  Pagination pg(offset, limit);
  Json::Value music_data = MusicService::instance().get_paginated_music(pg);
  auto resp = HttpResponse::newHttpJsonResponse(music_data);
  callback(resp);
}
