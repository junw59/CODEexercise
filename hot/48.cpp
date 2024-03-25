#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for ( int i =0; i < n/2; i++){
            for ( int j =0; j < n; j++){
                swap(matrix[i][j],matrix[n-1-i][j]);
            }
        }
        for ( int i =0; i < n; i++){
            for ( int j = i+1 ; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<vector<int>> nums={{1,2,3},{4,5,6},{7,8,9}};
    entity.rotate(nums);
    for (auto i : nums){
        for (auto j : i){
            cout << j << " ";
        }
        cout << "\n";
    }
}