#include <cstdio>
#include <cstdlib>
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};


void __TraversalPreOrder(struct Node *t, vector<int> &list) {
    if (t == NULL) {
        list.push_back(-1);
        return;
    }
    list.push_back(t->value);

    __TraversalPreOrder(t->left, list);
    __TraversalPreOrder(t->right, list);
}

vector<int> TraversalPreOrder(struct Node *t) {
    vector<int> list;

    __TraversalPreOrder(t, list);

    return list;
}

bool isIdealTwoTrees(vector<int> &l, vector<int> &s) {
    for (int i = 0; i < l.size() - s.size() + 1; i++) {
        for (int j = 0; j < s.size(); j++) {
            if (l[i + j] != s[j])
                break;
            if (j == s.size() -1 )
                return true;
        }
    }
    return false;
}




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

struct Node *createTreefromInput() {
    struct Node *binaryRoot;
    int n;
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

    return binaryRoot;
}


int main(void) {

    // input
    struct Node *t1 = createTreefromInput();
    struct Node *t2 = createTreefromInput();
    

    cout << "tree 1" << endl;
    prettyTreePrint(t1);
    cout << endl;
    cout << "tree 2" << endl;
    prettyTreePrint(t2);


    vector<int> t2_ = TraversalPreOrder(t1);
    vector<int> t1_ = TraversalPreOrder(t2);
    
    bool ans = isIdealTwoTrees(t2_,t1_);
    cout << "ans : " << ans << endl;

    return 0;
}
