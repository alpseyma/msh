#ifndef DETECTION_MANAGER_H
#define DETECTION_MANAGER_H

#include "Detector.h"

class DetectionManager {
public:
    static DetectionManager& instance();

    void setChain(Detector* first);
    bool process();

private:
    DetectionManager();
    DetectionManager(const DetectionManager&);
    DetectionManager& operator=(const DetectionManager&);

    Detector* m_chain;
};

#endif
