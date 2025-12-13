#include <iostream>
#include "Logger.h"
#include "StateManager.h"

int main() {
    Logger::instance().info("MSH system started");
    Logger::instance().warning("This is a test warning");
    Logger::instance().error("This is a test error");
    StateManager::instance().setState("HOME");
    StateManager::instance().setState("AWAY");
    StateManager::instance().restoreLastState();

    return 0;
}

