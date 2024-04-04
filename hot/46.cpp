#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    void back_track(vector<int> &output, vector<int>& nums, vector<vector<int>> &res){
        int n = nums.size();
        if(output.size() == n){
            res.push_back(output);
            return ;
        }

        for (int i = 0; i < n; i++){
            if(find(output.begin(),output.end(), nums[i])!=output.end()){
                continue;
            }

            output.push_back(nums[i]);
            back_track(output,nums,res);
            output.pop_back();
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res ;
        vector<int> output;

        back_track(output,nums,res);
        return res;
    }

};



int main(){
    Solution entity;
    vector<int> nums={1,2,3,4};
    cout << "hello world" << endl;
    vector<vector<int>> results;
    results=entity.permute(nums);
    for (auto i : results){
        for ( auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}