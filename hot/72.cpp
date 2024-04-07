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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n+1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j < m+1; j++) {
            dp[0][j] = j;
        }

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                int left = dp[i-1][j]+1;
                int down = dp[i][j-1]+1;
                int ld = dp[i-1][j-1];
                if (word1[i-1]!=word2[j-1]){
                    ld++;
                }
                dp[i][j]=min(ld,min(left,down));
            }
        }

        return dp[n][m];
    }
};




int main() {
    Solution entity;
    cout << "hello world" << endl;
    vector<vector<int>> nums={{1,3,1},{1,5,1},{4,2,1}};
    // cout << entity.minDistance("abcde","ace") << endl;
    // cout << entity.minDistance("horse","ros") << endl;
    cout << entity.minDistance("","a") << endl;

    return 0;
}