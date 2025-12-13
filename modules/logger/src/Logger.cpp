#include "Logger.h"
#include <iostream>

Logger::Logger() {}

Logger& Logger::instance() {
    static Logger instance;
    return instance;
}

void Logger::log(Level level, const std::string& message) {
    switch (level) {
        case INFO:
            std::cout << "[INFO] ";
            break;
        case WARNING:
            std::cout << "[WARNING] ";
            break;
        case ERROR:
            std::cout << "[ERROR] ";
            break;
    }
    std::cout << message << std::endl;
}

void Logger::info(const std::string& message) {
    log(INFO, message);
}

void Logger::warning(const std::string& message) {
    log(WARNING, message);
}

void Logger::error(const std::string& message) {
    log(ERROR, message);
}
