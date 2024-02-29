#include <gtest/gtest.h>
#include "../emuEVM_lib/stackemu.h"

namespace {
    TEST(test1, simple_test) {
        Stack<int> a;
        a.push(10);
        EXPECT_EQ(a.getTop(), 10);
    }

    TEST(test2, clearing_stack) {
        Stack<float> s(1);
        s.push(1.999);
        s.pop();
        s.pop();
    }

    TEST(test3, deleting_test) {
        Stack<char> x = Stack<char>(2);
        x.push('3');
        x.push('a');
        x.push('(');
    }

    TEST(test4, assignment) {
        Stack<double> z(3);
        Stack<double> o(1);
        double m = 14.05;
        o.push(m);
        z = o;
        EXPECT_EQ(m, o.getTop());
    }

    TEST(test5, something) {
        Stack<int> a(8);
        for (int i = 0; i < 8; ++i) {
            a.push(i + 1);
        }
        Stack<int> b(a);
    }

    TEST(test6, HAHAHA) {
        Stack<int> a, b(3);
        Stack<int> c = b;

    }
}