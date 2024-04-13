#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;



class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &combine, int idx){
        if(idx == candidates.size()){
            return ;
        }
        if ( target == 0){
            ans.push_back(combine);
            return ;
        }

        dfs(candidates, target, ans, combine, idx+1);
        if (target-candidates[idx]>=0){
            combine.push_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }


    void dfs2(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &combine, int idx){
        if(idx == candidates.size()){
            return ;
        }
        if ( target == 0){
            ans.push_back(combine);
            return ;
        }

        if (target-candidates[idx]>=0){
            dfs2(candidates, target, ans, combine, idx+1);
            combine.push_back(candidates[idx]);
            dfs2(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combine;
        sort(candidates.begin(),candidates.end());
        dfs2(candidates, target, ans, combine, 0);
        return ans;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={2,3,5,7};
    vector<vector<int>> results;
    results=entity.combinationSum2(nums,8);
    for (auto i : results){
        for ( auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}