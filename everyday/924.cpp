#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        // 先标记相同的连通集合
        int n =graph.size();
        vector<int> id_link(n,0);
        unordered_map <int,int> id_of_size;
        int id=0;
        for(int i =0; i<n; ++i){
            // 如果是未归入某一连通集的才继续考虑
            if(id_link[i]==0){
                ++id;
                id_link[i]=id;

                int size=1;
                queue<int> q;
                q.push(i);
                while (!q.empty()){
                    int u = q.front();
                    q.pop();
                    // 遍历所有的与u相连的边
                    for (int v=0; v<n; ++v){
                        if(id_link[v]==0 && graph[u][v]==1){
                            ++size;
                            q.push(v);
                            id_link[v]=id;
                        }
                    }
                }
                id_of_size[id]=size;
                // cout << "id:" << id << " is "<< size<< endl;
            }
        }

        // 已经找完了所有的连通集合
        for(int i =0; i<n; ++i){
            // cout << i << ":" << id_link[i] << endl;
        }
        unordered_map <int, int> init_p;
        // 标记那些被感染的节点的集合id，以及被感染的节点数目
        for(auto x:initial){
            ++init_p[id_link[x]];
        }

        int ans = n+1;
        int removed = 0;
        for(auto x:initial){
            // 只有一个被感染节点的集合的数目就是待移除的可选数目
            int remove_p = (init_p[id_link[x]]==1? id_of_size[id_link[x]]:0);
            // cout << x << ";"<< remove_p << endl;
            // 如果移除的节点数更多，或者虽然移除的节点数是相等的但是编号更靠前
            if(remove_p > removed || (remove_p == removed && x<ans) ){
                ans = x;
                removed = remove_p;
            }
        }
        return ans;
    }


    void dfs(int x,vector<bool> &visited, int &node_id , int &size,unordered_set <int> &st, vector<vector<int>>& graph){
        visited[x]=true;
        ++size;
        if(node_id !=-2 && st.count(x)>0){
            node_id = node_id==-1? x:-2;
        }
        for (int i=0; i <graph[x].size(); ++i){
            if(!visited[i] && graph[x][i]==1){
                dfs(i,visited,node_id,size,st,graph);
            }
        }
    }

    int minMalwareSpread2(vector<vector<int>>& graph, vector<int>& initial) {
        unordered_set <int> st;
        for(auto x:initial){
            st.insert(x);
        }
        int n = graph.size();
        int max_size=0;
        int ans=-1;
        vector<bool> visited(n,false);
        int node_id ,size;
        // 从每一个被感染的节点开始做dfs
        for(auto x: initial){
            if(visited[x]){
                continue;
            }
            // node_id 记录了当前被感染的节点x，-1表示不是被感染的，-2表示遇到了俩个感染节点
            node_id=-1;
            size=0;
            // dfs 遍历和当前节点连接的连通集合
            dfs(x,visited,node_id,size,st,graph);
            if(node_id>-1 && (size>max_size || (size==max_size && node_id<ans ) )){
                max_size = size;
                ans = node_id;
            }
        }

        return ans<0? *min_element(initial.begin(),initial.end()) :ans;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    // vector<vector<int>> nums = {{1,1,0},{1,1,0},{0,0,1}};
    // vector<int> initial = {0,1};
    vector<vector<int>> nums = {{1,0,0},{0,1,0},{0,0,1}};
    vector<int> initial = {0,2};

    // vector<vector<int>> nums = {{1,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,1}};
    // vector<int> initial = {1,3};

    cout << entity.minMalwareSpread(nums, initial);
    cout << entity.minMalwareSpread2(nums, initial);


}