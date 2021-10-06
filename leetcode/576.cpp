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
    bool checkInclusion(string s1, string s2) {
        int left = 0, right = 0;
        int valid = 0;
        map<char, int> need, window;
        for (char c: s1) need[c]++;

        while (right < s2.size()){
            char c = s2[right];
            right++;
            if (need.count(c)){
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (right - left >= s1.size() ){
                if (valid == need.size()) return true;

                char d = s2[left];
                left++;
                if (need.count(d)){
                    if ( window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }

        return false;
    }
};

int main(){
    Solution entity;
    string s("ab"), t("eidbaooo");

    cout << entity.checkInclusion(s,t);
}