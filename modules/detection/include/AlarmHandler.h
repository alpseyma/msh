#ifndef ALARM_HANDLER_H
#define ALARM_HANDLER_H

#include "Detector.h"

class AlarmHandler : public Detector {
protected:
    bool detect() override;
};

#endif
