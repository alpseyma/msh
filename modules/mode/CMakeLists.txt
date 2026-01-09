add_library(mode STATIC
    src/ModeManager.cpp
)

target_include_directories(mode PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(mode
    state
    logger
)

