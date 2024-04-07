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
    int longestCommonSubsequence(string text1, string text2) {
        int n =text1.size();
        int m =text2.size();

        // dp[i][j]表示text1的前i个[:i-1]和text2的前j个[:j-1]元素的最大公共子序列数，考虑到还有一个元素也不选择的情况，需要的维度需要+1
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < m+1; j++) {
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                // cout<< i << j << dp[i][j] <<endl;
            }
        }

        return dp[n][m];

    }
};




int main() {
    Solution entity;
    cout << "hello world" << endl;
    vector<vector<int>> nums={{1,3,1},{1,5,1},{4,2,1}};
    cout << entity.longestCommonSubsequence("abcde","ace") << endl;
    // cout << entity.longestCommonSubsequence("abc","def") << endl;

    return 0;
}