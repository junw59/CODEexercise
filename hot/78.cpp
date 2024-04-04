#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 迭代法实现子集枚举
        vector <int> temp;
        vector<vector <int>> ans;
        int n = nums.size();

        for (int mask =0; mask < ( 1<<n ) ;mask ++){
            temp.clear();
            for (int i =0; i < n; i++){
                if (mask & (1<<i)){
                    temp.push_back(nums[i]);
                }
            }

            ans.push_back(temp);
        }

        return ans;
    }


    vector <int> temp;
    vector<vector <int>> ans;
    void dfs(int curr, vector<int>& nums){
        if(curr == nums.size()){
            ans.push_back(temp);
            return ;
        }

        temp.push_back(nums[curr]);
        dfs(curr+1,nums);
        temp.pop_back();
        dfs(curr+1,nums);
    }

    vector<vector<int>> subsets2(vector<int>& nums) {
        dfs(0,nums);
        return ans;
    }

};


int main(){
    Solution entity;
    vector<int> nums={1,2,3,4};
    cout << "hello world" << endl;
    vector<vector<int>> results;
    results=entity.subsets2(nums);
    for (auto i : results){
        for ( auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}