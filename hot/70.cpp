#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 可以使用的方案数目： f(x) = f(x-1) + f(x-2)
        // 使用滚动数组，用三个变量存储方程中的三个数
        int p =0,q=0,r=1; // 这是n=0的时候，r=1，只有一种选择
        for( int i = 1; i<=n; i++){
            p=q; // x-2
            q=r; // x-1
            r = p+q; // x
        }

        return r;
    }
};




int main(){
    Solution entity;
    cout << "hello world" << endl;
    cout << entity.climbStairs(2);
    cout << entity.climbStairs(5);

    return 0;
}