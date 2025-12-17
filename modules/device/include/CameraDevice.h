#ifndef CAMERA_DEVICE_H
#define CAMERA_DEVICE_H

#include "Device.h"
#include <string>

class CameraDevice : public Device {
public:
    explicit CameraDevice(const std::string& id);

    void on() override;
    void off() override;
    void reportFailure() override;
    Device* clone() const override;
};

#endif
