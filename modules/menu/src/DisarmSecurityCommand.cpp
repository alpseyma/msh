#include "DisarmSecurityCommand.h"
#include "SecurityManager.h"

void DisarmSecurityCommand::execute() {
    SecurityManager::instance().disarm();
}
