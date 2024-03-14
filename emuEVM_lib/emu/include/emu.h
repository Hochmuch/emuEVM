#pragma once

#include "../../../parser/parser.cpp"
#include "../../../preprocessor/preprocessor.cpp"

namespace emulator {

    class Emu {
    private:
        parsing::Parser parser;
        preprocessing::Preprocessor preprocessor;
    public:
        void execute(std::string &path);
    };

}