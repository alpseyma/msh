#include "ArmSecurityCommand.h"
#include "SecurityManager.h"

void ArmSecurityCommand::execute() {
    SecurityManager::instance().arm();
}
