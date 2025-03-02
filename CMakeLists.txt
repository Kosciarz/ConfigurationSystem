cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_FLAGS "-Werror -Wall -g -pedantic")

set(SOURCES
    "src/Main.cpp"
    "src/Config.cpp"
    "src/ConfigSerializer.cpp"
)

include(FetchContent)

set(FETCHCONTENT_BASE_DIR ${CMAKE_SOURCE_DIR}/third_party)

FetchContent_Declare(
    json
    https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()
FetchContent_MakeAvailable(googletest)

enable_testing()

project(ConfigurationSystem LANGUAGES CXX VERSION 1.0.0)

add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src/include)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)


include(GoogleTest)