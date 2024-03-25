#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for (int i =0; i < n; i++){
            int sum=0;
            for (int j =i; j < n; j++){
                sum+=nums[j];

                if (sum==k){
                    count ++;
                }
            }
        }
        return count;
    }

    int subarraySum2(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int count = 0;
        int n = nums.size();
        int pre=0;
        mp[pre]++;
        for (int i =0; i < n; i++){
            pre += nums[i];
            if(mp.find(pre-k)!=mp.end()){
                count+=mp[pre-k];
            }
            mp[pre]++;
        }
        return count;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={1,1,1};
    int k =2;
    // int ans=entity.subarraySum(nums,k);
    int ans=entity.subarraySum2(nums,k);
    cout << ans << " ";
}
