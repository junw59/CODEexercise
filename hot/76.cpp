#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    unordered_map <char, int> mt,ms;
    string minWindow(string s, string t) {
        for (auto i : t){
            mt[i]++;
        }
        int n=s.size();

        int ansL=-1,ansN=n+1;
        int l =0;
        for (int r=0; r <n; r++){
            if (mt.find(s[r])!=mt.end()){
                ms[s[r]]++;
            }
            while ( check() && l<=r){
                if (r-l+1 <ansN){
                    ansL = l;
                    ansN=r-l+1;
                }
                if (mt.find(s[l])!=mt.end()){
                    ms[s[l]]--;
                }
                l++;
            }
        }
        return ansL==-1? string("") :s.substr(ansL,ansN);
    }

    bool check(){
        for (const auto &p:mt){
            if (ms[p.first] < p.second){
                return false;
            }
        }
        return true;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    string ans="",s="ADOBECODEBANC",t="ABC";
    ans=entity.minWindow(s,t);
    cout << ans << endl;
}