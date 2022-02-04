#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>
#include <queue>


using namespace std;


struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};


struct MultiChildNode {
    int value;
    struct Node* originNode;
    MultiChildNode *parent;
    list<MultiChildNode*> children; 
} typedef MultiChildNode;
// 多分木に関するクラス
// n分木は 2 分木で再現できる

 
void __createAnswerTree(list<Node*>lefts,list<Node*>rights, MultiChildNode *anstreeNode, struct Node *origin) {
    if (origin->left)
        lefts.push_back(origin->left);
    if (origin->right)
        rights.push_back(origin->right);
    cerr << ":::  " << origin->value << "   lefts = " <<lefts.size() << "   rights = " << rights.size() << endl;
    

    for(list<Node*>::iterator it = begin(lefts); it != end(lefts); ++it){
        Node* node = *it;

        cerr << node->value << endl;

        MultiChildNode *mnode = new MultiChildNode();
        anstreeNode->children.push_back(mnode);
        mnode->parent = anstreeNode;
        mnode->originNode = node;
        mnode->value = node->value;

        auto it2 = it;
        it2++;
        lefts.erase(it);
        __createAnswerTree(lefts,rights,mnode,node);
        lefts.insert(it2,node);
    }


    for(list<Node*>::iterator it = begin(rights); it != end(rights); ++it){
        Node* node = *it;

        cerr << node->value << endl;

        MultiChildNode *mnode = new MultiChildNode();
        anstreeNode->children.push_back(mnode);
        mnode->parent = anstreeNode;
        mnode->originNode = node;
        mnode->value = node->value;

        auto it2 = it;
        it2++;
        rights.erase(it);
        __createAnswerTree(lefts,rights,mnode,node);
        rights.insert(it2,node);
    }


    cerr << "Node " << origin->value << " is searched" << endl;
}


MultiChildNode *createAnswerTree(struct Node *origin) {
    MultiChildNode *answerTree = new MultiChildNode();
    list<Node*>lefts;
    list<Node*>rights;

    answerTree->value = origin->value;
    answerTree->parent = NULL;
    answerTree->originNode = origin;

    __createAnswerTree(lefts,rights,answerTree,origin);

    return answerTree;
}


void bottomUpToRoot(MultiChildNode *leaf) {

    while(leaf != NULL) {
        cout << leaf->value << " - ";
        leaf = leaf->parent;
    }
    cout << endl;
}



void searchToLeaf(MultiChildNode *answertTree) {
    if (answertTree->children.size() == 0) {
        bottomUpToRoot(answertTree);
        return;
    }

    for(auto item : answertTree->children)
        searchToLeaf(item);
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



int main(void) {

    // input
    struct Node *input;
    input = (struct Node*)malloc(sizeof(struct Node));
    input->value = 5;
    input->left = (struct Node*)malloc(sizeof(struct Node));
    input->left->value = 2;
    input->left->left = NULL;
    input->left->right = NULL;

    input->right = (struct Node*)malloc(sizeof(struct Node));
    input->right->value = 8;
    input->right->left = NULL;
    input->right->right = NULL;

    // 5 - 2
    //   - 8


    prettyTreePrint(input);

    // answer 用の tree 作成
    MultiChildNode *ans = createAnswerTree(input); 


    searchToLeaf(ans);




    // answer 用の treeを辿って回答出力

    return 0;
}

