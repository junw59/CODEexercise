#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n<1) return 0;
        vector <int> fibs(n+1,0);
        fibs[0]=0;
        fibs[1]=1;
        return memf(fibs , n);
    }

    int memf( vector<int> &fibs, int n){
        if (n < 2) return fibs[n];
        if (fibs[n] != 0){
            return fibs[n];
        }
        fibs[n] = memf(fibs,n-1)+memf(fibs, n-2);
        return fibs[n];
    }
};

int main(){
    Solution entity;
    cout << "hello world"<< endl;
    cout << entity.fib(1) << "\t" << entity.fib(5) << "\t" << entity.fib(10);
    return 0;
}