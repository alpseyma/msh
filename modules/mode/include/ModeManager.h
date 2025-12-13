#ifndef MODE_MANAGER_H
#define MODE_MANAGER_H

#include "SystemMode.h"

class ModeManager {
public:
    static ModeManager& instance();

    void setMode(SystemMode mode);
    SystemMode getCurrentMode() const;

private:
    ModeManager();
    ModeManager(const ModeManager&);
    ModeManager& operator=(const ModeManager&);

    SystemMode m_currentMode;
};

#endif
