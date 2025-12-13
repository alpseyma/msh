#include "Detector.h"

Detector::Detector() : m_next(0) {}
Detector::~Detector() {}

void Detector::setNext(Detector* next) {
    m_next = next;
}

bool Detector::handle() {
    if (detect()) {
        return true;
    }
    if (m_next) {
        return m_next->handle();
    }
    return false;
}

