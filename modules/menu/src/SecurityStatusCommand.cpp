#include "SecurityStatusCommand.h"
#include "SecurityManager.h"
#include "Logger.h"

void SecurityStatusCommand::execute() {
    if (SecurityManager::instance().isArmed()) {
        Logger::instance().info("Security status: ARMED");
    } else {
        Logger::instance().info("Security status: DISARMED");
    }
}
