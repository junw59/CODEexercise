#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            cout<< dp[i] << endl;
        }

        return *max_element(dp.begin(),dp.end());
    }
};



int main() {
    Solution entity;
    cout << "hello world" << endl;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << entity.lengthOfLIS(nums);

    return 0;
}