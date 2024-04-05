#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right){
            int mid = (left + right)/2;
            cout << left << mid << right << endl;
            // if ( nums[mid]> nums[left] && nums[right]> nums[mid]){
            //     // 说明是有序的
            //     if (nums[mid]==target){
            //         return mid;
            //     }else if (nums[mid]>target){
            //         // 中间大于target，说明应该去左边找
            //         right = mid -1;
            //     }else {
            //         left = mid+1;
            //     }
            // }else 
            if ( nums[mid]> nums[left]){
                // 说明左边是有序的
                if (nums[mid]==target){
                    return mid;
                }else if (nums[left]==target){
                    return left;
                }else if (nums[left]>target || nums[mid]<target){
                    // 左边大于target，说明应该去右边找
                    left = mid+1;
                }else {
                    right = mid -1;
                }
            }else{
                // 说明右边是有序的
                if (nums[mid]==target){
                    return mid;
                }else if (nums[right]==target){
                    return right;
                }else if (nums[right]<target || nums[mid]>target){
                    // 右边小于target，说明应该去左边找
                    right = mid -1;
                }else {
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution entity;
    // vector<int> nums={4,5,6,7,0,1,2};
    // int target = 2;
    vector<int> nums={3,1};
    int target = 1;
    cout << "hello world" << endl;
    cout << entity.search(nums, target);
    return 0;
}