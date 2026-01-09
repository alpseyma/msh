#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <vector>
#include <string>
#include "SystemState.h"
#include "StateSnapshot.h"

class StateManager {
public:
    static StateManager& instance();

    // saveSnapshot=true ise önceki state history'ye kaydedilir.
    void setState(const std::string& stateName, bool saveSnapshot = true);
    std::string getCurrentState() const;

    void restoreLastState();

private:
    StateManager();
    StateManager(const StateManager&);
    StateManager& operator=(const StateManager&);

    void saveState();

    SystemState m_state;
    std::vector<StateSnapshot> m_history;
};

#endif

