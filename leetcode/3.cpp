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
    int lengthOfLongestSubstring(string s) {
        map <char, int> window;
        int left = 0, right = 0;
        int res = 0;

        while( right < s.size()){
            char c = s[right];
            window[c]++;
            right++;

            while (window[c] > 1){
                char d = s[left];
                left ++;
                window[d]--;
            }

            res = max(res, right - left);
        }
        return res;
    }
};

int main(){
    Solution entity;
    string s("ADOBECODEBANC");

    cout << entity.lengthOfLongestSubstring(s);
}