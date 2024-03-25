#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n =nums.size();
        k = k%n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }

    void reverse(vector<int>& nums, int l, int r){
        while ( l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={1,2,3,4,5,6,7};
    entity.rotate(nums,2);
    for (auto i : nums){
        cout << i << " ";
        cout << endl;
    }

    return 0;
}