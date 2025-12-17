#include "TVDevice.h"
#include "Logger.h"

TVDevice::TVDevice(const std::string& id) : Device(id) {}

void TVDevice::on()  { Logger::instance().info("TV ON: " + m_id); }
void TVDevice::off() { Logger::instance().info("TV OFF: " + m_id); }

void TVDevice::reportFailure() {
    Logger::instance().warning("TV failure reported: " + m_id);
}

Device* TVDevice::clone() const {
    return new TVDevice(*this);
}
