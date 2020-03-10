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
        auto x = luaL_dofile(_state, fileName);

        if(x != 0) {
            std::cout << lua_tostring(_state, -1) << std::endl;
        } else {
            std::cout << "finished" << std::endl;
        }

    }

    void LuaRunner::update() {
        auto y = lua_getglobal(_state, "update");

        if(lua_isfunction(_state, -1)) {
            auto x = lua_pcall(_state, 0, 0, 0);


            if(x != 0) {
                std::cout << lua_tostring(_state, -1) << std::endl;
            }
        }

    }

    void LuaRunner::displayStack() {
        auto i = lua_gettop(_state);
        printf("----------------  Stack Dump[%i] ----------------\n", i);
        while(i) {
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
        printf("\n ----------------  Stack Dump ----------------\n");
    }


}