//
// Created by Carys LeKander on 4/4/21.
//

#ifndef TRIESIMPLEMENTATION_TRIE_H
#define TRIESIMPLEMENTATION_TRIE_H
#include <iostream>

using namespace std;

const int SIZE_OF_ALPHABET = 26;

struct Node{
    char character;
    bool isWord;
    Node* children[SIZE_OF_ALPHABET]; //array of 26 nodes to account for all letters
                                     //only lowercase letters
    Node(char c) {
        character = c;
        isWord = false;
    }

    bool hasChildren () {
        for(int i = 0; i < SIZE_OF_ALPHABET; i++) {
            if(children[i] != nullptr) {
                return true;
            }
        }
        return false;
    }

};

class Trie {
private:
    Node* root = new Node('\0'); //root node that is intialized to null
public:
    /**
     * Inserts a word into the trie
     */
    void Insert(std::string word);

    /**
     * Searches if the trie contains a given word
     * returns false if word has not been inserted
     */
    bool Search(std::string word);

    /**
     * Searches if the trie contains a word that starts with passed in string
     */
    bool StartsWith(std::string start);

    /**
     * removes word from trie
     */
    void Remove(std::string word);
    Node* Remove(Node* node, std::string word, int depth);

    /**
     * returns a node
     * if word has been insert: returns the last node of the word
     * if word has not been inserted: returns a null pointer
     */
    Node* GetNode(std::string word);
};


#endif //TRIESIMPLEMENTATION_TRIE_H
