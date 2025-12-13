add_executable(msh
    main.cpp
)

target_link_libraries(msh
    logger
    menu
    device
    mode
    state
    detection
    security
)
