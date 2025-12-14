#include "TurnOffDevicesCommand.h"
#include "DeviceManager.h"

void TurnOffDevicesCommand::execute() {
    DeviceManager::instance().turnOffAll();
}

