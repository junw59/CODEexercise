#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int max_num = 0, sum_num = 0, target_num = 0;
        max_num = *max_element(nums.begin(),nums.end());
        sum_num = accumulate(nums.begin(),nums.end(),0);
        // for (int i = 0; i < n; i++) {
        //     sum_num += nums[i];
        //     max_num = max(max_num, nums[i]);
        // }
        target_num = sum_num / 2;
        if (sum_num % 2 == 1 || max_num > target_num) {
            return false;
        }
        // // dp_2d[i][j] 是在前i个元素中，是否能找到和为j的组合
        // vector<vector<bool>> dp_2d(n, vector<bool>(target_num+1, false));
        // dp_2d[0][nums[0]] = true;
        // for (int i = 1; i < n; i++) {
        //     dp_2d[i][0]=true;
        //     for(int j =1; j <target_num+1; j++){
        //         if(nums[i]<=j){
        //             dp_2d[i][j] = dp_2d[i-1][j] | dp_2d[i-1][j-nums[i]];
        //         }else {
        //             dp_2d[i][j] = dp_2d[i-1][j];
        //         }
        //     }
        // }
        // return dp_2d[n-1][target_num];
        // dp_2d[i][j] 是在前i个元素中，是否能找到和为j的组合，由于[i]其实只用了一层，所以可以修改为一维数组
        vector<bool> dp(target_num+1, false);
        dp[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            dp[0] = true;
            // 为了获得正确的迭代，由于等式的右边是先选择的更小的元素，因此对j的迭代应该从大开始，这样取的才是上一轮循环中得到的数值
            for(int j =target_num; j >=nums[i]; j--){
                dp[j] = dp[j] | dp[j-nums[i]];
            }
        }
        return dp[target_num];
    }
};

int main() {
    Solution entity;
    cout << "hello world" << endl;
    vector<int> nums = {1, 5, 11, 5};
    cout << entity.canPartition(nums);
    cout << entity.canPartition(nums);

    return 0;
}