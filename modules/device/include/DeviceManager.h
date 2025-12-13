#ifndef DEVICE_MANAGER_H
#define DEVICE_MANAGER_H

#include <map>
#include <string>
#include "Device.h"

class DeviceManager {
public:
    static DeviceManager& instance();

    void addDevice(Device* device);
    void removeDevice(const std::string& id);

    void turnOnAll();
    void turnOffAll();

private:
    DeviceManager();
    DeviceManager(const DeviceManager&);
    DeviceManager& operator=(const DeviceManager&);

    std::map<std::string, Device*> m_devices;
};

#endif
