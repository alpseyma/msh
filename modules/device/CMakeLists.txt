add_library(device STATIC
    src/Device.cpp
    src/DeviceManager.cpp
    src/LightDevice.cpp
)

target_include_directories(device PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(device
    logger
)

