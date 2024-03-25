#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre=0,ans=nums[0];
        for (auto x :nums){
            pre = max(pre + x,x);
            ans = max(pre,ans);
        }
        return ans;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    int results;
    results=entity.maxSubArray(nums);
    cout << results << endl;

    return 0;
}