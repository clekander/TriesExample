#include <iostream>
#include "Trie.h"

int main() {
    Trie trie;

    trie.Insert("hello");
    trie.Insert("he");
    trie.Insert("hi");
    trie.Insert("high");
    trie.Insert("a");
    trie.Insert("apple");
    trie.Insert("I");

    std::cout << trie.Search("hello") << std::endl;
    std::cout << trie.Search("he") << std::endl;
    std::cout << trie.StartsWith("hell") << std::endl;
    trie.Remove("goodbye");
    trie.Remove("hello");
    std::cout << trie.Search("hello") << std::endl;
    std::cout << trie.Search("he") << std::endl;

    std::cout << trie.StartsWith("hell") << std::endl;

    return 0;
}
