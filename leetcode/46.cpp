#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> track;
        backtrack(nums, track, res);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track, vector<vector<int>> &res){
        if (track.size() == nums.size()){
            res.push_back(track);
            return ;
        }

        for (auto i : nums){
            // 判断是否存在
            if (find(track.begin(), track.end(), i) != track.end()){
                continue;
            }

            track.push_back(i);
            backtrack(nums, track, res);
            track.pop_back();
        }
    }
};

int main(){
    Solution entity;
    vector <int> nums={1,2,3,4};
    cout << "hello world"<< endl;
    vector <vector <int>> res;
    res=entity.permute(nums);
    for ( auto first : res){
        for ( auto second : first){
            cout << second << "\t";
        }
        cout << endl;
    }
    cout << res.size();
    return 0;
}