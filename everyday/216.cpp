#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <stdio.h>
#include <vector>
#include <string>
#include <typeinfo>
#include <numeric>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &combination, int cur, int k, int n) {
        if (cur > 10 || combination.size() > k) {
            return;
        }
        int temp_sum=accumulate(combination.begin(), combination.end(), 0);
        if (combination.size() == k && temp_sum == n) {
            ans.push_back(combination);
            return ;
        }
        if(temp_sum >n){return;}

        // 选择当前的数
        combination.push_back(cur);
        dfs(ans, combination, cur + 1, k, n);
        // 撤销刚才选择的数
        combination.pop_back();
        dfs(ans, combination, cur + 1, k, n);

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        // 选择k个数，和为n
        vector<vector<int>> ans;
        vector<int> combination;
        dfs(ans, combination, 1, k, n);

        return ans;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<vector<int>> ans;
    // ans=entity.combinationSum3(3,7);
    ans=entity.combinationSum3(9,45);
    for(auto i:ans){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
}