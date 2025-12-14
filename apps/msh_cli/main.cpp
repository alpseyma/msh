#include "Logger.h"

#include "Menu.h"
#include "SetModeCommand.h"
#include "TurnOnDevicesCommand.h"
#include "TurnOffDevicesCommand.h"
#include "ArmSecurityCommand.h"

#include "DeviceManager.h"
#include "LightDevice.h"

#include <iostream>

int main() {
    Logger::instance().info("MSH system started");

    // Demo devices (so ON/OFF commands do something)
    LightDevice light1("LivingRoomLight");
    LightDevice light2("KitchenLight");
    DeviceManager::instance().addDevice(&light1);
    DeviceManager::instance().addDevice(&light2);

    Menu menu;

    SetModeCommand cmdHome(MODE_HOME);
    SetModeCommand cmdAway(MODE_AWAY);
    SetModeCommand cmdNight(MODE_NIGHT);

    TurnOnDevicesCommand cmdOn;
    TurnOffDevicesCommand cmdOff;

    ArmSecurityCommand cmdArm;

    menu.addCommand(1, &cmdHome);
    menu.addCommand(2, &cmdAway);
    menu.addCommand(3, &cmdNight);
    menu.addCommand(4, &cmdOn);
    menu.addCommand(5, &cmdOff);
    menu.addCommand(6, &cmdArm);

    int choice = 0;
    while (choice != -1) {
        std::cout << "1) Set Mode: HOME\n";
        std::cout << "2) Set Mode: AWAY\n";
        std::cout << "3) Set Mode: NIGHT\n";
        std::cout << "4) Turn ON all devices\n";
        std::cout << "5) Turn OFF all devices\n";
        std::cout << "6) Arm security\n";
        std::cout << "-1) Exit\n";
        std::cout << "Select: ";

        std::cin >> choice;
        if (choice != -1) {
            menu.handleInput(choice);
        }
    }

    Logger::instance().info("MSH system shutdown");
    return 0;
}

