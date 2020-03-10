#include <iostream>
#include "Runtime/LuaRunner.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>
using namespace LuaTest;

int main() {
try {
    auto runner = new Runtime::LuaRunner();
    runner->fileName = "lua/main.lua";
    runner->run();
    runner->displayStack();
    runner->update();
    auto x = 100;

    while(x > 0) {
        _sleep(100);
        runner->update();
        x--;
    }
    return 0;
} catch(std::exception e) {
    std::cout << e.what() << std::endl;
}

}
