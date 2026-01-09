#include "SystemState.h"

SystemState::SystemState()
    : m_currentState("INITIAL") {}

void SystemState::setState(const std::string& stateName) {
    m_currentState = stateName;
}

std::string SystemState::getState() const {
    return m_currentState;
}

StateSnapshot SystemState::save() const {
    return StateSnapshot(m_currentState);
}

void SystemState::restore(const StateSnapshot& snapshot) {
    m_currentState = snapshot.getStateName();
}
