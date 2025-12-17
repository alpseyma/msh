#include "Detector.h"

Detector::Detector() : m_next(0) {}
Detector::~Detector() {}

void Detector::setNext(Detector* next) {
    m_next = next;
}

bool Detector::handle() {
    bool detected = detect();

    if (detected && m_next) {
        // detection happened -> continue to action handlers
        m_next->handle();
    } else if (!detected && m_next) {
        // no detection -> try next detector in chain
        return m_next->handle();
    }

    return detected;
}


