#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        if(accumulate(dist.begin(),dist.end(),0) > (long long) speed*hoursBefore){
            return -1;
        }
        int n =dist.size();
        int ans =0;
        vector<vector<int>> vt(n,vector<int>(n));
        for(int i=0; i<n ; ++i){ // 跳的次数逐渐增加，直到n-1
            for (int j=0; j<n-1; ++j){ // 最后一段路不用考虑是否要跳过
                // 前j段路，跳了i次
                // 不跳过这一段
                vt[i][j+1]=(vt[i][j] + dist[j]+speed-1)/speed *speed;
                if( i!=0){
                    // 跳过这一段 求最小值
                    vt[i][j+1] = min( vt[i][j+1] , vt[i-1][j] + dist[j]) ;
                }
            }
            // 结束之后看看是否到最小的i
            if(vt[i][n-1]+dist[n-1] <= (long long) speed*hoursBefore ){
                return i;
            }
        }

        return -1;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    // vector<int> initial = {1,3,2};
    // cout << entity.minSkips(initial,4,2);

    vector<int> initial = {1,2,3,4,5};
    cout << entity.minSkips(initial,1000,1);



}