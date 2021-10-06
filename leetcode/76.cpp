#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> need, window;
        for ( char c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;

        int start = 0, len = s.size() + 1;
        while( right < s.size()){
            char c = s[right];
            right++;

            if (need.count(c)){
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while( valid == need.size()){
                if (right - left < len){
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;

                if (need.count(d)){
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }

        return len == s.size() + 1 ? "" : s.substr(start, len);
    }
};

int main(){
    Solution entity;
    string s("ADOBECODEBANC"), t("ABC");

    cout << entity.minWindow(s,t);
}