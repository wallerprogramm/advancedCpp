cmake_minimum_required(VERSION 3.0.0)
project(rpn_calculator)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    fraction.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
