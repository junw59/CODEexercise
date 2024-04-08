#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i =n-2;
        // 寻找连续的按照小大排列一对数
        while (i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        // 如果找到了，在右边找一个略大的数
        if( i >=0){
            int j =n-1;
            while( j>i && nums[i]>=nums[j]){
                j--;
            }
            swap(nums[i],nums[j]);
        }

        reverse(nums.begin()+i+1,nums.end());
    }
};



int main(){
    Solution entity;
    vector<int> nums={1,2,3};
    cout << "hello world" << endl;
    entity.nextPermutation(nums);
    for (auto i : nums){
        cout << i << endl;
    }

    return 0;
}