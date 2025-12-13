#include "StateSnapshot.h"

StateSnapshot::StateSnapshot(const std::string& stateName)
    : m_stateName(stateName) {}

std::string StateSnapshot::getStateName() const {
    return m_stateName;
}
