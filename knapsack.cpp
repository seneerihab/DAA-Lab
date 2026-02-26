#include <iostream>
#include <vector>
using namespace std;

int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1));

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(wt[i-1] <= w)
                dp[i][w] = maxVal(val[i-1] + dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int val[] = {70, 80, 140};
    int wt[] = {5, 10, 20};
    int W = 25;
    int n = 3;

    cout << "Maximum Profit: " << knapsack(W, wt, val, n);
    return 0;
}