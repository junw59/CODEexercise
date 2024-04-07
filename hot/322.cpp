#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;



class Solution {
public:
    vector <int> dp_list;
    int dp_coins(vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }else if( amount <0){
            return -1;
        }
        // 如果计算过了，就不要重复计算
        if(dp_list[amount]!=0){
            return dp_list[amount];
        }
        int min_num = amount+1;
        for(int coin: coins){
            int temp=dp_coins(coins, amount-coin);
            if(temp>=0 && temp < min_num){
                min_num = temp+1;
            }
        }
        dp_list[amount] = min_num==amount+1? -1: min_num;
        return dp_list[amount];
    }

    int coinChange2(vector<int>& coins, int amount) {
        // 这是递归的自顶向下的方法
        int n =coins.size();
        dp_list.resize(amount+1);
        dp_list[0]=0;
        return dp_coins(coins, amount);
    }

    int coinChange(vector<int>& coins, int amount) {
        // 这是自底向上的计算方法
        int n =coins.size();
        if(amount==0){
            return 0;
        }
        vector <int> dp(amount+1,amount+1);
        dp[0]=0;

        for(int i =1; i < amount+1; i++){
            for (int j = 0; j < n; j++){
                if(i>=coins[j]){
                    dp[i] = min(dp[i-coins[j]]+1,dp[i]);
                }
            }
        }

        return dp[amount]==amount+1? -1: dp[amount];
    }
};



int main(){
    Solution entity;
    cout << "hello world" << endl;
    vector<int> nums={1,2,5};
    cout << entity.coinChange(nums,12);
    nums={2};
    cout << entity.coinChange2(nums,10);
    // cout << INT_MAX;

    return 0;
}