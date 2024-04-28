#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<vector<int>> &mat){
    int n =mat.size();
    int m =mat[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> ans;
    vector<vector<int>> direc={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> visited(n,vector<int>(m,0));
    q.push(make_pair(0,0));
    visited[0][0]=1;
    while(!q.empty()){
        int size_q = q.size();
        while(size_q--){
            pair<int, int> curr = q.front();
            q.pop();
            for (int i =0; i<4; ++i){
                int x=curr.first+direc[i][0],y=curr.second+direc[i][1];
                if( x>=n || x<0 || y>=n || y<0 || visited[x][y]==1 || mat[x][y]==1){
                    continue;
                }
                if(x==n-1 && y==m-1){
                    return true;
                }
                q.push(make_pair(x,y));
                visited[x][y]=1;
            }
        }
    }

    return false;
}

vector<vector<int>> direc={{0,1},{0,-1},{1,0},{-1,0}};

bool dfs(vector<pair<int,int>> &ans,vector<pair<int,int>> &temp_path, vector<vector<int>> &mat, vector<vector<int>> &visited, int n, int m, int k, int l){
    // cout << k << " " << l << " " << visited[k][l] << " \n";
    visited[k][l]=1;
    for (int i =0; i<4; ++i){
        int x=k+direc[i][0],y=l+direc[i][1];
        if( x>=n || x<0 || y>=m || y<0 || visited[x][y]==1 || mat[x][y]==1){
            continue;
        }
        // cout << x << " " << y << " \n";
        temp_path.push_back(make_pair(x,y));
        if( x==n-1 && y==m-1){
            ans=temp_path;
        }
        dfs(ans,temp_path,mat,visited,n,m,x,y);
        visited[k][l]=0;
        temp_path.pop_back();
    }


    return false;
}

int main() {
    vector<vector<int>> mat= {
        // {0, 1, 0, 0, 0,},
        // {0, 1, 1, 1, 0,},
        // {0, 0, 0, 0, 0,},
        // {0, 1, 1, 1, 0,},
        // {0, 0, 0, 1, 0,},
        {0,1,1,1},
        {0,0,0,0}
    };
    vector<pair<int,int>> ans;
    vector<pair<int,int>> temp_path;
    int n =mat.size();
    int m =mat[0].size();
    vector<vector<int>> visited(n,vector<int>(m,0));
    temp_path.push_back(make_pair(0,0));
    dfs(ans,temp_path,mat,visited,n,m,0,0);

    for(auto x:ans){
        cout << "(" << x.first << "," << x.second << ")\n";
    }

    // cout << bfs(mat) << endl;
}
// 64 位输出请用 printf("%lld")