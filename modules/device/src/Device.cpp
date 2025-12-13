#include "Device.h"

Device::Device(const std::string& id)
    : m_id(id) {}

Device::~Device() {}

std::string Device::getId() const {
    return m_id;
}
