#pragma once
#include <string>
#include <map>

class AppConfig {
private:
    std::map<std::string, std::string> _settings;
    AppConfig() {}

public:
    static AppConfig& instance() {
        static AppConfig inst;
        return inst;
    }

};
