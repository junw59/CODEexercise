#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[1] < b[1];});

        int rem = 0, pre = intervals[0][1];
        for (int i = 1; i < n ; i++){
            if (intervals[i][0] < pre) rem++;
            else pre = intervals[i][1];
        }

        return rem;
    }
};

int main(){
    Solution entity;
    // [[1,2],[2,3],[3,4],[1,3]]
    vector<vector<int>> rat = {{1,2},{2,3},{3,4},{1,3}};
    cout << entity.eraseOverlapIntervals(rat);
}