#pragma once
#include <drogon/HttpController.h>

using namespace drogon;

class Music : public drogon::HttpController<Music> {
public:
  METHOD_LIST_BEGIN
  METHOD_ADD(Music::getOne, "/{id}", Get);
  METHOD_ADD(Music::create, "/", Post);
  METHOD_ADD(Music::update, "/{id}", Put);
  METHOD_ADD(Music::deleteOne, "/{id}", Delete);
  METHOD_LIST_END

  void getOne(const HttpRequestPtr &req,
              std::function<void(const HttpResponsePtr &)> &&callback, int id);
  void fetchList(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback);
};
