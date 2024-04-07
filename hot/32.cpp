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
    int longestValidParentheses(string s) {
        // 动态规划的做法
        int n = s.size();
        if (n<2){
            return 0;
        }
        int ans=0;
        vector<int> dp(n,0);
        for(int i =1; i<n; i++){
            if(s[i]==')'){
                if(s[i-1]=='('){
                    // 如果前一个是 (, 那么就找前2个之前的dp，加上最近的2个
                    dp[i] = (i>2? dp[i-2]:0)+2;
                }else if ( i> dp[i-1] && s[i-1-dp[i-1]]=='(') {
                    // 如果前一个是),然后，前一个之前的连续配对的括号之前有一个(, 那么应该将这个(之前的连续配对的，加上前一个之前的，再加上2
                    int pre_i = i-1-dp[i-1];
                    dp[i] = (pre_i >= 1? dp[pre_i-1]:0) + dp[i-1] +2 ;
                }
            }
            // cout << i << dp[i] << endl;
        }
        return *max_element(dp.begin(),dp.end());
    }

    int longestValidParentheses2(string s) {
        int n =s.size();
        if (n<2){
            return 0;
        }
        stack<int> sta;
        sta.push(-1);
        int ans =0;
        for(int i =0; i<n; i++){
            if(s[i]=='('){
                sta.push(i);
            }else {
                sta.pop();
                if(sta.empty()){
                    sta.push(i);
                }else{
                    ans = max(ans,i-sta.top());
                }
            }
        }

        return ans;
    }

};



int main() {
    Solution entity;
    cout << "hello world" << endl;
    // cout << entity.longestValidParentheses("(()");
    cout << entity.longestValidParentheses(")()())");
    cout << entity.longestValidParentheses2(")()())");

    return 0;
}