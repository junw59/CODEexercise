#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n =nums.size();
        for (int i = 0; i < n; i++){
            if (nums[i] <=0){
                nums[i] = n+1;
            }
        }
        for (int i = 0; i < n; i++){
            int num =abs(nums[i]);
            if (num<=n){
                nums[num-1] = -abs(nums[num-1]);
            }
        }
        for (int i = 0; i < n; i++){
            if (nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }

    int firstMissingPositive2(vector<int>& nums) {
        int n = nums.size();
        for ( int i =0; i <n; i++){
            // 由于换过去的数字可能也<n，所以需要继续换
            while (nums[i] >0 && nums[i]<=n && nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for ( int i =0; i <n; i++){
            if (nums[i]!=i+1){
                return i+1;
            }
        }
        return n+1;

    }

};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={3,4,-1,1};
    int ans=entity.firstMissingPositive2(nums);
    cout << ans << endl;

    return 0;
}