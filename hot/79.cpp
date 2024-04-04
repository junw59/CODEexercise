#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;



class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool check(vector<vector<char>>& board, string word, vector<vector<int>> &visited, int i, int j, int curr){
        int n = board.size();
        int m = board[0].size();

        if(visited[i][j]==1) return false;
        if(board[i][j]!=word[curr]){
            return false;
        }
        if(curr==word.size()-1 && board[i][j]==word[curr]){
            return true;
        }

        bool flag;
        visited[i][j]=1;
        for (int sel = 0; sel < 4; sel++) {
            int new_i = i + directions[sel][0], new_j = j + directions[sel][1];
            if(new_i>=0 && new_i < n && new_j>=0 && new_j < m){
                if (visited[new_i][new_j]==0){
                    flag=check(board, word, visited, new_i, new_j, curr+1);
                    if(flag){ return flag;}
                }
            }
        }
        visited[i][j]=0;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(),vector<int> (board[0].size(),0));
        bool flag;
        int n = board.size();
        int m = board[0].size();

        for (int i =0; i < n; i++){
            for (int j =0; j < m; j++){
                    flag= check(board, word, visited, i, j, 0);
                    if(flag){ return flag;}
            }
        }
        return false;
    }
};


int main(){
    Solution entity;
    // vector<vector<char>> nums={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    vector<vector<char>> nums={{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    cout << "hello world" << endl;
    vector<string> results;
    cout << entity.exist(nums,"ABCCED") << endl;
    cout << entity.exist(nums,"ABCB") << endl;
    cout << entity.exist(nums,"AAB") << endl;
    for (auto i : nums){
        for ( auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}