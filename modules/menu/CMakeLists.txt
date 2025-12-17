add_library(menu STATIC
    src/Menu.cpp
    src/SetModeCommand.cpp
    src/TurnOnDevicesCommand.cpp
    src/TurnOffDevicesCommand.cpp
    src/ArmSecurityCommand.cpp
    src/DisarmSecurityCommand.cpp
    src/RunSecurityCheckCommand.cpp
    src/SecurityStatusCommand.cpp
    src/ShowManualCommand.cpp
)

target_include_directories(menu PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(menu
    mode
    device
    security
    logger
)

