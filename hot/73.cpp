#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m =matrix.size();
        int n =matrix[0].size();
        vector <int> row(m,0),col(n,0);
        for (int i =0; i < m; i++){
            for (int j =0; j < n; j++){
                if (matrix[i][j] == 0){
                    row[i]=true;
                    col[j]=true;
                }
            }
        }

        for (int i =0; i < m; i++){
            for (int j =0; j < n; j++){
                if (row[i] || col[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    // vector<vector<int>> nums={{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> nums={{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    entity.setZeroes(nums);
    for (auto i : nums){
        for (auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}