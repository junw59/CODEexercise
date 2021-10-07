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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dpi0 = 0, dpi1 = -prices[0];
        int dippre0 = 0;

        for (int i = 1; i < n; i++){
            int temp = dpi0;
            dpi0 = max(dpi0, dpi1 + prices[i]);
            dpi1 = max(dpi1, dippre0 - prices[i]);
            dippre0 = temp;
        }

        return dpi0;
    }
};

int main(){
    Solution entity;
    vector<int> prices = {1,2,3,0,2};

    cout << entity.maxProfit(prices);
}