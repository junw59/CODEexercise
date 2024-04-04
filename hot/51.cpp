#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<string> generate_queen(vector<int> &queens){
        vector<string> sol;
        int n =queens.size();

        for (int i =0; i < n; i++){
            string rows(n,'.');
            rows[queens[i]]='Q';
            sol.push_back(rows);
        }
        return sol;
    }

    void backtrack(vector<vector<string>> &ans, vector<int> &queens, int n, int row, unordered_set<int> &columns, unordered_set<int> &dia_p, unordered_set<int> &dia_anti) {
        if( n == row){
            ans.push_back(generate_queen(queens));
            return ;
        }

        for( int i = 0; i < n; i++){
            // 判断是否存在对应位置的 Q
            if (columns.count(i)>0){
                continue;
            }
            if (dia_p.count(row-i)>0){
                continue;
            }
            if (dia_anti.count(row+i)>0){
                continue;
            }
            queens[row]=i;
            columns.insert(i);
            dia_p.insert(row-i);
            dia_anti.insert(row+i);
            backtrack(ans,queens,n,row+1,columns,dia_p,dia_anti);
            queens[row]=-1;
            columns.erase(i);
            dia_p.erase(row-i);
            dia_anti.erase(row+i);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> queens(n,-1); // 记录n个数，每个数分别是每一行中，第几列是Q
        unordered_set <int> columns; // 记录出现Q的列
        unordered_set <int> dia_p; // 记录出现Q的 row-column ，实际上就是对角线
        unordered_set <int> dia_anti; // 记录出现Q的 row+column ，实际上就是反对角线

        backtrack(ans,queens,n,0,columns,dia_p,dia_anti);
        return ans;
    }
};


int main(){
    Solution entity;
    cout << "hello world" << endl;
    vector<vector<string>> results;
    results = entity.solveNQueens(4);
    for (auto i : results){
        for ( auto j: i){
            cout << j << " " << endl;
        }
        cout << endl;
    }

    return 0;
}