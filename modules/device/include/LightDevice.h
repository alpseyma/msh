#ifndef LIGHT_DEVICE_H
#define LIGHT_DEVICE_H

#include "Device.h"

class LightDevice : public Device {
public:
    LightDevice(const std::string& id);

    void on();
    void off();
};

#endif
