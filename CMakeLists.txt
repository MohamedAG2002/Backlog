cmake_minimum_required(VERSION 3.27.0)
set(CMAKE_CXX_STANDERD 20)
set(CMAKE_CXX_STANDERD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(backlog)

add_executable(${PROJECT_NAME} main.cpp)

# Will install the project to be able to be used as a CLI command
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
