#include "Logger.h"
#include "StateManager.h"
#include "ModeManager.h"
#include "DeviceManager.h"
#include "LightDevice.h"
#include "DetectionManager.h"
#include "MotionDetector.h"
#include "SmokeDetector.h"

int main() {
    Logger::instance().info("MSH system started");

    // Mode test
    ModeManager::instance().setMode(MODE_HOME);
    ModeManager::instance().setMode(MODE_AWAY);
    ModeManager::instance().setMode(MODE_NIGHT);
    ModeManager::instance().setMode(MODE_EMERGENCY);

    // State undo test
    StateManager::instance().restoreLastState();

    // Device test
    LightDevice light1("LivingRoomLight");
    LightDevice light2("KitchenLight");

    DeviceManager::instance().addDevice(&light1);
    DeviceManager::instance().addDevice(&light2);

    DeviceManager::instance().turnOnAll();
    DeviceManager::instance().turnOffAll();

    // Detection test
    MotionDetector motion;
    SmokeDetector smoke;
    motion.setNext(&smoke);

    DetectionManager::instance().setChain(&motion);
    DetectionManager::instance().process();

    Logger::instance().info("MSH system shutdown");
    return 0;
}

