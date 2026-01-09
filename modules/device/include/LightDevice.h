#ifndef LIGHT_DEVICE_H
#define LIGHT_DEVICE_H

#include "Device.h"

class LightDevice : public Device {
public:
    LightDevice(const std::string& id);

    void on() override;
    void off() override;

    // REQ10 - Prototype
    Device* clone() const override;

    // REQ9 - Failure (stub) - istersen ekle
    bool isFaulty() const override { return false; }
    void reportFailure() override;

};

#endif
