#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n =startTime.size();
        vector< vector<int> > jobs(n);
        for(int i =0; i<n; ++i){
            jobs[i]={startTime[i], endTime[i], profit[i]};
        }
        // 按照结束时间升序排序
        sort(jobs.begin(), jobs.end(), [](const vector<int> &job1, const vector<int> &job2){
            return job1[1] < job2[1];
        });
        vector<int> dp(n+1);
        for(int i=1; i<=n; ++i){
            // 结束时间在i-1的开始时间之前的job的数量
            int k=upper_bound(jobs.begin(), jobs.begin()+i-1, jobs[i-1][0], [&](int tar, const vector<int> &job1) {
                return tar<job1[1];
            }) - jobs.begin();
            // 前i个job对应的最大收益, 由前i-1个不包括第 i-1 job，或者是第i-1个job加上前面的k
            dp[i]=max(dp[i-1], dp[k]+jobs[i-1][2]);
        }
        return dp[n];
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> num1={1,2,3,3};
    vector<int> num2={3,4,5,6};
    vector<int> num3={50,10,40,70};
    cout << entity.jobScheduling(num1, num2, num3) << endl;

    return 0;
}