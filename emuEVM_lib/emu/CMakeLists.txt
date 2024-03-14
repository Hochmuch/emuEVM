add_library(emu  emu.cpp)
add_executable(emu_tests tests/tests_emu.cpp)
target_include_directories(emu PRIVATE include)
include_directories(include)
include(FetchContent)
target_link_libraries(emu PRIVATE preprocessor parser)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)
target_link_libraries(emu_tests GTest::gtest_main)
gtest_discover_tests(emu_tests)