#ifndef MOTION_DETECTOR_H
#define MOTION_DETECTOR_H

#include "Detector.h"

class MotionDetector : public Detector {
protected:
    bool detect();
};

#endif
