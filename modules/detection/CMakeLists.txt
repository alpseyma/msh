add_library(detection STATIC
    src/Detector.cpp
    src/MotionDetector.cpp
    src/SmokeDetector.cpp
    src/DetectionManager.cpp
)

target_include_directories(detection PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(detection
    logger
)

