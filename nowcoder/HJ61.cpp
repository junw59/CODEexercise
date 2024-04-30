#include <iostream>
#include <vector>
using namespace std;

int nums_div(int app, int disk){
    vector<vector<int>> dp(app+1,vector<int>(disk+1,0));
    for(int j = 1; j <= disk; ++j) {
        dp[0][j] = 1;
        dp[1][j] = 1;
    }

    for(int i =1; i< app+1; ++i){
        for(int j=1; j<disk+1; ++j){
            dp[i][j]=dp[i][j-1]+ (i<j? 0: dp[i-j][j]);
        }
    }
    return dp[app][disk];
}


int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        // cout << a + b << endl;
        cout << nums_div(a,b) << endl;
    }
}
// 64 位输出请用 printf("%lld")