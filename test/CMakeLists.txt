set(TEST_SOURCES
    "ConfigTest.cpp"
)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(ConfigSystemTest ${TEST_SOURCES})
target_link_libraries(ConfigSystemTest PRIVATE config_lib GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ConfigSystemTest)