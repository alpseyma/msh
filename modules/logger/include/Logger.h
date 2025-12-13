#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
public:
    enum Level {
        INFO,
        WARNING,
        ERROR
    };

    static Logger& instance();

    void log(Level level, const std::string& message);

    void info(const std::string& message);
    void warning(const std::string& message);
    void error(const std::string& message);

private:
    Logger();
    Logger(const Logger&);
    Logger& operator=(const Logger&);
};

#endif
