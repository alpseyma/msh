add_library(device STATIC
    src/CameraDevice.cpp
    src/ConcreteDeviceFactory.cpp
    src/Device.cpp
    src/DeviceManager.cpp
    src/LightDevice.cpp
    src/TVDevice.cpp
)

target_include_directories(device PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(device
    logger
)

