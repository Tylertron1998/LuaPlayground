#include <iostream>
#include "Runtime/LuaRunner.h"
using namespace LuaTest;

int main() {
try {
    auto runner = new Runtime::LuaRunner();
    runner->fileName = "lua/main.lua";
    runner->run();
    getchar();
    return 0;
} catch(std::exception e) {
    std::cout << e.what() << std::endl;
}

}
