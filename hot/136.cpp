#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for (auto i:nums){
            ans ^=i;
        }

        return ans;
    }
};


int main(){
    Solution entity;
    vector<int> nums={2,2,1};
    int target = 8;
    cout << "hello world" << endl;
    vector<int> results;
    cout<< entity.singleNumber(nums);
    for (auto i : results){
        cout << i << endl;
    }

    return 0;
}