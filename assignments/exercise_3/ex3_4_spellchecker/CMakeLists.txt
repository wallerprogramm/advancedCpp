cmake_minimum_required(VERSION 3.0.0)
project(spellchecker)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    main.cpp
    spellchecker.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
