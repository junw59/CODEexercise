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

        for (int i = 1; i < n; i++){
            dpi0 = max(dpi0, dpi1 + prices[i]);
            dpi1 = max(dpi1, -prices[i]);
        }

        return dpi0;
    }
};

int main(){
    Solution entity;
    vector<int> prices = {7,1,5,3,6,4};

    cout << entity.maxProfit(prices);
}