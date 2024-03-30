#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;


class Solution {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
    vector<int> visited;
    // 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
    vector<int> result;
    // 判断有向图中是否有环
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
        visited[u]=2; // 表示完成
        result.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // prerequisites 中的 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
        int n = prerequisites.size();
        edges.resize(numCourses);
        visited.resize(numCourses);

        for ( int i =0; i < n ; i++){
            // 存储的是指向的节点数组
            edges[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for ( int i =0; i < numCourses && valid ; i++){
            if (!visited[i]){
                dfs(i);
            }
        }

        if (!valid){
            return {};
        }

        reverse(result.begin(), result.end());
        return result;
    }


    vector<int>  findOrder_bfs(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> edges_all(numCourses);
        vector<int> in_deg(numCourses);
        vector<int> ret_order;

        for (auto i :prerequisites){
            edges_all[i[1]].push_back(i[0]);
            in_deg[i[0]]++;
        }

        queue<int> q;
        for (int i =0; i < numCourses;i++){
            if ( in_deg[i]==0){
                q.push(i);
                ret_order.push_back(i);
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
                    ret_order.push_back(v);
                    q.push(v);
                }
            }
        }

        if(zero_deg!=numCourses){
            return {};
        }

        return ret_order;
    }

};




int main(){
    Solution entity;
    vector<vector<int>> nums={{1,0},{0,3},{3,2}};
    // vector<vector<int>> nums={{1,0}};
    cout << "hello world" << endl;
    vector<int> results;
    results=entity.findOrder(4,nums);
    // results=entity.findOrder_bfs(4,nums);
    for (auto i : results){
        cout << i << " " ;
    }

    return 0;
}
