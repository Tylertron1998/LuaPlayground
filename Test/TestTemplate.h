//
// Created by Tyler Davis on 03/03/2020.
//

#ifndef LUATEST_TESTTEMPLATE_H
#define LUATEST_TESTTEMPLATE_H

namespace LuaTest::Test {
    class TestTemplate {
    public:
        template<typename T, typename... TRest>
        void test(T first, TRest... args) {
            std::cout << first << std::endl;
            x--;
            test(args...);
        }
        template<typename T>
        void test(T arg) {
            std::cout << arg << std::endl;
            x--;
        }
        int x;
    };
}

#endif //LUATEST_TESTTEMPLATE_H
