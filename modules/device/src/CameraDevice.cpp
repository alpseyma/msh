#include "CameraDevice.h"
#include "Logger.h"

CameraDevice::CameraDevice(const std::string& id) : Device(id) {}

void CameraDevice::on()  { Logger::instance().info("Camera ON: " + m_id); }
void CameraDevice::off() { Logger::instance().info("Camera OFF: " + m_id); }

void CameraDevice::reportFailure() {
    Logger::instance().warning("Camera failure reported: " + m_id);
}

Device* CameraDevice::clone() const {
    return new CameraDevice(*this);
}
