#include "include/emu.h"

void emulator::Emu::execute(std::string &path) {
    std::vector<std::pair<std::string, std::string>> commands = parser.readfile(path);
    for (auto &command : commands) {
        emulator::Emu::preprocessor.calculate(command);
    }
}

