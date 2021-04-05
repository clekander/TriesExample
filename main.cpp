#include <iostream>
#include "Trie.h"

int main() {
    Trie t;

    t.Insert("hello");
    t.Insert("he");
    t.Insert("hi");
    t.Insert("app");
    t.Insert("i");

    std::cout << t.Search("hi") << std::endl;
    std::cout << t.Search("h") << std::endl;
    std::cout << t.StartsWith("h") << std::endl;
    std::cout << t.Search("her") << std::endl;
    
    t.Delete("goodbye");
    t.Delete("hello");
    t.Delete("app");
    t.Delete("he");

    std::cout << t.Search("hello") << std::endl;
    std::cout << t.Search("he") << std::endl;


    return 0;
}
