#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;


class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
public:
    void dfs(int u){
        visited[u]=1;
        for (auto v : edges[u]){
            if (visited[v]==0){
                dfs(v);
                if (!valid) return ;
            } else if (visited[v]==1){
                valid = false;
                return ;
            }
        }
        visited[u]=2;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // prerequisites 中的 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
        int n = prerequisites.size();
        edges.resize(numCourses);
        visited.resize(numCourses);

        for ( int i =0; i < n ; i++){
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for ( int i =0; i < numCourses && valid ; i++){
            dfs(i);
        }

        return valid;
    }


    bool canFinish_bfs(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> edges_all(numCourses);
        vector<int> in_deg(numCourses);

        for (auto i :prerequisites){
            edges_all[i[1]].push_back(i[0]);
            in_deg[i[0]]++;
        }

        queue<int> q;
        for (int i =0; i < numCourses;i++){
            if ( in_deg[i]==0){
                q.push(i);
            }
        }

        int zero_deg=0;
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            zero_deg++;

            for (auto v : edges_all[cur]){
                in_deg[v]--;
                if (in_deg[v]==0){
                    q.push(v);
                }
            }
        }

        return zero_deg==numCourses;
    }

};




int main(){
    Solution entity;
    vector<vector<int>> nums={{1,0},{0,2}};
    cout << "hello world" << endl;
    int results;
    // results=entity.canFinish(3,nums);
    results=entity.canFinish_bfs(3,nums);
    cout << results << endl;

    return 0;
}
