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
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0;
        map <char, int> need, window;
        for (char c: p) need[c]++;
        vector<int> res;
        int valid = 0;

        while ( right < s.size()){
            char c = s[right];
            right++;

            if (need.count(c)){
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (right - left >= p.size()){
                if (valid == need.size()) res.push_back(left);

                char d = s[left];
                left++;
                if (need.count(d)){
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }

        return res;
    }
};

int main(){
    Solution entity;
    string s("cbaebabacd"), t("abc");
    vector<int> res = entity.findAnagrams(s,t);
    for (auto i : res){
        cout << i << "\t";
    }
}