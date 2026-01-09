#include "TurnOnDevicesCommand.h"
#include "DeviceManager.h"

void TurnOnDevicesCommand::execute() {
    DeviceManager::instance().turnOnAll();
}
