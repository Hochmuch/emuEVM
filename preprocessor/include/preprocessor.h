#pragma once

#include <stdexcept>
#include "../../parser/include/parser.h"
#include "../../emuEVM_lib/stackemu/stackemu.h"

namespace preprocessing {

    class PreprocessorError : std::exception {
    public:
        const char *what() const noexcept;
    };

    class ReadFromEmptyRegisterError : std::exception {
    public:
        const char *what() const noexcept;
    };

    class Preprocessor {
    private:
        stack::Stack<long long> stack_emulator = stack::Stack<long long>(10000);
        std::unordered_map<std::string, long long> registers = {
                {"AX", 0},
                {"BX", 0},
                {"CX", 0},
                {"DX", 0},
                {"SP", 0},
                {"BP", 0},
                {"SI", 0},
                {"DI", 0},
                {"PC", 0}
        };
        std::unordered_map<std::string, bool> is_register_used = {
                {"AX", false},
                {"BX", false},
                {"CX", false},
                {"DX", false},
                {"SP", false},
                {"BP", false},
                {"SI", false},
                {"DI", false},
                {"PC", false}
        };
        bool is_started = false;
    public:
        void begin();

        void end();

        void push(long long value0);

        void pop();

        void pushr(const std::string& reg0);

        void popr(const std::string& reg0);

        void add();

        void sub();

        void mul();

        void div();

        void out();

        void in();

        void calculate(std::pair<std::string, std::string> command);

        void abort_if_not_started() const;
    };
}
