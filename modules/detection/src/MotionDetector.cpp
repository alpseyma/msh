#include "MotionDetector.h"
#include "Logger.h"

bool MotionDetector::detect() {
    Logger::instance().info("MotionDetector: no motion detected");
    return false; // handled mi? hayır → zincire devam
}
