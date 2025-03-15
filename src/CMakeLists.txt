set(SOURCES
    "Config.cpp"
    "Config.hpp"
    "ConfigSerializer.cpp"
    "ConfigSerializer.hpp"
)

include(FetchContent)
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)

FetchContent_MakeAvailable(json)


add_library(config_lib STATIC ${SOURCES})
target_include_directories(config_lib PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(config_lib PRIVATE nlohmann_json::nlohmann_json)

add_executable(${PROJECT_NAME} "Main.cpp")
target_link_libraries(${PROJECT_NAME} PRIVATE config_lib)