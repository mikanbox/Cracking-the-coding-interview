#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

/*
input format
n m
a b
a b
*/
// g++ -std=c++14 4-1.cpp 

/*
3 2
0 1
1 2
*/

struct Node {
    struct Node *next;
    int value;
};


void prettyPrint(vector<vector<int>> &graph) {

    for (int i = 0; i < graph.size(); i++) {
        cout << i << " :";
        for (auto n : graph[i]) 
            cout << n << ", ";
        cout << endl;
    }
}





int main(void) {
    vector<vector<int>> nodeAdjacencyGraph;
    int n,m;
    cin >> n >> m;

    nodeAdjacencyGraph.resize(n,vector<int>());

    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        nodeAdjacencyGraph[a].push_back(b);   
    }

    prettyPrint(nodeAdjacencyGraph);





    return 0;
}