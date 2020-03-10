//
// Created by Tyler Davis on 03/03/2020.
//

#ifndef LUATEST_LUARUNNER_H
#define LUATEST_LUARUNNER_H


#include <string>
#include "LuaRunner.h"

extern "C" {
#include <lua.hpp>
}

namespace LuaTest::Runtime {
    class LuaRunner {
    public:
        const char *fileName;
        void run();
        void registerMethod();
        template<typename T>
        T luaGet(std::string object, std::string identifier);
        void displayStack();
    private:
        lua_State* _state;
    };
}



#endif //LUATEST_LUARUNNER_H
