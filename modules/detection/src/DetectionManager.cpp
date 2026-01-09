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

bool DetectionManager::process() {
    if (m_chain) {
        return m_chain->handle();
    }
    Logger::instance().warning("Detection chain is empty");
    return false;
}
