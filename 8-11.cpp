#include <iostream>
#include <vector>
#include <stack>
using namespace std;



// int solve () {


//     return 0;
// }

// int _solve() {
    
// }

void pretty_print(vector<vector<int>> &DP) {
    cout << endl;
    for (int i = 0; i < DP.size(); i++) {
        for (int j = 0; j < DP[i].size(); j++) {
            cout << DP[i][j] << ",";
        }
        cout << endl;
    }
}

int main (void) {
    int n;
    cin >> n;
    vector<int> coins{0, 1, 2, 7, 8, 12};
    vector<vector<int>> DP = vector<vector<int>>(coins.size(), vector<int>(n + 1,0));
    DP[0][0] = 1;

    for (int i = 0; i < coins.size(); i++) {
        for (int j = 0; j <= n; j++) {

            for (int k = coins.size() - 1; k >= i; k--) {
                if (j + coins[k] > n)
                    continue;
                
                DP[k][j + coins[k]] += DP[i][j];
            }
        }
    }
    pretty_print(DP);
    
    int res = 0;
    for (int i = 0; i < coins.size(); i++) 
        res += DP[i][n];
    
    cout << res << endl;

    

}


                // for (int l = 1; l < n; l++) {
                //     if (j + coins[k - 1] * l > n)
                //         continue;
                //     DP[k][j + coins[k - 1] * l ] += DP[i][j];
                // }
