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
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        double ans = 1e9;
        int n = quality.size();
        vector<int> weight(n);
        // 填充数组从0开始++
        iota(weight.begin(), weight.end(), 0);
        // 把下标按照权重排序，权重小的放前面，这意味着其最后相乘的系数比较小
        sort(weight.begin(), weight.end(), [&](int const &a, int const &b) {
            return wage[a] * quality[b] < wage[b] * quality[a];
        });

        double tot_q = 0;
        // 用大根堆把最大的q放最前面
        priority_queue<int, vector<int>, less<int>> q;
        // 先把前k-1个小的权重的q加起来
        for (int i = 0; i < k - 1; ++i) {
            tot_q += quality[weight[i]];
            q.push(quality[weight[i]]);
        }
        // 每次增加一个最大的权重，同时把之前的最大的q去掉
        for (int i = k - 1; i < n; ++i) {
            // 最大的权重的下标
            int idx = weight[i];
            // 添加当前的下标
            tot_q += quality[idx];
            q.push(quality[idx]);
            double tot_w = (double) wage[idx] / quality[idx] * tot_q;
            // cout << tot_q << " " << ((double) wage[idx]) / quality[idx] <<" "<< tot_w << endl;
            ans = min(ans, tot_w);
            // 去掉最大值
            tot_q -= q.top();
            q.pop();
        }

        return ans;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<int> qualify={10,20,5};
    vector<int> wages={70,50,30};
    cout << entity.mincostToHireWorkers(qualify, wages, 2) << endl;

    return 0;
}