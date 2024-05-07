#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>
#include <functional>

using namespace std;



class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n1=grid.size();
        int n2=grid[0].size();

        // 表示的是从 i,j; i,k 出发的两个robot 得到的最大cherry 数
        vector<vector<vector<int>>> memo(n1,vector<vector<int>>(n2,vector<int>(n2,-1)));
        function<int(int,int,int)> dfs = [&](int i, int j, int k)->int{
            // 如果越界就返回0
            if(i==n1 || j<0 || j>=n2 || k<0 || k>=n2){
                return 0;
            }
            int &ans =memo[i][j][k];
            // 如果计算过就跳过
            if( ans != -1){
                return ans;
            }
            // 依次遍历j和k的各种可能性
            for( int j2=j-1; j2 <=j+1; ++j2){
                for( int k2=k-1; k2 <=k+1; ++k2){
                    ans = max(ans,dfs(i+1,j2,k2));
                }
            }

            ans += grid[i][j] + (k==j? 0: grid[i][k]);
            return ans;
        };
        return dfs(0,0,n2-1);
    }


    int cherryPickup_2(vector<vector<int>>& grid) {
        int n1=grid.size();
        int n2=grid[0].size();
        // 在左右和下边都添加一个数值为0的层，以减少边界条件的计算
        // dp[i][j][k]是指从 i,j 和 i,k 开始的robot最终最多能得到的cherry
        vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+2,vector<int>(n2+2,0)));
        for(int i=n1-1; i>=0; --i){
            for(int j=0; j<min(n2,i+1); ++j){
                for(int k=max(j+1,n2-1-i); k<n2; ++k){
                    // 有9种情况来决定下一步
                    dp[i][j+1][k+1] = max({
                        dp[i+1][j][k],dp[i+1][j][k+1],dp[i+1][j][k+2],
                        dp[i+1][j+1][k],dp[i+1][j+1][k+1],dp[i+1][j+1][k+2],
                        dp[i+1][j+2][k],dp[i+1][j+2][k+1],dp[i+1][j+2][k+2]
                    }) + grid[i][j] +grid[i][k] ;
                }
            }
        }
        return dp[0][1][n2];
    }


    int cherryPickup_3(vector<vector<int>>& grid) {
        int n1=grid.size();
        int n2=grid[0].size();
        // 在左右和下边都添加一个数值为0的层，以减少边界条件的计算
        // dp[i][j][k]是指从 i,j 和 i,k 开始的robot最终最多能得到的cherry
        // vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+2,vector<int>(n2+2,0)));
        // 这次使用滚动数组方法
        vector<vector<int>> curr(n2+2,vector<int>(n2+2,0));
        vector<vector<int>> prev(n2+2,vector<int>(n2+2,0));
        for(int i=n1-1; i>=0; --i){
            for(int j=0; j<min(n2,i+1); ++j){
                for(int k=max(j+1,n2-1-i); k<n2; ++k){
                    // 有9种情况来决定下一步
                    curr[j+1][k+1] = max({
                        prev[j][k],prev[j][k+1],prev[j][k+2],
                        prev[j+1][k],prev[j+1][k+1],prev[j+1][k+2],
                        prev[j+2][k],prev[j+2][k+1],prev[j+2][k+2]
                    }) + grid[i][j] +grid[i][k] ;
                }
            }
            // 交换两个 vector
            swap(curr,prev);
        }
        return prev[1][n2];
    }
};






int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<vector<int>> nums={{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout << entity.cherryPickup(nums) << endl;
    cout << entity.cherryPickup_2(nums) << endl;
    cout << entity.cherryPickup_3(nums) << endl;

    return 0;
}