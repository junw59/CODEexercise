#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word_set;
        for (auto word : wordDict){
            word_set.insert(word);
        }
        int n =s.size();
        vector<bool> dp(n+1,false);
        dp[0] = true;
        for (int i = 1; i < n+1; i++) {
            for( int j=0; j<i; j++){
                // cout << i << j << endl;
                if(dp[j] && word_set.count(s.substr(j,i-j))>0){
                    dp[i]=true;
                    break;
                }
            }
        }

        return dp[n];
    }
};




int main(){
    Solution entity;
    cout << "hello world" << endl;
    vector<int> nums={1,2,5};
    vector<string> wordDict={"leet","code"};
    cout << entity.wordBreak("leetcode",wordDict);
    // cout << INT_MAX;

    return 0;
}