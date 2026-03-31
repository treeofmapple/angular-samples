#ifndef MUSICDATA_H
#define MUSICDATA_H

#include <algorithm>
#include <optional>
#include <string>

struct MusicData {
  std::optional<std::string> track_popularity;
  std::optional<std::string> playlist_genre;
  std::optional<std::string> playlist_subgenre;
  std::optional<std::string> key;
  std::optional<std::string> loudness;
  std::optional<std::string> acousticness;
  std::optional<std::string> duration_ms;

  MusicData() {}
};

#endif
