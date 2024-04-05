#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int right=0;
        int n =nums.size();
        int end =0, step=0;
        // 只跳到了n-1
        for(int i =0; i < n-1; i++){
            if(i<=right){
                right = max(right, i+nums[i]);
                if(i==end){
                    end = right;
                    step++;
                }
            }
        }
        return step;
    }
};


int main(){
    Solution entity;
    vector<int> nums={2,3,1,1,4};
    cout << "hello world" << endl;
    cout << entity.jump(nums);

    return 0;
}