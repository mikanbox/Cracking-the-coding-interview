#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;


int main(void) {
    int input = 5;
    cin >> input;

    vector<long long> dp = vector<long long>(input + 1);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= input; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    
    cout << "answer : " << dp[input] << endl;
    return 0;
};
