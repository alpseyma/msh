#include "DetectionManager.h"
#include "Logger.h"

DetectionManager::DetectionManager() : m_chain(0) {}

DetectionManager& DetectionManager::instance() {
    static DetectionManager instance;
    return instance;
}

void DetectionManager::setChain(Detector* first) {
    m_chain = first;
    Logger::instance().info("Detection chain configured");
}

void DetectionManager::process() {
    if (m_chain) {
        m_chain->handle();
    } else {
        Logger::instance().warning("Detection chain is empty");
    }
}
