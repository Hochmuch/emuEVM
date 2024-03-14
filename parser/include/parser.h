#pragma once

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <vector>

namespace parsing {

    enum class OperandType {
        // Registers
        AX, BX, CX, DX, SP, BP, SI, DI, PC,
        // Numbers and others
        NN, STRING, LABEL
    };

    enum class Opcode {
        BEGIN, END, PUSH, POP, PUSHR, POPR, ADD, SUB, MUL, DIV, OUT, IN
    };

    const std::unordered_map<std::string, Opcode> opcodes =
            {
                    {"PUSH",  Opcode::PUSH},
                    {"POP",   Opcode::POP},
                    {"PUSHR", Opcode::PUSHR},
                    {"POPR",  Opcode::POPR},
                    {"ADD",   Opcode::ADD},
                    {"SUB",   Opcode::SUB},
                    {"MUL",   Opcode::MUL},
                    {"DIV",   Opcode::DIV},
                    {"OUT",   Opcode::OUT},
                    {"IN",    Opcode::IN},
                    {"BEGIN", Opcode::BEGIN},
                    {"END",   Opcode::END}
            };

    const std::unordered_map<std::string, OperandType> registers =
            {
                    {"AX", OperandType::AX},
                    {"BX", OperandType::BX},
                    {"CX", OperandType::CX},
                    {"DX", OperandType::DX},
                    {"AX", OperandType::AX},
                    {"BX", OperandType::BX},
                    {"CX", OperandType::CX},
                    {"DX", OperandType::DX},
            };


    class Parser {
    private:
        std::ifstream file;
    public:
        std::vector<std::pair<std::string, std::string>> readfile(std::string &path);

        std::pair<std::string, std::string> parse_line(const std::string &line);

        bool is_number(const std::string &s);
    };

    class ParserError : std::exception {
    public:
        const char *what() const noexcept;
    };
}