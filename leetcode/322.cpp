#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 需要的数目
        vector<int> memo(amount+1,-1);

        return dp(coins, amount, memo);
    }

    int dp( vector<int>& coins, int amount, vector<int> &memo){
        // base case
        if (amount == 0 ) return 0;
        if (amount < 0 ) return -1;
        if (memo[amount] != -1) return memo[amount];

        // int res = Integer.MAX_VALUE;
        int res = amount+1;
        for( auto coin: coins){
            int subP = dp(coins, amount-coin, memo);
            if (subP == -1) continue;

            res = min(res, subP + 1);
        }
        memo[amount] = (res == amount + 1? -1 : res);

        // return res == Integer.MAX_VALUE ? -1 : res;
        return memo[amount];
    }
// private:

};

class Solution2 {
public:
    int coinChange(vector<int>& coins, int amount) {
        // 需要的数目
        vector<int> memo(amount+1,amount+1);
        if (amount == 0 ) return 0;
        if (amount < 0 ) return -1;
        memo[0]=0;
        for( int i = 1; i < amount + 1; i++){
            for (int coin: coins){
                if(coin > i) continue;
                memo[i] = min(memo[i],memo[i-coin]+1);
            }
        }
        return memo[amount] > amount ? -1 : memo[amount];
    }
};

int main(){
    Solution entity;
    Solution2 entity2;
    vector<int> coins={186,419,83,408};
    // [186,419,83,408]
    // 6249
    int amount = 827;
    cout << "hello world"<< endl;
    cout << entity2.coinChange(coins, amount) << "\t" << entity.coinChange(coins, amount) << endl;
    return 0;
}