#include "../model/DataChart.h"
#include <filesystem>
#include <iostream>
#include <stdexcept>

namespace fs = std::filesystem;

class ExtractService {
private:
  std::string getEnvVar(const std::string &key) {
    std::ifstream envFile(".env");
    std::string line;
    while (std::getline(envFile, line)) {
      if (line.find(key + "=") == 0) {
        return line.substr(key.length() + 1);
      }
    }
    return "";
  }

public:
  void loadData(StdDataFrame<uint64_t> &df) {
    std::string envPath = getEnvVar("DATA_PATH");
    if (envPath.empty()) {
      throw std::runtime_error("DATA_PATH not found in .env file");
    }

    fs::path dataPath(envPath);

    if (dataPath.is_relative()) {
      dataPath = fs::current_path() / dataPath;
    }

    if (fs::exists(dataPath)) {
      std::cout << "Loading data from: " << fs::absolute(dataPath) << std::endl;
      df.read(dataPath.string().c_str(), io_format::csv2);
    } else {
      throw std::runtime_error("Could not find .csv in the data folder.");
    }
  }
}
