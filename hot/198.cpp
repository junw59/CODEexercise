#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n =nums.size();
        if (n==0){
            return 0;
        } else if(n==1) {
            return nums[0];
        }
        vector<int> money(n);
        money[0]=nums[0];
        money[1]=max(nums[0],nums[1]);

        for ( int i =2; i < n; i++){
            money[i]=max(money[i-2]+nums[i],money[i-1]);
        }

        return money[n-1];
    }


    int rob2(vector<int>& nums) {
        // 使用滚动数组
        int n =nums.size();
        if (n==0){
            return 0;
        } else if(n==1) {
            return nums[0];
        }
        int first = nums[0];
        int second = max(nums[0],nums[1]);

        for ( int i =2; i < n; i++){
            int temp = max(first+nums[i],second);
            first = second;
            second = temp;
        }

        return second;
    }
};


int main(){
    Solution entity;
    cout << "hello world" << endl;
    vector<int> nums={1,2,3,1};
    cout << entity.rob2(nums);
    nums={0};
    cout << entity.rob(nums);

    return 0;
}