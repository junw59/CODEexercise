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
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (auto x : nums) {
                if (x <= i && dp[i - x] + dp[i] < INT_MAX) {
                    dp[i] += dp[i - x];
                }
            }
        }

        return dp[target];
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={1,2,3};
    cout << entity.combinationSum4(nums,4);
}