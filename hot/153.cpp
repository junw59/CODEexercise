#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        while (left < right){
            int mid= (left+right)/2;
            if( nums[mid]< nums[right]){
                // 为什么不能用mid-1？
                right = mid;
            } else{
                left = mid+1;
            }
        }
        return nums[left];
    }
};

int main(){
    Solution entity;
    vector<int> nums={3,4,5,1,2};
    cout << "hello world" << endl;
    cout<< entity.findMin(nums);
    return 0;
}