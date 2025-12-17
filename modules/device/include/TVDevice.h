#ifndef TV_DEVICE_H
#define TV_DEVICE_H

#include "Device.h"
#include <string>

class TVDevice : public Device {
public:
    explicit TVDevice(const std::string& id);

    void on() override;
    void off() override;
    void reportFailure() override;
    Device* clone() const override;
};

#endif
