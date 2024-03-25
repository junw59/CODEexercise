#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> L (n, 0), R(n, 0);

        L[0] = 1;
        for (int i =1; i < n; i++){
            L[i] = L[i-1]*nums[i-1];
        }
        R[n-1] = 1;
        for (int i = n-2; i >= 0; i--){
            R[i] = R[i+1]*nums[i+1];
        }
        vector<int> ans (n,0);
        for (int i =0; i < n; i++){
            ans[i] = R[i]*L[i];
        }
        return ans;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={1,2,3,4},ans;
    ans=entity.productExceptSelf(nums);
    for (auto i : ans){
        cout << i << endl;
    }

    return 0;
}