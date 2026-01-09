#include "AlarmHandler.h"
#include "Logger.h"

bool AlarmHandler::detect() {
    Logger::instance().warning("ALARM TRIGGERED");
    return false; // zincir devam etsin
}
