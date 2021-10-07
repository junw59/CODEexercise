#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int dpi0 = 0, dpi1 = -prices[0];

        for (int i = 1; i < n; i++){
            int temp = dpi0;
            dpi0 = max(dpi0, dpi1 + prices[i] - fee);
            dpi1 = max(dpi1, temp - prices[i]);
        }

        return dpi0;
    }
};

int main(){
    Solution entity;
    vector<int> prices = {1,3,2,8,4,9};
    int fee = 2;

    cout << entity.maxProfit(prices,fee);
}