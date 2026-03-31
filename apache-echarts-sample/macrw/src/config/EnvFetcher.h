#pragma once
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

class EnvFetcher {
public:
  static void loadEnv(const std::string &path = ".env") {
    std::ifstream envFile(path);
    if (!envFile.is_open()) {
      std::cerr << "Warning: Could not open " << path << std::endl;
      return;
    }

    std::string line;
    while (std::getline(envFile, line)) {
      if (line.empty() || line[0] == '#')
        continue;

      auto delimiterPos = line.find('=');
      if (delimiterPos != std::string::npos) {
        std::string key = line.substr(0, delimiterPos);
        std::string value = line.substr(delimiterPos + 1);

#ifdef _WIN32
        _putenv_s(key.c_str(), value.c_str());
#else
        setenv(key.c_str(), value.c_str(), 1);
#endif
      }
    }
  }
};
