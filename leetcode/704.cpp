
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
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left)/2;
            
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] == target) return mid;
        }

        return -1;
    }
};

int main(){
    Solution entity;
    vector<int> nums={1,0,3,5,9,12};
    int target = 9;
    cout << "hello world" << endl;
    cout << entity.search(nums, target) << endl;
}