cmake_minimum_required(VERSION 3.25)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "-Werror -Wall -g -pedantic")

set(SOURCES
    "src/Main.cpp"
    "src/Config.cpp"
    "src/ConfigSerializer.cpp"
)

project(ConfigurationSystem LANGUAGES CXX VERSION 1.0.0)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
