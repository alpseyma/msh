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
