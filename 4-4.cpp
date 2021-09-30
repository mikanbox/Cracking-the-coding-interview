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
a b c d e f 
*/
// g++ -std=c++14 4-1.cpp 

/*
7
1 2 3 4 5 6 7
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
    cout << endl;
}

bool isTreeBalanced(struct Node *tree, int &shallowestLevel, int &deepestLevel, int level) {
    bool res = true;
    cerr << "err : " << tree->value << endl;
    
    if (tree->left)
        res = isTreeBalanced(tree->left,shallowestLevel,deepestLevel,level + 1);
    if (tree->right)
        res = isTreeBalanced(tree->right,shallowestLevel,deepestLevel,level + 1);
    

    if (tree->left == NULL || tree->right==NULL) {
        if (level > deepestLevel) 
            deepestLevel = level;
        if (level < shallowestLevel)
            shallowestLevel = level;
        
        cerr << "err return: " <<  tree ->value <<" " << deepestLevel - shallowestLevel<< endl;
        return (deepestLevel - shallowestLevel <= 1);
    }
    
    return res;
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
        if (a == -1)
            continue;
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

    cout << endl;

    prettyTreePrint(binaryRoot);

    int shallowest = 10000000,deepest = -1000000;
    bool res = isTreeBalanced(binaryRoot,shallowest,deepest,0);

    cout << res << endl;

    return 0;
}