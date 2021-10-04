#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n,'.'));
        backtrack(board, 0, res);
        return res; 
    }

    void backtrack(vector<string> & board, int row, vector<vector<string>> & res){
        // 结束条件
        if (row == board.size()){
            res.push_back(board);
            return ;
        }

        int n = board[row].size();
        for ( int col = 0; col < n; col++){
            if (! isValid(board, row, col)) continue;

            board[row][col] = 'Q';
            backtrack(board, row + 1, res);
            board[row][col] = '.';
        }
        return ;
    }

    bool isValid(vector<string> & board, int row, int col){
        int n = board.size();

        // 同一列
        for ( int i = 0; i < n; i++){
            if (board[i][col] == 'Q') return false;
        }

        // 右上方
        for ( int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if (board[i][j] == 'Q') return false;
        }

        // 左上方
        for ( int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--){
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }
};

int main(){
    Solution entity;
    vector <int> nums={1,2,3,4};
    cout << "hello world"<< endl;
    vector <vector <string>> res;
    res=entity.solveNQueens(4);
    for ( auto first : res){
        for ( auto second : first){
            cout << second << "\n";
        }
        cout << "\n" << endl;
    }
    cout << res.size();
    return 0;
}