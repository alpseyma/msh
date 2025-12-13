#include "Detector.h"

Detector::Detector() : m_next(0) {}
Detector::~Detector() {}

void Detector::setNext(Detector* next) {
    m_next = next;
}

void Detector::handle() {
    if (!detect() && m_next) {
        m_next->handle();
    }
}
