#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    void dfs(vector<int>& candidates, int target,vector<vector<int>> &ans, vector<int> &combined,int idx){
        if(target==0){
            ans.push_back(combined);
            return ;
        }
        if(idx==candidates.size()){
            return;
        }
        if (target>= candidates[idx]){
            // 直接跳过这个数，然后dfs
            dfs(candidates,target,ans,combined,idx+1);
            // 选择这个数，然后dfs
            combined.push_back(candidates[idx]);
            dfs(candidates,target-candidates[idx],ans,combined,idx);
            combined.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combined;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,ans,combined,0);
        return ans;
    }

};




int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> initial = {2,3,6,7};
    vector<vector<int>> ans;
    ans=entity.combinationSum(initial,7);
    for(auto i:ans){
        for(auto j:i){
            cout << j << " ";
        }
        cout << endl;
    }
}