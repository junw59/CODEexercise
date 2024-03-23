#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int first = 0; first < n - 2; first++){
            // 相同就跳过
            if (first > 0 && nums[first] == nums[first-1]) continue;
            int third = n-1;
            int target = - nums[first];
            for (int second = first+1; second < n - 1; second++){
                if (second > first+1 && nums[second] == nums[second-1]) continue;
                while (second < third && nums[second] + nums[third] > target){
                    third--;
                }
                if (second == third) {
                    break;
                }
                if (nums[third] + nums[second] == target) {
                    ans.push_back({nums[first], nums[second],nums[third]});
                }
            }
        }
        return ans;
    }
};





int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={-1,0,1,2,-1,-4};
    // vector<int> nums={1,1};
    vector<vector<int>> ans;
    ans=entity.threeSum(nums);
    for (auto i : ans){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}