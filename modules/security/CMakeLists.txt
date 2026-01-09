add_library(security STATIC
    src/SecurityManager.cpp
)

target_include_directories(security PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# ModeManager.h buradan geliyor
target_include_directories(security PRIVATE
    ${CMAKE_SOURCE_DIR}/modules/mode/include
)

target_link_libraries(security
    mode
    detection
    state
    logger
)

