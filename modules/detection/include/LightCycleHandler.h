#ifndef LIGHT_CYCLE_HANDLER_H
#define LIGHT_CYCLE_HANDLER_H

#include "Detector.h"

class LightCycleHandler : public Detector {
protected:
    bool detect() override;
};

#endif
