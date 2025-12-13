#include <iostream>
#include "Logger.h"

int main() {
    Logger::instance().info("MSH system started");
    Logger::instance().warning("This is a test warning");
    Logger::instance().error("This is a test error");
    return 0;
}

