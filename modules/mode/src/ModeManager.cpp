#include "ModeManager.h"
#include "StateManager.h"
#include "Logger.h"

ModeManager::ModeManager()
    : m_currentMode(MODE_HOME) {}

ModeManager& ModeManager::instance() {
    static ModeManager instance;
    return instance;
}

void ModeManager::setMode(SystemMode mode) {
    m_currentMode = mode;

    switch (mode) {
        case MODE_HOME:
            StateManager::instance().setState("HOME");
            Logger::instance().info("Mode changed to HOME");
            break;

        case MODE_AWAY:
            StateManager::instance().setState("AWAY");
            Logger::instance().info("Mode changed to AWAY");
            break;

        case MODE_NIGHT:
            StateManager::instance().setState("NIGHT");
            Logger::instance().info("Mode changed to NIGHT");
            break;

        case MODE_EMERGENCY:
            StateManager::instance().setState("EMERGENCY");
            Logger::instance().warning("Mode changed to EMERGENCY");
            break;
    }
}

SystemMode ModeManager::getCurrentMode() const {
    return m_currentMode;
}
