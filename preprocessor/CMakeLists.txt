add_library(preprocessor preprocessor.cpp)
add_executable(preprocessor_tests tests/tests_preprocessor.cpp)

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
target_link_libraries(preprocessor_tests GTest::gtest_main)
gtest_discover_tests(preprocessor_tests)