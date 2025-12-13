#include "Logger.h"
#include "StateManager.h"
#include "ModeManager.h"
#include "DeviceManager.h"
#include "LightDevice.h"
#include "DetectionManager.h"
#include "MotionDetector.h"
#include "SmokeDetector.h"
#include "SecurityManager.h"

int main() {
    Logger::instance().info("MSH system started");

    // Normal mode test (EMERGENCY'yi Security tetiklesin)
    ModeManager::instance().setMode(MODE_HOME);
    ModeManager::instance().setMode(MODE_AWAY);
    ModeManager::instance().setMode(MODE_NIGHT);

    // Device test
    LightDevice light1("LivingRoomLight");
    LightDevice light2("KitchenLight");
    DeviceManager::instance().addDevice(&light1);
    DeviceManager::instance().addDevice(&light2);
    DeviceManager::instance().turnOnAll();
    DeviceManager::instance().turnOffAll();

    // Detection chain
    MotionDetector motion;
    SmokeDetector smoke;
    motion.setNext(&smoke);
    DetectionManager::instance().setChain(&motion);

    // Security should trigger EMERGENCY based on detection
    SecurityManager::instance().arm();
    SecurityManager::instance().runOnce();

    // Optional: try to restore (EMERGENCY should be non-revertible if you implemented saveSnapshot=false)
    StateManager::instance().restoreLastState();

    Logger::instance().info("MSH system shutdown");
    return 0;
}

