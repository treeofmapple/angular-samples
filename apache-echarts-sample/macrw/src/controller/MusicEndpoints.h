#pragma once
#include <drogon/HttpController.h>

class MusicController : public drogon::HttpController<MusicController> {
public:
  METHOD_LIST_BEGIN
  METHOD_ADD(MusicController::fetchList, "/?offset={1}&limit={2}", Get);
  METHOD_LIST_END

  void fetchList(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback,
                 size_t offset, size_t limit);
};
