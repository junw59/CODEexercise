#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class UnionFind{
    // 并查集
private :
    vector <int> parents;
    vector <int> rank;
    int count;

public :
    UnionFind(vector<vector<char>>& grid){
        count = 0;
        int nr = grid.size();
        int nc = grid[0].size();
        for (int i = 0 ; i< nr; i++){
            for (int j = 0 ; j< nc; j++){
                if(grid[i][j]=='1'){
                    parents.push_back(i*nc+j);
                    count++;
                } else{
                    parents.push_back(-1);
                }
                rank.push_back(0);
            }
        }
    }

    int find(int num){
        if ( parents[num] != num){
            parents[num]=find(parents[num]);
        }
        return parents[num];
    }

    void unite( int i, int j){
        int par_i = find(i);
        int par_j = find(j);

        if (par_i!=par_j){
            if(rank[par_i] < rank[par_j]){
                swap(par_i,par_j);
            }
            parents[par_j] = par_i;
            if(rank[par_i] == rank[par_j]){
                rank[par_i]++;
            }
            count--;
        }
    }

    int get_count(){
        return count;
    }
};


class Solution {
public:
    void dfs(vector<vector<char>>& grid, int nr, int nc, int r, int c){
        grid[r][c]='0';
        if(r-1>=0 && r-1<nr && grid[r-1][c]=='1') dfs(grid,nr,nc,r-1,c);
        if(r+1>=0 && r+1<nr && grid[r+1][c]=='1') dfs(grid,nr,nc,r+1,c);
        if(c-1>=0 && c-1<nc && grid[r][c-1]=='1') dfs(grid,nr,nc,r,c-1);
        if(c+1>=0 && c+1<nc && grid[r][c+1]=='1') dfs(grid,nr,nc,r,c+1);
    }


    int numIslands(vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        int ans=0;
        for (int i = 0 ; i< nr; i++){
            for (int j = 0 ; j< nc; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,nr,nc,i,j);
                }
            }
        }

        return ans;
    }


    int numIslands_dfs(vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        int ans=0;
        for (int i = 0 ; i< nr; i++){
            for (int j = 0 ; j< nc; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    grid[i][j]='0';
                    stack<pair<int,int>> q;
                    q.push({i,j});
                    while (!q.empty()){
                        int r,c;
                        tie(r,c) = q.top();
                        q.pop();
                        grid[r][c]='0';
                        if(r-1>=0 && r-1<nr && grid[r-1][c]=='1'){
                            q.push({r-1,c});
                            grid[r-1][c]='0';
                        }
                        if(r+1>=0 && r+1<nr && grid[r+1][c]=='1'){
                            q.push({r+1,c});
                            grid[r+1][c]='0';
                        }
                        if(c-1>=0 && c-1<nc && grid[r][c-1]=='1'){
                            q.push({r,c-1});
                            grid[r][c-1]='0';
                        }
                        if(c+1>=0 && c+1<nc && grid[r][c+1]=='1'){
                            q.push({r,c+1});
                            grid[r][c+1]='0';
                        }
                    }
                    
                }
            }
        }
        return ans;
    }

    int numIslands_bfs(vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        int ans=0;
        for (int i = 0 ; i< nr; i++){
            for (int j = 0 ; j< nc; j++){
                if(grid[i][j]=='1'){
                    ans++;
                    grid[i][j]='0';
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while (!q.empty()){
                        int r,c;
                        tie(r,c) = q.front();
                        q.pop();
                        grid[r][c]='0';
                        if(r-1>=0 && r-1<nr && grid[r-1][c]=='1'){
                            q.push({r-1,c});
                            grid[r-1][c]='0';
                        }
                        if(r+1>=0 && r+1<nr && grid[r+1][c]=='1'){
                            q.push({r+1,c});
                            grid[r+1][c]='0';
                        }
                        if(c-1>=0 && c-1<nc && grid[r][c-1]=='1'){
                            q.push({r,c-1});
                            grid[r][c-1]='0';
                        }
                        if(c+1>=0 && c+1<nc && grid[r][c+1]=='1'){
                            q.push({r,c+1});
                            grid[r][c+1]='0';
                        }
                    }
                }
            }
        }
        return ans;
    }



    int numIslands_union(vector<vector<char>>& grid) {
        int nr = grid.size();
        int nc = grid[0].size();
        UnionFind uni(grid);
        for (int r = 0 ; r< nr; r++){
            for (int c = 0 ; c< nc; c++){
                if(grid[r][c]=='1'){
                    grid[r][c]='0';
                    if(r-1>=0 && r-1<nr && grid[r-1][c]=='1') uni.unite(r*nc+c, nc*(r-1)+c);
                    if(r+1>=0 && r+1<nr && grid[r+1][c]=='1') uni.unite(r*nc+c, nc*(r+1)+c);
                    if(c-1>=0 && c-1<nc && grid[r][c-1]=='1') uni.unite(r*nc+c, nc*r+c-1);
                    if(c+1>=0 && c+1<nc && grid[r][c+1]=='1') uni.unite(r*nc+c, nc*r+c+1);
                }
            }
        }

        return uni.get_count();
    }
};



int main(){
    Solution entity;
    vector<vector<char>> nums={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','1'}};
    cout << "hello world" << endl;
    int results;
    // results=entity.numIslands(nums);
    // results=entity.numIslands_bfs(nums);
    // results=entity.numIslands_dfs(nums);
    results=entity.numIslands_union(nums);
    cout << results << endl;

    return 0;
}