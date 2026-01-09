add_library(state STATIC
    src/StateSnapshot.cpp
    src/SystemState.cpp
    src/StateManager.cpp
)

target_include_directories(state PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(state
    logger
)

