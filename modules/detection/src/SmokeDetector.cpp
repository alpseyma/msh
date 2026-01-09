#include "SmokeDetector.h"
#include "Logger.h"

bool SmokeDetector::detect() {
    Logger::instance().warning("SmokeDetector: smoke detected!");
    return true; // olayı işledim → zincir durur
}
