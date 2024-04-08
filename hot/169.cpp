#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map <int,int> mp;
        int max_c=0, idx=0;
        for(auto num:nums){
            mp[num]++;
            if(mp[num]>max_c){
                max_c = mp[num];
                idx = num;
            }
        }

        return idx;
    }


    int majorityElement2(vector<int>& nums) {
        int curr=0, count=0;
        for(auto num:nums){
            if(count==0){
                curr=num;
            }
            if(curr == num){
                count++;
            }else{
                count--;
            }
        }

        return curr;
    }
};



int main(){
    Solution entity;
    vector<int> nums={2,2,1,1,1,2,2};
    cout << "hello world" << endl;
    cout<< entity.majorityElement2(nums);

    return 0;
}