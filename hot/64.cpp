#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <numeric>
#include <stack>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,0));
        dp[0][0]=grid[0][0];
        for (int i =1; i < n; i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for (int j =1; j < m; j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }

        // cout << n << m << endl;
        for (int i =1; i < n; i++){
            for(int j =1; j < m; j++){
                // cout << i << j << endl;
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }

        return dp[n-1][m-1];
    }
};



int main() {
    Solution entity;
    cout << "hello world" << endl;
    vector<vector<int>> nums={{1,3,1},{1,5,1},{4,2,1}};
    cout << entity.minPathSum(nums);

    return 0;
}