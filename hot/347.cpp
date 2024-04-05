#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
    // bool operator > ( const pair<int,int> &d1, const pair<int,int> &d2){
    static bool cmp (pair<int,int> &d1, pair<int,int> &d2){
        return d1.second > d2.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        // mp 里分别是元素和出现的次数
        unordered_map<int,int> mp;
        for( auto & v: nums){
            mp[v]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        // priority_queue< pair<int,int>, vector<pair<int,int>>,cmp<pair<int,int>> >
        for(auto item: mp){
            // cout << item.first << " " << item.second << endl;
            if (q.size()==k){
                if (q.top().second < item.second){
                    q.pop();
                    q.emplace(item.first,item.second);
                }
            }else{
                q.emplace(item.first,item.second);
            }
        }

        vector <int> ans;
        while(!q.empty()){
            // cout << q.top().first << endl;
            ans.emplace_back(q.top().first);
            q.pop();
        }

        return ans;
    }
};



int main() {
    Solution entity;
    // vector<int> nums = {1,1,1,2,2,3};
    vector<int> nums = {3,0,1,0};
    cout << "hello world" << endl;
    vector<int> results;
    // results= entity.topKFrequent(nums,2);
    results= entity.topKFrequent(nums,1);
    for (auto i : results){
        cout << i << endl;
    }

    return 0;
}