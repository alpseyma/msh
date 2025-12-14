cmake_minimum_required(VERSION 3.16)
project(MSH LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(modules/logger)
add_subdirectory(modules/menu)
add_subdirectory(modules/device)
add_subdirectory(modules/mode)
add_subdirectory(modules/state)
add_subdirectory(modules/detection)
add_subdirectory(modules/security)

add_subdirectory(apps/msh_cli)

