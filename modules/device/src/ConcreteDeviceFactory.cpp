#include "ConcreteDeviceFactory.h"
#include "CameraDevice.h"
#include "TVDevice.h"

Device* ConcreteDeviceFactory::createCamera(const std::string& id) {
    return new CameraDevice(id);
}

Device* ConcreteDeviceFactory::createTV(const std::string& id) {
    return new TVDevice(id);
}
