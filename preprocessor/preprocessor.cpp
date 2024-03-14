#include "include/preprocessor.h"
#include <stdlib.h>

const char *preprocessing::PreprocessorError::what() const noexcept {
    return "Preprocessor error!!!";
}

const char *preprocessing::ReadFromEmptyRegisterError::what() const noexcept {
    return "You are trying to read from empty register!!!";
}

void preprocessing::Preprocessor::abort_if_not_started() const {
    if (!this->is_started) {
        throw preprocessing::PreprocessorError();
    }
}

void preprocessing::Preprocessor::begin() {
    if (this->is_started) {
        throw preprocessing::PreprocessorError();
    }
    this->is_started = true;
}

void preprocessing::Preprocessor::end() {
    if (!this->is_started) {
        throw preprocessing::PreprocessorError();
    }
    this->is_started = false;
    exit(0);
}

void preprocessing::Preprocessor::push(long long value0) {
    preprocessing::Preprocessor::abort_if_not_started();
    this->stack_emulator.push(value0);
}

void preprocessing::Preprocessor::pop() {
    preprocessing::Preprocessor::abort_if_not_started();
    this->stack_emulator.pop();
}

void preprocessing::Preprocessor::pushr(const std::string& reg0) {
    preprocessing::Preprocessor::abort_if_not_started();
    if (!preprocessing::Preprocessor::is_register_used[reg0]) {
        throw preprocessing::ReadFromEmptyRegisterError();
    }
    this->stack_emulator.push(this->registers[reg0]);
}

void preprocessing::Preprocessor::popr(const std::string& reg0) {
    preprocessing::Preprocessor::abort_if_not_started();
    this->registers[reg0] = this->stack_emulator.getTop();
    this->is_register_used[reg0] = true;
    this->stack_emulator.pop();
}

void preprocessing::Preprocessor::add() {
    preprocessing::Preprocessor::abort_if_not_started();
    long long top1 = this->stack_emulator.getTop();
    this->stack_emulator.pop();
    long long top2 = this->stack_emulator.getTop();
    this->stack_emulator.push(top1);
    this->stack_emulator.push(top2 + top1);
}

void preprocessing::Preprocessor::sub() {
    preprocessing::Preprocessor::abort_if_not_started();
    long long top1 = this->stack_emulator.getTop();
    this->stack_emulator.pop();
    long long top2 = this->stack_emulator.getTop();
    this->stack_emulator.push(top1);
    this->stack_emulator.push(top2 - top1);
}

void preprocessing::Preprocessor::mul() {
    preprocessing::Preprocessor::abort_if_not_started();
    long long top1 = this->stack_emulator.getTop();
    this->stack_emulator.pop();
    long long top2 = this->stack_emulator.getTop();
    this->stack_emulator.push(top1);
    this->stack_emulator.push(top2 * top1);
}

void preprocessing::Preprocessor::div() {
    preprocessing::Preprocessor::abort_if_not_started();
    long long top1 = this->stack_emulator.getTop();
    this->stack_emulator.pop();
    long long top2 = this->stack_emulator.getTop();
    this->stack_emulator.push(top1);
    this->stack_emulator.push(top2 / top1);
}

void preprocessing::Preprocessor::out() {
    preprocessing::Preprocessor::abort_if_not_started();
    long long top = this->stack_emulator.getTop();
    this->stack_emulator.pop();
    std::cout << top << std::endl;
}

void preprocessing::Preprocessor::in() {
    preprocessing::Preprocessor::abort_if_not_started();
    long long to_add;
    std::cin >> to_add;
    this->stack_emulator.push(to_add);
}

void preprocessing::Preprocessor::calculate(std::pair<std::string, std::string> command) {
    if (command.first == "BEGIN") {
        this->begin();
    } else if (command.first == "END") {
        this->end();
    } else if (command.first == "PUSH") {
        this->push(std::stoll(command.second));
    } else if (command.first == "POP") {
        this->pop();
    } else if (command.first == "PUSHR") {
        this->pushr(command.second);
    } else if (command.first == "POPR") {
        this->popr(command.second);
    } else if (command.first == "ADD") {
        this->add();
    } else if (command.first == "SUB") {
        this->sub();
    } else if (command.first == "MUL") {
        this->mul();
    } else if (command.first == "DIV") {
        this->div();
    } else if (command.first == "OUT") {
        this->out();
    } else if (command.first == "IN") {
        this->in();
    }
}