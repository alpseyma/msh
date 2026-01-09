#ifndef RUN_DETECTION_TEST_COMMAND_H
#define RUN_DETECTION_TEST_COMMAND_H

#include "Command.h"

class RunDetectionTestCommand : public Command {
public:
    void execute() override;
};

#endif
