#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

/*
input format
n 
a b c d e f ..
*/
// g++ -std=c++14 4-1.cpp 

/*
1
2 | 3
4 5 | 6 7
8 9 10 11 | 12 13 | 14 15
*/


struct Node {
    struct Node *left;
    struct Node *right;
    int value;
};



void prettyTreePrint(struct Node *tree) {
    queue<struct Node *> q;
    q.push(tree);
    int c = 0;
    while(!q.empty()) {
        struct Node *n = q.front();
        q.pop();

        if (n) {
            cout << n->value << ", ";

            q.push(n->left);
            q.push(n->right);
        } else {
            cout << "*, ";
        }
        
        c++;
        if (!(c & (c + 1)))
            cout << endl;

    }
}

void createLinkedListsfromTree(vector<list<int>>  &nodes, struct Node *tree, int depth){
    if (tree == NULL)
        return;
    if (depth == nodes.size())
        nodes.push_back( list<int>());

    // 行きがけ順
    nodes[depth].push_back(tree->value);
    createLinkedListsfromTree(nodes,tree->left,depth + 1);
    createLinkedListsfromTree(nodes,tree->right,depth + 1);
    
}


int main(void) {
    int n;
    struct Node *binaryRoot;

    cin >> n;
    binaryRoot = (struct Node*)malloc(sizeof(struct Node));

    for (int i = 1; i <= n; i++) {
        int a;
        int j;
        struct Node **target = &binaryRoot;

        cin >> a;
        for (j = 1; j <= i / 2; j = j << 1);
    
        for (; j >= 2; j = j >> 1) {
            if ((i % j) / (j >> 1)){
                target = &((*target)->right);
            } else {
                target = &((*target)->left);
            }
        }

        *target = (struct Node*)malloc(sizeof(struct Node));
        (**target).left  = NULL;
        (**target).right = NULL;
        (**target).value = a;
    }

    prettyTreePrint(binaryRoot);


    vector<list<int>> nodes;
    createLinkedListsfromTree(nodes,binaryRoot,0);

    cout << endl;
    for(auto nodelist : nodes) {
        for (auto nd : nodelist)
            cout << nd << ", ";
        cout << endl;
    }



    return 0;
}