/*
Levenshtein 距离，又称编辑距离，指的是两个字符串之间，由一个转换成另一个所需的最少编辑操作次数。许可的编辑操作包括将一个字符替换成另一个字符，插入一个字符，删除一个字符。编辑距离的算法是首先由俄国科学家 Levenshtein 提出的，故又叫 Levenshtein Distance 。

例如：

字符串A: abcdefg

字符串B: abcdef

通过增加或是删掉字符 ”g” 的方式达到目的。这两种方案都需要一次操作。把这个操作所需要的次数定义为两个字符串的距离。

要求：

给定任意两个字符串，写出一个算法计算它们的编辑距离。
*/

#include <iostream>
#include <vector>
using namespace std;


int leven_dist(const string &s1, const string &s2){
    int n1=s1.size();
    int n2=s2.size();

    vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
    // s1，s2的前i个与空集的距离
    for(int i =0; i<=n1; ++i){
        dp[i][0] =i;
    }
    for(int i =0; i<=n2; ++i){
        dp[0][i] =i;
    }

    for( int i=1; i<=n1; ++i){
        for( int j=1; j<=n2; ++j){
            int op1 = dp[i-1][j] +1; // 删除s1 的距离
            int op2 = dp[i][j-1] +1; // 删除s2 的距离
            int op3 = dp[i-1][j-1]; // 替换的距离
            if (s1[i-1]!=s2[j-1]){
                ++op3;
            }
            dp[i][j] = min(min(op1,op2),op3);
        }
    }

    return dp[n1][n2];
}

int main() {
    string s1;
    string s2;
    // getline(cin,s1);
    // getline(cin,s2);
    s1="zik";
    s2="wpnsas";
    cout << leven_dist(s1,s2) << endl;

}
// 64 位输出请用 printf("%lld")