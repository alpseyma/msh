#include "LightDevice.h"
#include "Logger.h"

LightDevice::LightDevice(const std::string& id)
    : Device(id) {}

void LightDevice::on() {
    Logger::instance().info("Light ON: " + m_id);
}

void LightDevice::off() {
    Logger::instance().info("Light OFF: " + m_id);
}

void LightDevice::reportFailure() {
    Logger::instance().warning("Device failure reported: " + m_id);
}

Device* LightDevice::clone() const {
    return new LightDevice(*this);
}
