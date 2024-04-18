#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> findOriginalArray(vector<int>& changed) {
        vector<int> ans;
        int n =changed.size();
        if(n%2!=0){
            return ans;
        }
        sort(changed.begin(),changed.end());
        unordered_map <int,int> mp;
        for(auto x:changed){
            ++mp[x];
            int half=x/2;
            if(mp[half]>0 && x%2==0){
                ans.push_back(half);
                --mp[x];
                --mp[half];
            }
            if(mp[x]==0){
                mp.erase(x);
            }
            if(mp[half]==0){
                mp.erase(half);
            }
        }

        return mp.size()>0? vector<int>(): ans;
    }
};


int main(){
    cout << "hello world!" << endl;
    // vector<int> nums={1,3,4,2,6,8};
    vector<int> nums={1,3};
    // for_each(nums.begin(),nums.end(),[](const int &a){cout << a << ",";});
    vector<int> result;
    result= Solution::findOriginalArray(nums);
    for_each(result.begin(),result.end(),[](const int &a){cout << a << ",";});


}
