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
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int c = 0;
        int ck = 0;
        while (c < g.size() && ck < s.size()){
            if (g[c] <= s[ck]) c++;
            ck++;
        }

        return c;
    }
};

int main(){
    Solution entity;
    vector<int> c = {1,2};
    vector<int> ck = {1,2,3};
    cout << entity.findContentChildren(c, ck);
}