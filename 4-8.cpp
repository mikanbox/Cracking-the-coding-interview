#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;



struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};


// 探索の形が幾何学的に対称なら、コードも対称になるか確認すること
int search(struct Node *givenNode, struct Node **returnNode,struct Node *node1,struct Node *node2) {
    int ret = 0;

    if (givenNode->left)
        ret += search(givenNode->left,returnNode, node1, node2);

    if (givenNode->right)
        ret += search(givenNode->right,returnNode, node1, node2);

    if (givenNode == node1)
        ret++;
    if (givenNode == node2)
        ret++;     

    return ret;
}


struct Node *_search(struct Node *rootNode, struct Node *node1, struct Node *node2) {
    struct Node *returnNode = NULL;

    search(rootNode,&returnNode, node1, node2);

    return returnNode;
}



