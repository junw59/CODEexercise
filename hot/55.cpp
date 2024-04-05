#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int right=0;
        int n =nums.size();
        for(int i =0; i < n; i++){
            if(i<=right){
                right = max(right, i+nums[i]);
                if(right >=n-1){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Solution entity;
    vector<int> nums={2,3,1,1,4};
    cout << "hello world" << endl;
    cout << entity.canJump(nums);

    return 0;
}