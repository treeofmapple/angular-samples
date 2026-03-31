#include <fstream>
#include <sstream>

void loadEnv(const std::string &path = ".env") {
  std::ifstream envFile(path);
  if (!envFile.is_open()) {
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

      setenv(key.c_str(), value.c_str(), 1);
    }
  }
}
