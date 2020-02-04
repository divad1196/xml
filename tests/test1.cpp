#include <cstdlib>
#include <iostream>
#include "../src/node.h"


int main () {
    Node html("html");
    Node test("test");
    html.append(test);
    test.setAttribute("class", "abc def");
    std::cout << html << std::endl;

    test.addAttribute("class", "ijkl");
    std::cout << html << std::endl;

    test.setAttribute("class", "ijkl");
    std::cout << html << std::endl;
    return EXIT_SUCCESS;
}