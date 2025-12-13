#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device {
public:
    Device(const std::string& id);
    virtual ~Device();

    std::string getId() const;

    virtual void on() = 0;
    virtual void off() = 0;

protected:
    std::string m_id;
};

#endif
