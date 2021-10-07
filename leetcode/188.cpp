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
    int maxProfit(int mk, vector<int>& prices) {
        int n = prices.size();
        if (n < 1) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(mk + 1, vector<int>(2)));

        for (int i = 0; i < n; i++){
            for (int k = mk; k >= 1; k--){
                if (i == 0){
                    dp[i][k][0] = 0;
                    dp[i][k][1] = - prices[i];
                    continue;
                }

                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }

        return dp[n-1][mk][0];
    }
};

int main(){
    Solution entity;
    vector<int> prices = {2,4,1};
    int mk = 2;

    cout << entity.maxProfit(mk, prices);
}