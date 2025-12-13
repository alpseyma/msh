#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <vector>
#include "SystemState.h"

class StateManager {
public:
    static StateManager& instance();

    void setState(const std::string& stateName);
    std::string getCurrentState() const;

    void saveState();
    void restoreLastState();

private:
    StateManager();
    StateManager(const StateManager&);
    StateManager& operator=(const StateManager&);

    SystemState m_state;
    std::vector<StateSnapshot> m_history;
};

#endif
