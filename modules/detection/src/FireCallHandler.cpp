#include "FireCallHandler.h"
#include "Logger.h"

bool FireCallHandler::detect() {
    Logger::instance().warning("Fire department has been notified (simulated)");
    return true; // zinciri burada kesmek mantıklı
}
