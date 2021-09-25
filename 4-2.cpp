#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// input : node_number : 8

struct Node {
    Node *left;
    Node *right;
    int value;
};


struct Node *create_binary_tree(vector<int> &node_list, int lower, int upper) {

    int mid;
    struct Node *mid_node;

    if (lower > upper) 
        return NULL;
    
    mid = (lower + upper) / 2;
    
    mid_node = (struct Node *)malloc(sizeof(struct Node));
    mid_node->value = node_list[mid];
    mid_node->left  = create_binary_tree(node_list, lower, mid - 1);
    mid_node->right = create_binary_tree(node_list, mid + 1, upper);

    return mid_node;
}


void pretty_print(struct Node *tree) {

    queue<struct Node *> q;
    q.push(tree);
    int c = 0;

    while (!q.empty()) {
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


int main(void) {
    int n;
    cin >> n;

    vector<int> node_list(n, 0);
    for (int i = 0; i < n; i++)
        node_list[i] = i + 1;
    
    struct Node *binary_tree_root = create_binary_tree(node_list, 0, node_list.size() - 1);

    pretty_print(binary_tree_root);

    return 0;
}