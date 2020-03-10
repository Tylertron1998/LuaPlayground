//
// Created by Tyler Davis on 03/03/2020.
//
#include <iostream>
#include "stdio.h"
#include "LuaRunner.h"
#include <functional>
extern "C" {
#include <lua.hpp>
}

namespace LuaTest::Runtime {

    void LuaRunner::run() {
        _state = luaL_newstate();
        luaL_openlibs(_state);
        printf("Running %s\n", fileName);
        auto x = luaL_loadfile(_state, fileName);

        lua_call(_state, 0, 0);

        if(x != 0) {
            std::cout << lua_tostring(_state, -1) << std::endl;
        } else {
            std::cout << "finished" << std::endl;
        }

    }


    void LuaRunner::registerMethod() {
        lua_register(_state, "", nullptr);
    }

    template<>
    std::string LuaRunner::luaGet(std::string object, std::string identifier) {
        return "foobar";
    }

    template<>
    int LuaRunner::luaGet(std::string object, std::string identifier) {
        return (int)lua_tonumber(_state, 1);
    }

    void LuaRunner::displayStack() {
        auto i = lua_gettop(_state);
        printf("----------------  Stack Dump ----------------" );
        while(  i   ) {
            int t = lua_type(_state, i);
            switch (t) {
                case LUA_TSTRING:
                    printf("%d:`%s'", i, lua_tostring(_state, i));
                    break;
                case LUA_TBOOLEAN:
                    printf("%d: %s",i,lua_toboolean(_state, i) ? "true" : "false");
                    break;
                case LUA_TNUMBER:
                    printf("%d: %g",  i, lua_tonumber(_state, i));
                    break;
                default: printf("%d: %s", i, lua_typename(_state, t)); break;
            }
            i--;
        }
        printf(" ----------------  Stack Dump ----------------");
    }
}