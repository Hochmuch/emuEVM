#include "./include/parser.h"

const char *parsing::ParserError::what() const noexcept {
    return "Parser error!!!";
}

bool parsing::Parser::is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

std::pair<std::string, std::string> parsing::Parser::parse_line(const std::string &line) {
    std::pair<std::string, std::string> parsed_line = {"", ""};
    bool writing_to_opcode = true;
    for (char i : line) {
        if (isalpha(i) && writing_to_opcode) {
            parsed_line.first += i;
        } else if (i == ' ' && writing_to_opcode) {
            writing_to_opcode = false;
        } else if (isalpha(i) && !writing_to_opcode && parsed_line.first != "PUSH") {
            parsed_line.second += i;
        } else if (isdigit(i) && !writing_to_opcode && parsed_line.first == "PUSH") {
            parsed_line.second += i;
        } else {
            throw ParserError();
        }
    }
    if (parsing::opcodes.find(parsed_line.first) == parsing::opcodes.end()) {
        throw ParserError();
    }
    if ((parsed_line.first == "PUSHR" || parsed_line.first == "POPR") && parsing::registers.find(parsed_line.second) == registers.end()) {
        throw ParserError();
    }
    if (parsed_line.first == "PUSH" && !Parser::is_number(parsed_line.second)) {
        throw ParserError();
    }
    return parsed_line;
}

std::vector<std::pair<std::string, std::string>> parsing::Parser::readfile(std::string &path) {
    std::vector<std::pair<std::string, std::string>> parsed_file;
    file = std::ifstream(path);
    std::string line;
    while (std::getline(file, line)) {
        std::pair<std::string, std::string> parsed_line = parse_line(line);
        parsed_file.push_back(parsed_line);
    }
    file.close();
    return parsed_file;
}