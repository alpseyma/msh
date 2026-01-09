
#ifndef SHOW_MANUAL_COMMAND_H
#define SHOW_MANUAL_COMMAND_H

#include "Command.h"

class ShowManualCommand : public Command {
public:
    void execute() override;
};

#endif
