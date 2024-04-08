#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pre = 0;
        int n =nums.size();
        for (int idx =pre; idx<n;idx++){
            if(nums[idx]==0){
                swap(nums[pre],nums[idx]);
                pre++;
            }
        }

        for (int idx =pre; idx<n;idx++){
            if(nums[idx]==1){
                swap(nums[pre],nums[idx]);
                pre++;
            }
        }
    }
};



int main(){
    Solution entity;
    vector<int> nums={2,0,2,1,1,0};
    cout << "hello world" << endl;
    entity.sortColors(nums);
    for (auto i : nums){
        cout << i << endl;
    }

    return 0;
}