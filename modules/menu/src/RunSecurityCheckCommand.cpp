#include "RunSecurityCheckCommand.h"
#include "SecurityManager.h"

void RunSecurityCheckCommand::execute() {
    SecurityManager::instance().runOnce();
}
