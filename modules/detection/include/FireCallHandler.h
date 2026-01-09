#ifndef FIRE_CALL_HANDLER_H
#define FIRE_CALL_HANDLER_H

#include "Detector.h"

class FireCallHandler : public Detector {
protected:
    bool detect() override;
};

#endif
