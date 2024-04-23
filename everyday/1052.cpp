#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <stdio.h>
#include <vector>
#include <string>
#include <typeinfo>
#include <numeric>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n =customers.size();
        if (minutes>=n){
            return accumulate(customers.begin(),customers.end(),0);
        }
        int ans=0;
        for(int i =0; i <n; ++i){
            if(grumpy[i]==0){
                ans+=customers[i];
            }
        }
        int left=0, right=minutes-1;
        int max_add=0;
        for(int i =left; i <= right; ++i){
            if(grumpy[i]==1){
                max_add+=customers[i];
            }
        }
        int curr_add =max_add;
        while ( right <n-1){
            if(grumpy[left]==1){
                curr_add+= - customers[left];
            }
            ++left;
            ++right;
            if(grumpy[right]==1){
                curr_add+= customers[right];
            }
            max_add = max(max_add,curr_add);
        }

        return ans+max_add;
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> nums={1,0,1,2,1,1,7,5};
    vector<int> nums2={0,1,0,1,0,1,0,1};
    cout << entity.maxSatisfied(nums,nums2,3);
}
