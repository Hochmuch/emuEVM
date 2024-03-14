#include <gtest/gtest.h>
#include "../stackemu.h"

namespace {
    TEST(test1, simple_test) {
        stack::Stack<int> a;
        a.push(10);
        EXPECT_EQ(a.getTop(), 10);
    }

    TEST(test2, clearing_stack) {
        stack::Stack<float> s(1);
        s.push(1.999);
        s.pop();
        s.pop();
    }

    TEST(test3, deleting_test) {
        stack::Stack<char> x = stack::Stack<char>(2);
        x.push('3');
        x.push('a');
        x.push('(');
    }

    TEST(test4, assignment) {
        stack::Stack<double> z(3);
        stack::Stack<double> o(1);
        double m = 14.05;
        o.push(m);
        z = o;
        EXPECT_EQ(m, o.getTop());
    }

    TEST(test5, something) {
        stack::Stack<int> a(8);
        for (int i = 0; i < 8; ++i) {
            a.push(i + 1);
        }
        stack::Stack<int> b(a);
    }

    TEST(test6, HAHAHA) {


    }
}