#ifndef SYSTEM_STATE_H
#define SYSTEM_STATE_H

#include <string>
#include "StateSnapshot.h"

class SystemState {
public:
    SystemState();

    void setState(const std::string& stateName);
    std::string getState() const;

    StateSnapshot save() const;
    void restore(const StateSnapshot& snapshot);

private:
    std::string m_currentState;
};

#endif
