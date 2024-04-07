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
    string longestPalindrome(string s) {
        int n = s.size();
        if(n<2){
            return s;
        }
        // dp[i][j]就是从i开始，到j结束的字串是不是回文，实际上需要填充的只是对角线右上的元素
        vector<vector<bool>> dp(n,vector<bool>(n,false));

        // 首先是对称轴上的元素
        for (int i =0; i<n; i++){
            dp[i][i]=true;
        }

        int max_l=1;
        int begin_i=0;
        // dp[i][j] = dp[i+1][j-1] && s[i+1][j-1]
        // 一层一层填充
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i < n; i++) {
                int j = i + l - 1;
                if (j > n - 1) {
                    break;
                }
                if(s[i]==s[j]){
                    if( l <=3){
                        dp[i][j]=true;
                    }else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }

                if(dp[i][j] && l > max_l){
                    max_l=l;
                    begin_i=i;
                }
            }
        }

        return s.substr(begin_i, max_l);
    }

    string longestPalindrome2(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }

        int max_l = 1;
        int begin_i = 0;
        for (int i = 0; i < n; i++) {
            // 两种边界条件
            for (int temp=0;temp<2; temp++){
                int j = i+temp;
                int start =i;
                // cout<< start << j <<endl;
                bool check = s[start]==s[j] ;
                while (check && j < n-1 && start>=1 && s[start-1] == s[j+1]) {
                    // cout << "yes" << start << j <<endl;
                    start--;
                    j++;
                }
                if(check && j-start+1> max_l){
                    max_l = j-start+1;
                    begin_i = start;
                }
            }
        }

        // cout << begin_i << max_l;
        return s.substr(begin_i, max_l);
    }
};



int main() {
    Solution entity;
    cout << "hello world" << endl;
    vector<vector<int>> nums={{1,3,1},{1,5,1},{4,2,1}};
    // cout << entity.longestPalindrome("babad")<< endl;
    // cout << entity.longestPalindrome2("babad")<< endl;
    // cout << entity.longestPalindrome2("cbbd")<< endl;
    cout << entity.longestPalindrome2("aaaa")<< endl;

    return 0;
}