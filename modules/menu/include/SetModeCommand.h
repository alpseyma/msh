#ifndef SET_MODE_COMMAND_H
#define SET_MODE_COMMAND_H

#include "Command.h"
#include "SystemMode.h"

class SetModeCommand : public Command {
public:
    SetModeCommand(SystemMode mode);
    void execute();

private:
    SystemMode m_mode;
};

#endif
