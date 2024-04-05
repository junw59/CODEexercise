#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left<=right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }

        return left;
    }
};


int main(){
    Solution entity;
    vector<int> nums={1,3,5,6};
    int target = 2;
    cout << "hello world" << endl;
    // vector<int> results;
    cout << entity.searchInsert(nums, target);
    // for (auto i : results){
    //     cout << i << endl;
    // }

    return 0;
}