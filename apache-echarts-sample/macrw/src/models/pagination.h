#ifndef PAGINATION_H
#define PAGINATION_H

#include <algorithm>
#include <cstddef>

struct Pagination {
  size_t offset;
  size_t limit;

  Pagination() : offset(0), limit(100) {}

  Pagination(size_t off, size_t lim)
      : offset(off), limit(lim == 0 ? 100 : std::min(lim, (size_t)1000)) {}

  size_t start() const { return offset; }
  size_t end() const { return offset + limit; }
};
#endif
