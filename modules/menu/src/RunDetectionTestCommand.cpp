#include "RunSecurityCheckCommand.h"
#include "DetectionManager.h"
#include "Logger.h"

void RunSecurityCheckCommand::execute() {
    Logger::instance().info("Running security detection test");
    DetectionManager::instance().process();
}
