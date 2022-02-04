#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;



struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
};


struct Node *search(struct Node *givenNode) {

    if (givenNode->right) {
        struct Node *tmpNode = givenNode->right;

        while (tmpNode->left)
            tmpNode = tmpNode->left;
        
        return tmpNode;
    } else if (givenNode->parent){
        struct Node *tmpNode = givenNode;

        do {
            if (givenNode->value <= tmpNode->parent->value)
                return tmpNode->parent;
            
            tmpNode = tmpNode->parent;
        } while (tmpNode->parent);
    }

    return NULL;
}

// 探索の形が幾何学的に対称なら、コードも対称になるか確認すること
struct Node *search(struct Node *givenNode) {

    struct Node *tmpNode;

    if (givenNode->right) {
        tmpNode = givenNode->right;

        while (tmpNode->left)
            tmpNode = tmpNode->left;
    } else if (givenNode->parent){
        tmpNode = givenNode;
        
        while (tmpNode && givenNode->value >= tmpNode->value)
            tmpNode = tmpNode->parent;
    } else {
        tmpNode = NULL;
    }

    return tmpNode;
}




int main(void) {

// input


// search

    

// print

    return 0;
}