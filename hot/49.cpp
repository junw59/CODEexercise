#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashtable;
        // 使用引用 & 可以节约空间
        for (string &str: strs){
            string key = str;
            sort(key.begin(),key.end());
            hashtable[key].emplace_back(str);
        }
        vector<vector<string>> ans;
        for (auto it = hashtable.begin(); it != hashtable.end(); it++){
            ans.emplace_back(it->second);
        }
        return ans;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> results;
    results=entity.groupAnagrams(strs);
    for (auto i : results){
        for (auto j :i){
            cout << j << " ";
        }
        cout << ";";
    }

    return 0;
}