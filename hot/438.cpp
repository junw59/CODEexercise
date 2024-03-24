#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int ns = s.size(), np=p.size();
        if (ns<np){
            return vector<int>();
        }
        vector<int> ans;
        vector<int> p_count(26);
        vector<int> s_count(26);
        for (int i =0; i < np; i++){
            p_count[p[i]-'a']++;
            s_count[s[i]-'a']++;
        }
        if (p_count==s_count){
            ans.emplace_back(0);
        }
        for (int i =0; i < ns-np; i++){
            s_count[s[i]-'a']--;
            s_count[s[i+np]-'a']++;

            if (s_count==p_count){
                ans.emplace_back(i+1);
            }
        }

        return ans;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    string s="cbaebabacd";
    string p="abc";
    // vector<int> nums={1,1};
    vector<int> ans;
    ans=entity.findAnagrams(s,p);
    for (auto i : ans){
        cout << i << endl;
    }
}