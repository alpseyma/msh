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

    // REQ10 - Prototype
    virtual Device* clone() const = 0;

    // REQ9 - Failure (stub)
    virtual bool isFaulty() const { return false; }
    virtual void reportFailure() {}

protected:
    std::string m_id;
};

#endif
