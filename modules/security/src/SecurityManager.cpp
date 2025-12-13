#include "SecurityManager.h"
#include "DetectionManager.h"
#include "StateManager.h"
#include "Logger.h"
#include "ModeManager.h"


SecurityManager::SecurityManager() : m_armed(false) {}

SecurityManager& SecurityManager::instance() {
    static SecurityManager instance;
    return instance;
}

void SecurityManager::arm() {
    m_armed = true;
    Logger::instance().info("Security system armed");
}

void SecurityManager::disarm() {
    m_armed = false;
    Logger::instance().info("Security system disarmed");
}

bool SecurityManager::isArmed() const {
    return m_armed;
}

void SecurityManager::runOnce() {
    if (!m_armed) {
        Logger::instance().warning("Security check skipped (system is disarmed)");
        return;
    }

    bool detected = DetectionManager::instance().process();

    if (detected) {
        Logger::instance().warning("Security alert: switching to EMERGENCY mode");
        ModeManager::instance().setMode(MODE_EMERGENCY);
    } else {
        Logger::instance().info("Security check: no threat detected");
    }
}

