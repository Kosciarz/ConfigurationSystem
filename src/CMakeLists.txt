set(SOURCES
    "Config.cpp"
    "ConfigSerializer.cpp"
)

include(FetchContent)
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)

FetchContent_MakeAvailable(json)

set(LIB_NAME config_lib)

add_library(${LIB_NAME} STATIC ${SOURCES})
target_include_directories(${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${LIB_NAME} PRIVATE nlohmann_json::nlohmann_json)

add_executable(${PROJECT_NAME} "Main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIB_NAME})