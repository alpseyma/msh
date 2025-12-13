#ifndef STATE_SNAPSHOT_H
#define STATE_SNAPSHOT_H

#include <string>

class StateSnapshot {
public:
    StateSnapshot(const std::string& stateName);

    std::string getStateName() const;

private:
    std::string m_stateName;
};

#endif
