#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
private:
    vector<vector<int>> palin_f;
    vector<vector<string>> ans;
    vector<string> sol;
public:

    void dfs(string &s, int i){
        int n = s.size();
        if(i==s.size()){
            ans.push_back(sol);
        }

        for (int j = i; j <n; j++){
            if(palin_f[i][j]){
                sol.push_back(s.substr(i,j-i+1));
                dfs(s,j+1);
                sol.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
    int n = s.size();
    palin_f.assign(n, vector<int> (n, true));

    for (int i = n-1; i >=0; i--){
        for (int j = i+1 ;j < n; j++){
            palin_f[i][j] = (s[i]==s[j]) && palin_f[i+1][j-1];
        }
    }

    dfs(s,0);
    return ans;

    }
};

int main(){
    Solution entity;
    vector<vector<char>> nums={{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    cout << "hello world" << endl;
    vector<vector<string>> results;
    results = entity.partition("ABACCED");
    for (auto i : results){
        for ( auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}