#include "DeviceManager.h"
#include "Logger.h"

DeviceManager::DeviceManager() {}

DeviceManager& DeviceManager::instance() {
    static DeviceManager inst;
    return inst;
}

void DeviceManager::addDevice(Device* device) {
    m_devices[device->getId()] = device;
    Logger::instance().info("Device added: " + device->getId());
}

void DeviceManager::removeDevice(const std::string& id) {
    std::map<std::string, Device*>::iterator it = m_devices.find(id);

    if (it == m_devices.end()) {
        Logger::instance().warning("Remove failed, device not found: " + id);
        return;
    }

    m_devices.erase(it);
    Logger::instance().warning("Device removed: " + id);
}

void DeviceManager::turnOnAll() {
    for (auto it = m_devices.begin(); it != m_devices.end(); ++it) {
        it->second->on();
    }
}

void DeviceManager::turnOffAll() {
    for (auto it = m_devices.begin(); it != m_devices.end(); ++it) {
        it->second->off();
    }
}
