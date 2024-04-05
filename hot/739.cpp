#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 完全的暴力循环，时间是o(n^2)
        int n =temperatures.size();
        vector<int> ans(n,0);

        for (int i = 0; i < n; i++){
            int t=temperatures[i];
            for (int j = i+1; j < n; j++){
                if(temperatures[j]>t){
                    ans[i] = j-i;
                    break;
                }
            }
        }

        return ans;
    }


    vector<int> dailyTemperatures2(vector<int>& temperatures) {
        int n =temperatures.size();
        vector<int> ans(n,0);
        vector<int> next(101,INT_MAX);

        for ( int i = n-1; i >=0; i--){
            int hot_idx = INT_MAX;
            for ( int t = temperatures[i]+1; t<101;t++){
                // 寻找更大的温度出现的时间
                hot_idx = min(hot_idx, next[t]);
            }
            if(hot_idx!=INT_MAX){
                ans[i]= hot_idx - i;
            }
            next[temperatures[i]]=i;
        }

        return ans;
    }

    vector<int> dailyTemperatures3(vector<int>& temperatures) {
        // 使用栈去完成
        int n =temperatures.size();
        vector<int> ans(n,0);
        stack<int> sta;

        for ( int i = 0; i < n; i++){
            while (!sta.empty() && temperatures[i]>temperatures[sta.top()]){
                // 当前的大于栈顶，说明可以将当前对应的ans更新
                ans[sta.top()] = i-sta.top();
                sta.pop();
            }
            sta.push(i);
        }

        return ans;
    }
};


int main(){
    Solution entity;
    cout << "hello world" << endl;
    vector<int> nums={73,74,75,71,69,72,76,73};
    vector<int> results;
    results=entity.dailyTemperatures3(nums);
    for (auto i : results){
        cout << i << endl;
    }

    return 0;
}