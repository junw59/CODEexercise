#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>

using namespace std;


class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue < pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;
        int n =costs.size();

        // 设置寻找的数组的从左右边开始的指标
        int left = candidates-1, right = n-candidates;
        if(left < right){
            for (int i=0; i <= left; ++i){
                // que.push(make_pair())
                que.emplace(costs[i],i);
            }
            for (int i=right; i <n; ++i){
                que.emplace(costs[i],i);
            }
        }else {
            for (int i=0; i <n; ++i){
                que.emplace(costs[i],i);
            }
        }

        // 寻找最小的，加入目标
        long long sum=0;
        for(int i=0; i<k; ++i){
            auto pai=que.top();
            que.pop();
            sum+=pai.first;
            // cout << pai.second << " " << pai.first << endl;

            if(pai.second <= left && left < right -1 ){
                ++left;
                que.emplace(costs[left],left);
            }else if (pai.second >= right && left < right-1 ){
                --right;
                que.emplace(costs[right],right);
            }
        }

        return sum;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    // vector<int> nums={17,12,10,2,7,2,11,20,8};
    // vector<int> nums={31,25,72,79,74,65,84,91,18,59,27,9,81,33,17,58};
    vector<int> nums={28,35,21,13,21,72,35,52,74,92,25,65,77,1,73,32,43,68,8,100,84,80,14,88,42,53,98,69,64,40,60,23,99,83,5,21,76,34};
    // cout << entity.totalCost(nums,3,4) << endl;
    // cout << entity.totalCost(nums,11,2) << endl;
    cout << entity.totalCost(nums,32,12) << endl;

    return 0;
}