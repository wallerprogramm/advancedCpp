cmake_minimum_required(VERSION 3.0.0)
project(bin_op)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
