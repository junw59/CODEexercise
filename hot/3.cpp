#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n =s.size();
        int rk = 0;
        int ans=0;
        for (int lk =0; lk < n; lk++){
            if (lk!=0){
                occ.erase(s[lk-1]);
            }
            while (rk<n && !occ.count(s[rk])){
                occ.insert(s[rk]);
                rk++;
            }
            ans=max(ans,rk-lk);
        }
        return ans;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    string s="abcabdecbb";
    // vector<int> nums={1,1};
    int ans=entity.lengthOfLongestSubstring(s);
    cout << ans << " ";
}
