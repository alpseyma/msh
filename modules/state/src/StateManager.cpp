#include "StateManager.h"
#include "Logger.h"

StateManager::StateManager() {}

StateManager& StateManager::instance() {
    static StateManager instance;
    return instance;
}

void StateManager::setState(const std::string& stateName, bool saveSnapshot) {
    if (saveSnapshot) {
        saveState();
    }
    m_state.setState(stateName);
    Logger::instance().info("State changed to: " + stateName);
}

std::string StateManager::getCurrentState() const {
    return m_state.getState();
}

void StateManager::saveState() {
    m_history.push_back(m_state.save());
}

void StateManager::restoreLastState() {
    if (m_history.empty()) {
        Logger::instance().warning("No previous state to restore");
        return;
    }

    StateSnapshot snapshot = m_history.back();
    m_history.pop_back();
    m_state.restore(snapshot);
    Logger::instance().info("State restored to: " + snapshot.getStateName());
}

