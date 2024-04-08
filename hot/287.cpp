#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        fast=0;
        do {
            slow = nums[slow];
            fast = nums[fast];
        } while (slow != fast);

        return slow;
    }
};



int main(){
    Solution entity;
    vector<int> nums={1,3,4,2,2};
    cout << "hello world" << endl;
    cout << entity.findDuplicate(nums);

    return 0;
}