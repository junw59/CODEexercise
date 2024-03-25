#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const vector<vector<int>> dire = {{0,1},{1,0},{0,-1},{-1,0}};
        int nrow = matrix.size(), ncol = matrix[0].size();
        int total = nrow*ncol;
        vector<int> ans(total,0);
        int row = 0, col =0;
        vector<vector<bool>> visited (nrow,vector<bool> (ncol));
        int dir_index=0;
        for ( int i = 0; i < total; i++){
            visited[row][col]=true;
            ans[i] = matrix[row][col];
            int next_row = row + dire[dir_index][0],next_col = col + dire[dir_index][1];
            if (next_row <0 || next_row >= nrow || next_col <0 || next_col >= ncol || visited[next_row][next_col]){
                dir_index = (dir_index + 1)%4;
            }
            row = row + dire[dir_index][0];
            col = col + dire[dir_index][1];
        }
        return ans;
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    // vector<vector<int>> nums={{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> nums={{1,2,3},{4,5,6},{7,8,9,5}};
    vector<int> ans;
    ans=entity.spiralOrder(nums);
    for (auto i : ans){
        cout << i << " ";
    }
}