cmake_minimum_required(VERSION 3.25)
project(emuEVM)

set(CMAKE_CXX_STANDARD 20)

add_executable(emuEVM main.cpp parser/tests/tests_parser.cpp preprocessor/tests/tests_preprocessor.cpp)

add_subdirectory(emuEVM_lib/stackemu)
add_subdirectory(emuEVM_lib/emu)
add_subdirectory(parser)
add_subdirectory(preprocessor)

target_link_libraries(emuEVM PRIVATE preprocessor parser stackemu emu)