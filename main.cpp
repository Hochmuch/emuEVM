#include <iostream>
#include "emuEVM_lib/stackemu/stackemu.h"
#include "emuEVM_lib/emu/emu.cpp"

int main(int argc, char *argv[]) {
    std::string path = argv[1];
    emulator::Emu emu;
    emu.execute(path);
    return 0;
}
