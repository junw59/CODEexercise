#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (const auto& row: matrix){
            auto it = lower_bound(row.begin(),row.end(),target);
            if (it != row.end() && *it == target){
                return true;
            }
        }
        return false;
    }


    bool searchMatrix2(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = m-1;
        while (x<n && y >=0){
            if (matrix[x][y]==target){
                return true;
            }
            if (matrix[x][y]>target){
                y--;
            }
            else{
                x++;
            }
        }
        return false;
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<vector<int>> nums={{1,2,3},{4,5,6},{7,8,9}};
    cout << entity.searchMatrix2(nums,5);
}