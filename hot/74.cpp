#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0;
        int right = n*m-1;
        // 每个i行j列都可以写成 mid = i*m + j;

        while (left<= right){
            int mid = (left + right)/2;
            int mid_num=matrix[mid/m][mid%m];
            if(mid_num == target){
                return true;
            } else if(mid_num > target){
                right= mid-1;
            } else{
                left= mid+1;
            }
        }
        return false;
    }
};

int main(){
    Solution entity;
    vector<vector<int>> nums={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 2;
    cout << "hello world" << endl;
    cout << entity.searchMatrix(nums, target);

    return 0;
}