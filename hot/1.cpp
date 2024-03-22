#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); i ++){
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()){
                return {it-> second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};


int main(){
    Solution entity;
    vector<int> nums={1,0,3,5,9,12};
    int target = 8;
    cout << "hello world" << endl;
    vector<int> results;
    results=entity.twoSum(nums, target);
    for (auto i : results){
        cout << i << endl;
    }

    return 0;
}