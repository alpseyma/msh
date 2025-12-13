add_library(security STATIC
    src/SecurityManager.cpp
)

target_include_directories(security PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(security
    detection
    state
    logger
)

