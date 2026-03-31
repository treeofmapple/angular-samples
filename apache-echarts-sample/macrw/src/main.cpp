#include "config/EnvFetcher.h"
#include <cstdint>
#include <cstdlib>
#include <service/MusicService.h>
#include <drogon/drogon.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {

  EnvFetcher::loadEnv(".env");

  const char *env_port = getenv("PORT");
  uint16_t port = env_port ? static_cast<uint16_t>(atoi(env_port)) : 8000;

  MusicService::instance().load_data("data/spotify_songs.csv");
  cout << "Server starting on port: " << port << endl;

  drogon::app().addListener("0.0.0.0", port).run();
  return 0;
}
