#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==0) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for (auto iv : intervals){
            int L = iv[0], R = iv[1];
            if (ans.size()==0 || ans.back()[1]<L){
                ans.push_back({L,R});
            }
            else{
                ans.back()[1] = max(ans.back()[1],R);
            }
        }
        return ans;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<vector<int>> nums={{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> results;
    results=entity.merge(nums);
    for (auto i : results){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}