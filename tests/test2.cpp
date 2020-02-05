#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "../src/node.h"

// Test safety of append in case of recursivity

int main () {
    Node html("html");
    Node test("test");
    Node test2("test2");
    Node test3("test3");
    html.append(test);
    test.append(test2);
    test2.append(test3);
    try {
        test3.append(test);
    } catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }

    // std::cout << html << std::endl;

    return EXIT_SUCCESS;
}