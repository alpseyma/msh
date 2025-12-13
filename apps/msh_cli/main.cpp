#include <iostream>
#include "Logger.h"
#include "StateManager.h"
#include "ModeManager.h"

int main() {
    Logger::instance().info("MSH system started");

    ModeManager::instance().setMode(MODE_HOME);
    ModeManager::instance().setMode(MODE_AWAY);
    ModeManager::instance().setMode(MODE_NIGHT);
    ModeManager::instance().setMode(MODE_EMERGENCY);

    StateManager::instance().restoreLastState();

    Logger::instance().info("MSH system shutdown");
    return 0;
}
