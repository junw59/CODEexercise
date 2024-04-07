#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    int numSquares(int n) {
        vector <int> dp(n+1);
        dp[0]=0;

        for(int i =1; i < n+1; i++){
            dp[i]=i;
            for(int j = 1; i-j*j>=0; j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }

        return dp[n];
    }
};



int main(){
    Solution entity;
    cout << "hello world" << endl;
    vector<int> nums={1,2,3,1};
    cout << entity.numSquares(12);
    nums={0};
    cout << entity.numSquares(13);

    return 0;
}