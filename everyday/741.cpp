#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;




class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n1=grid.size();
        int n2=grid[0].size();
        // 初始化为INT_MIN是为了经过障碍之后的max比较必须存在
        vector<vector<vector<int>>> dp(n1+n2-1,vector<vector<int>>(n1,vector<int>(n2,INT_MIN)));
        dp[0][0][0]=grid[0][0];
        // 遍历各种可能的路径长度k，直到最长的
        for(int k=1; k<n1+n2-1; ++k){
            for(int x1=max(k-n2+1,0); x1<=min(k,n2-1); ++x1){
                int y1=k-x1;
                // 如果遇到障碍就跳过
                if(grid[x1][y1]==-1){
                    continue;
                }
                // 从x1开始就可以免去一些重复
                for(int x2=x1; x2<=min(k,n2-1); ++x2){
                    int y2=k-x2;
                    if(grid[x2][y2]==-1){
                        continue;
                    }
                    int res = dp[k-1][x1][x2]; //都往右
                    if(x1>0){
                        res=max(res,dp[k-1][x1-1][x2]);
                    }
                    if(x2>0){
                        res=max(res,dp[k-1][x1][x2-1]);
                    }
                    if(x1>0&& x2>0){
                        res=max(res,dp[k-1][x1-1][x2-1]);
                    }
                    res+=grid[x1][y1];
                    // 避免两条路径相同
                    if(x1!=x2){
                        res+=grid[x2][y2];
                    }
                    dp[k][x1][x2] = res;
                }
            }
        }

        return max(dp[n1-1+n2-1][n1-1][n2-1], 0);
    }


    int cherryPickup_ans(vector<vector<int>> &grid) {
        int n = grid.size();
        vector<vector<vector<int>>> f(n * 2 - 1, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        f[0][0][0] = grid[0][0];
        for (int k = 1; k < n * 2 - 1; ++k) {
            for (int x1 = max(k - n + 1, 0); x1 <= min(k, n - 1); ++x1) {
                int y1 = k - x1;
                if (grid[x1][y1] == -1) {
                    continue;
                }
                for (int x2 = x1; x2 <= min(k, n - 1); ++x2) {
                    int y2 = k - x2;
                    if (grid[x2][y2] == -1) {
                        continue;
                    }
                    int res = f[k - 1][x1][x2]; // 都往右
                    if (x1) {
                        res = max(res, f[k - 1][x1 - 1][x2]); // 往下，往右
                    }
                    if (x2) {
                        res = max(res, f[k - 1][x1][x2 - 1]); // 往右，往下
                    }
                    if (x1 && x2) {
                        res = max(res, f[k - 1][x1 - 1][x2 - 1]); // 都往下
                    }
                    res += grid[x1][y1];
                    if (x2 != x1) { // 避免重复摘同一个樱桃
                        res += grid[x2][y2];
                    }
                    f[k][x1][x2] = res;
                }
            }
        }
        return max(f.back().back().back(), 0);
    }






};




int main(){
    cout << "hello world" << endl;
    Solution entity;
    // vector<vector<int>> nums={{0,1,-1},{1,0,-1},{1,1,1}};
    vector<vector<int>> nums={{1,1,-1},{1,-1,1},{-1,1,1}};
    cout << entity.cherryPickup(nums) << endl;
    cout << entity.cherryPickup_ans(nums) << endl;

    return 0;
}