#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for ( int i =0; i < numRows; i++){
            ans[i].resize(i+1);
            ans[i][0]=1;
            ans[i][i]=1;
            for ( int j =1; j < i; j++){
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
            }
        }
        return ans;
    }
};

int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<vector<int>> results;
    results=entity.generate(5);
    for (auto i : results){
        for (auto j :i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}