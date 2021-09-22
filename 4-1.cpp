#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// g++ "-std=c++14" 4-1.cpp 
// 

// sample
/*
5 4
0 4
0 1
1 2
2 3
3 4
*/

// sample
/*
5 4
0 4
0 1
1 2
2 3
3 3
*/


void pretty_print_graph(vector<vector<int> > *graph) {
    for (int i = 0;i < (*graph).size(); i++) {
            cout << i << endl;
        for (int j = 0; j < (*graph)[i].size(); j++)
            cout << "    -> " << (*graph)[i][j] << endl;
    }
}


bool search(vector<vector<int> > *graph, int s, int t) {

    vector<bool> isArrived((*graph).size(),false);

    stack<int> nodes;
    nodes.push(s);

    while(!nodes.empty()) {
        int target = nodes.top();
        nodes.pop();

        for(int i : (*graph)[target] ) {
            if (!isArrived[i]) {
                nodes.push(i);
                isArrived[i] = true;
                if (i == t)
                    return true;
            }
        }
        cerr << "n : " <<target << endl;
    }
    

    return false;
}


int main(void) {
    
    vector<vector<int> > graph;
    int n,m;
    cin >> n >> m;

    int s,t;
    cin >> s >> t;

    graph.resize(n,vector<int>());

    for(int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    pretty_print_graph(&graph);

    bool ans = search(&graph,s,t);

    cout << ((ans == true)? "true" : "false");

    return 0;
}







