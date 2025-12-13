#include "DeviceManager.h"
#include "Logger.h"

DeviceManager::DeviceManager() {}

DeviceManager& DeviceManager::instance() {
    static DeviceManager instance;
    return instance;
}

void DeviceManager::addDevice(Device* device) {
    m_devices[device->getId()] = device;
    Logger::instance().info("Device added: " + device->getId());
}

void DeviceManager::removeDevice(const std::string& id) {
    m_devices.erase(id);
    Logger::instance().warning("Device removed: " + id);
}

void DeviceManager::turnOnAll() {
    for (std::map<std::string, Device*>::iterator it = m_devices.begin();
         it != m_devices.end(); ++it) {
        it->second->on();
    }
}

void DeviceManager::turnOffAll() {
    for (std::map<std::string, Device*>::iterator it = m_devices.begin();
         it != m_devices.end(); ++it) {
        it->second->off();
    }
}
