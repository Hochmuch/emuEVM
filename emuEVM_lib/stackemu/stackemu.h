#ifndef EMUEVM_STACKEMU_H
#define EMUEVM_STACKEMU_H

#include <iostream>
#include <iomanip>

namespace stack {

    class StackOverflowError : std::exception {
    public:
        const char *what() const noexcept {
            return "Stack overflow!";
        };
    };

    class EmptyStackPopError : std::exception {
    public:
        const char *what() const noexcept {
            return "Trying to pop from empty stack!";
        };
    };

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

        Stack<T> &operator=(Stack<T> &&s) noexcept;

        ~Stack();

        void push(const T &);

        // void push(T &&);

        inline T pop();

        inline T getTop() const;

        inline int getSize() const;

        inline T *getStack() const;

        T getTopIndex() const;
    };

    template<typename T>
    Stack<T>::Stack(int stackSize) : size(stackSize) {
        stack = new T[size];
        top = 0;
    }

    template<typename T>
    Stack<T>::Stack(const Stack<T> &other) : size(other.getSize()) {
        stack = new T[size];
        top = other.getTopIndex();
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
    Stack<T> &Stack<T>::operator=(Stack<T> &&s) noexcept {
        *this = Stack(std::move(s));
        return *this;
    }

    template<typename T>
    Stack<T>::~Stack() {
        delete[] stack;
    }

    template<typename T>
    void Stack<T>::push(const T &value) {
        if (top >= size) {
            throw stack::StackOverflowError();
        }
        top++;
        stack[top] = value;
    }

    template<typename T>
    inline T Stack<T>::pop() {
        if (top <= 0) {
            throw stack::EmptyStackPopError();
        }
        top--;
        return stack[top + 1];
    }

    template<typename T>
    inline T Stack<T>::getTop() const {
        if (top <= 0) {
            throw stack::EmptyStackPopError();
        }
        return stack[top];
    }

    template<typename T>
    inline T Stack<T>::getTopIndex() const {
        return top;
    }

    template<typename T>
    inline int Stack<T>::getSize() const {
        return size;
    }

    template<typename T>
    inline T *Stack<T>::getStack() const {
        return stack;
    }

}
#endif //EMUEVM_STACKEMU_H
