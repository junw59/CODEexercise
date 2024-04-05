#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for ( auto i : prices){
            // 第一天显然不能售卖
            max_profit = max(max_profit, i-min_price);
            min_price = min(min_price,i);
        }
        return max_profit;
    }
};


int main(){
    Solution entity;
    vector<int> nums={7,1,5,3,6,4};
    cout << "hello world" << endl;
    cout << entity.maxProfit(nums);

    return 0;
}