#include "Logger.h"

#include "Menu.h"
#include "SetModeCommand.h"
#include "TurnOnDevicesCommand.h"
#include "TurnOffDevicesCommand.h"
#include "ArmSecurityCommand.h"
#include "DisarmSecurityCommand.h"
#include "RunSecurityCheckCommand.h"
#include "SecurityStatusCommand.h"

#include "DeviceManager.h"
#include "LightDevice.h"

#include <iostream>

int main() {
    Logger::instance().info("MSH system started");

    LightDevice light1("LivingRoomLight");
    LightDevice light2("KitchenLight");
    DeviceManager::instance().addDevice(&light1);
    DeviceManager::instance().addDevice(&light2);

    Menu menu;

    SetModeCommand home(MODE_HOME);
    SetModeCommand away(MODE_AWAY);
    SetModeCommand night(MODE_NIGHT);

    TurnOnDevicesCommand onCmd;
    TurnOffDevicesCommand offCmd;

    ArmSecurityCommand armCmd;
    DisarmSecurityCommand disarmCmd;
    RunSecurityCheckCommand checkCmd;
    SecurityStatusCommand statusCmd;

    menu.addCommand(1, "Set Mode: HOME", &home);
    menu.addCommand(2, "Set Mode: AWAY", &away);
    menu.addCommand(3, "Set Mode: NIGHT", &night);
    menu.addCommand(4, "Turn ON all devices", &onCmd);
    menu.addCommand(5, "Turn OFF all devices", &offCmd);
    menu.addCommand(6, "Arm security", &armCmd);
    menu.addCommand(7, "Disarm security", &disarmCmd);
    menu.addCommand(8, "Run security check", &checkCmd);
    menu.addCommand(9, "Security status", &statusCmd);

    int choice = 0;
    while (choice != -1) {
        menu.show();
        std::cout << "-1) Exit\nSelect: ";
        std::cin >> choice;
        if (choice != -1) {
            menu.handleInput(choice);
        }
    }

    Logger::instance().info("MSH system shutdown");
    return 0;
}

