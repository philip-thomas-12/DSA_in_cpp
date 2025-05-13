#include <iostream>
#include <vector>
using namespace std;

// Filename: knapsack_01.cpp
// Description: 0/1 Knapsack problem using dynamic programming.

int main() {
    int n, W;
    cin >> n >> W;
    vector<int> weight(n), value(n);
    for(int i = 0; i < n; i++) {
        cin >> weight[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> value[i];
    }
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {
            if(weight[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weight[i-1]] + value[i-1]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    cout << dp[n][W] << endl;
    return 0;
}
