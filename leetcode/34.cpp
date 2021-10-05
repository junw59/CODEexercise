
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() < 1) return {-1, -1};
        int left = leftsearch(nums, target);
        int right = rightsearch(nums, target);

        return {left, right};
    }

    int leftsearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left)/2;
            
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] == target) right = mid - 1;
        }

        if (left >= nums.size() || nums[left] != target) return -1;
        return left;
    }

    int rightsearch(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left)/2;
            
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] == target) left = mid + 1;
        }

        if (right < 0 || nums[right] != target) return -1;
        return right;
    }
};
int main(){
    Solution entity;
    vector<int> nums={1,0,3,5,9,9,12};
    int target = 9;
    cout << "hello world" << endl;
    vector<int> res = entity.searchRange(nums, target);
    cout << res[0] << "," << res[1] << endl;
}