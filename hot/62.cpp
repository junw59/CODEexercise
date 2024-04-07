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
    int uniquePaths(int m, int n) {
        vector <vector<int>> dp(m,vector<int>(n,1));
        for (int i = 1; i <m; i++){
            for (int j = 1; j <n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];

    }
};




int main() {
    Solution entity;
    cout << "hello world" << endl;
    cout << entity.uniquePaths(3,7);

    return 0;
}