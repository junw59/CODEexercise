#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxk = 2;
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(maxk + 1, vector<int>(2)));

        for (int i = 0; i < n; i++){
            for (int k = maxk; k >= 1; k--){
            // for (int k = 1; k <= maxk; k++){
                if (i == 0){
                    dp[i][k][0] = 0;
                    dp[i][k][1] = - prices[i];
                    continue;
                }

                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }

        return dp[n-1][maxk][0];
    }
};

int main(){
    Solution entity;
    vector<int> prices = {3,3,5,0,0,3,1,4};

    cout << entity.maxProfit(prices);
}