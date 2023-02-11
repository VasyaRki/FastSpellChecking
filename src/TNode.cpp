#include "include/TNode.h"

void TNode::insert(const std::string& word) {
    node* ptr = root;
    for (size_t i = 0; i < word.size(); i++) 
    {
        short int index = hash_(word[i]);
        if (ptr->children[index] == NULL) 
        {
            ptr->children[index] = new node;
        }
        ptr = ptr->children[index];
    }
    ptr->is_word = true;
}

bool TNode::is_word(const std::string& word) {
    node* ptr = root;
    for (size_t i = 0; i < word.size(); i++)
    {
        short int index = hash_(word[i]);
        if (ptr->children[index] == NULL) 
        {
            return false;
        }
        ptr = ptr->children[index];
    }

    if (ptr->is_word) return true;
    return false;
}

short int hash_(const char& c) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') return tolower(c) - 'a';
    return 26;
}