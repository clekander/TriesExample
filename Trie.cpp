//
// Created by Carys LeKander on 4/4/21.
//

#include "Trie.h"

void Trie::Insert(std::string word){
    Node* current = root; //sets node equal to the null root
    int wordLength = word.length();
    for(int i = 0; i < wordLength; i++) {
        char c = word.at(i);

        //checks if node has been inserted into children array
        //characters will be placed into array in alphabetical order, so can be found by
        //  subtracting c's value by a
        if(current->children[c - 'a'] == nullptr) {
            current->children[c - 'a'] = new Node(c); //inserts new character into children
        }
        current = current->children[c - 'a']; //increases position in trie
    }
    current->isWord = true; //after inserting last character, set that node as end of word
}

Node* Trie::GetNode(std::string word) {
    Node* current = root;
    int wordLength = word.length();
    for(int i = 0; i < wordLength; i++) {
        char c = word.at(i);

        //if null at character's position in children array, return null pointer
        if(current->children[c - 'a'] == nullptr) {
            return nullptr;
        }
        current = current->children[c - 'a'];
    }
    return current;
}

bool Trie::Search(std::string word) {
    Node* node = GetNode(word);
    if(node != nullptr && node->isWord) {
        return true;
    }
    return false;
}

bool Trie::StartsWith(std::string start) {
    Node* node = GetNode(start);
    if(node != nullptr) {
        return true;
    }
    return false;
}

void Trie::Remove(std::string word) {
    if(Search(word)) {
        Remove(root, word, 0);
    }
    else {
        cout << "Word not inserted" << endl;
    }
}

Node* Trie::Remove(Node* node, std::string word, int depth) {
    if(node == nullptr) {
        return nullptr;
    }

    if(depth == word.length())  {
        if(node->isWord) {
            node->isWord = false;
        }

        if(!node->hasChildren()) {
            delete(node);
            node = nullptr;
        }
        return node;
    }

    int index = word[depth] - 'a';
    node->children[index] = Remove(node->children[index], word, depth + 1);

    if(!node->hasChildren() && !node->isWord) {
        delete node;
        node = nullptr;
    }

    return node;
}

