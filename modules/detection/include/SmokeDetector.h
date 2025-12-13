#ifndef SMOKE_DETECTOR_H
#define SMOKE_DETECTOR_H

#include "Detector.h"

class SmokeDetector : public Detector {
protected:
    bool detect();
};

#endif
