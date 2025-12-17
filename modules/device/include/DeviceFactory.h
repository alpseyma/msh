#ifndef DEVICE_FACTORY_H
#define DEVICE_FACTORY_H

#include "Device.h"
#include <string>

class DeviceFactory {
public:
    virtual ~DeviceFactory() = default;

    virtual Device* createCamera(const std::string& id) = 0;
    virtual Device* createTV(const std::string& id) = 0;
};

#endif
