#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nr = grid.size();
        if (!nr) return 0;
        int nc = grid[0].size();
        int cnt = 0;
        queue<pair<int,int>> q;
        for ( int i =0; i <nr; i++){
            for ( int j =0; j <nc; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                } else if (grid[i][j] == 1){
                    cnt ++;
                }
            }
        }

        int ans = 0;
        vector<int> dir_x={0,1,0,-1};
        vector<int> dir_y={1,0,-1,0};

        while (!q.empty()){
            int i,j;
            int n = q.size();
            if (cnt >0){
                ans++;
            }
            while (n>0){
                tie(i,j) = q.front();
                q.pop();
                n--;
                for (int idx = 0; idx <4;idx++){
                    int new_i = i+dir_x[idx];
                    int new_j = j+dir_y[idx];
                    if (new_i >=0 && new_i< nr && new_j >=0 && new_j< nc && grid[new_i][new_j]==1){
                        grid[new_i][new_j]=2;
                        q.push({new_i,new_j});
                        cnt--;
                    }
                }
            }
        }
        return cnt >0? -1: ans ;
    }
};



int main(){
    Solution entity;
    vector<vector<int>> nums={{2,1,1},{1,1,0},{0,1,1}};
    cout << "hello world" << endl;
    int results;
    results=entity.orangesRotting(nums);
    cout << results << endl;

    return 0;
}
