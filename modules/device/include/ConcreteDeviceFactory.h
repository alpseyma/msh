#ifndef CONCRETE_DEVICE_FACTORY_H
#define CONCRETE_DEVICE_FACTORY_H

#include "DeviceFactory.h"

class ConcreteDeviceFactory : public DeviceFactory {
public:
    Device* createCamera(const std::string& id) override;
    Device* createTV(const std::string& id) override;
};

#endif
