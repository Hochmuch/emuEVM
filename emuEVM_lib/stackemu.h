#ifndef EMUEVM_STACKEMU_H
#define EMUEVM_STACKEMU_H

#include <iostream>
#include <iomanip>

template<typename T>
class Stack {
private:
    T *stack;
    int size;
    int top;
public:
    Stack(int = 30);

    Stack(const Stack<T> &);

    Stack<T> &operator=(const Stack<T> &s);

    Stack<T> &operator=(const Stack<T> &&s) noexcept;

    ~Stack();

    inline void push(const T &);

    inline T pop();

    inline T getTop() const;

    inline int getSize() const;

    inline T *getStack() const;
};

template<typename T>
Stack<T>::Stack(int stackSize) : size(stackSize) {
    stack = new T[size];
    top = 0;
}

template<typename T>
Stack<T>::Stack(const Stack<T> &other) : size(other.getSize()) {
    stack = new T[size];
    top = other.getTop();
    for (int i = 0; i < top; i++) {
        stack[i] = other.getStack()[i];
    }
}

template<class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &s) {
    if (&s != this) {
        delete[] stack;
        size = s.size;
        top = s.top;
        stack = new T[size];
        for (int i = 0; i < size; i++)
            stack[i] = s.stack[i];
    }
    return *this;
}

template<typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &&s) noexcept {
    *this = Stack(std::move(s));
    return *this;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] stack;
}

template<typename T>
inline void Stack<T>::push(const T &value) {
    if (top >= size) {
        throw ("No free space!");
    }
    top++;
    stack[top] = value;
}

template<typename T>
inline T Stack<T>::pop() {
    if (top <= 0) {
        throw ("Stack is already empty!");
    }
    top--;
    return stack[top + 1];
}

template<typename T>
inline T Stack<T>::getTop() const {
    return stack[top];
}

template<typename T>
inline int Stack<T>::getSize() const {
    return size;
}

template<typename T>
inline T *Stack<T>::getStack() const {
    return stack;
}

#endif //EMUEVM_STACKEMU_H
