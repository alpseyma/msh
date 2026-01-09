#include "LightCycleHandler.h"
#include "Logger.h"

bool LightCycleHandler::detect() {
    Logger::instance().warning("Alarm light cycle activated (simulated)");
    return false; // zincir devam etsin
}
