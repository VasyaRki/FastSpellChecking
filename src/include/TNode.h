#ifndef TNODE_H
#define TNODE_H

#include <string>

class TNode
{
public:
    void insert(const std::string&);
    bool is_word(const std::string&);
private:
    struct node
    {
        bool is_word = false;
        struct node* children[27];
        node() {
            for (size_t i = 0; i < 27; i++)
            {
                children[i] = NULL;
            }
        }
    };
    struct node* root = new node[27];

};

short int hash_(const char&);

#endif