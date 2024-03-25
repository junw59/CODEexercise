#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n =nums.size();
        vector <int> ans;
        priority_queue <pair <int,int>> q;
        for (int i =0; i < k; i++){
            q.push({nums[i], i});
        }
        ans.emplace_back(q.top().first);
        for (int i =k; i <n; i++){
            q.push({nums[i], i});
            // 这里必须使用 while 而不能是 if
            while (q.top().second <= i-k){
                q.pop();
            }
            ans.emplace_back(q.top().first);
        }

        return ans;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    // vector<int> nums={1,3,-1,-3,5,3,6,7};
    vector<int> nums={9,10,9,-7,-4,-8,2,-6};
    int k =5;
    vector<int> ans;
    ans=entity.maxSlidingWindow(nums,k);
    for (auto i : ans){
        cout << i << endl;
    }
}

