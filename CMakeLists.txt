cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "-Werror -Wall -g -pedantic")

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/third_party)

enable_testing()

project(ConfigurationSystem LANGUAGES CXX VERSION 1.0.0)

add_subdirectory(src)
add_subdirectory(tests)
