#include <iostream>
#include "Logger.h"
#include "StateManager.h"
#include "ModeManager.h"
#include "DeviceManager.h"
#include "LightDevice.h"

int main() {
    Logger::instance().info("MSH system started");

    ModeManager::instance().setMode(MODE_HOME);
    ModeManager::instance().setMode(MODE_AWAY);
    ModeManager::instance().setMode(MODE_NIGHT);
    ModeManager::instance().setMode(MODE_EMERGENCY);

    StateManager::instance().restoreLastState();

    LightDevice light1("LivingRoomLight");
    LightDevice light2("KitchenLight");

    DeviceManager::instance().addDevice(&light1);
    DeviceManager::instance().addDevice(&light2);

    DeviceManager::instance().turnOnAll();
    DeviceManager::instance().turnOffAll();
    Logger::instance().info("MSH system shutdown");
    return 0;
}
