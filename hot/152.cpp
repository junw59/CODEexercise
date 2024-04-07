#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp_max(nums);
        vector<int> dp_min(nums);

        for(int i = 1; i < n; i++){
            dp_max[i] = max(max(dp_min[i-1]*nums[i],nums[i]),dp_max[i-1]*nums[i]);
            dp_min[i] = min(min(dp_max[i-1]*nums[i],nums[i]),dp_min[i-1]*nums[i]);
        }

        return *max_element(dp_max.begin(),dp_max.end());
    }


    int maxProduct2(vector<int>& nums) {
        // 使用滚动数组节省空间
        int n = nums.size();
        int dp_max=nums[0];
        int dp_min=nums[0];
        int ans=nums[0];

        for(int i = 1; i < n; i++){
            int temp_max=dp_max,temp_min=dp_min;
            dp_max = max(max(temp_min*nums[i],nums[i]),temp_max*nums[i]);
            dp_min = min(min(temp_max*nums[i],nums[i]),temp_min*nums[i]);
            ans = max(ans,dp_max);
        }

        return ans;
    }
};


int main() {
    Solution entity;
    cout << "hello world" << endl;
    vector<int> nums = {2,3,-2,4};
    cout << entity.maxProduct(nums);
    cout << entity.maxProduct2(nums);

    return 0;
}