#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int right=0;
        for (int i =0; i < nums.size(); i++){
            if (nums[i]){
                swap(nums[i],nums[right]);
                right+=1;
            }
        }
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={0,1,0,3,12};
    entity.moveZeroes(nums);
    for (auto i: nums) cout << i << " ";
}