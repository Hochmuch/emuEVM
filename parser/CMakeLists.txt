add_library(parser parser.cpp)
add_executable(parser_tests tests/tests_parser.cpp)
target_include_directories(parser PRIVATE include)
include_directories(include)
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)
target_link_libraries(parser_tests GTest::gtest_main)
gtest_discover_tests(parser_tests)