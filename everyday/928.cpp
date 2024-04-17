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
    void dfs(int x,vector<bool> &visited, int &node_id , int &size,unordered_set <int> &st, vector<vector<int>>& graph){
        // 找的待删除节点需要是没看过的，并且在这个集合里面没有出现多个的
        if(node_id==x){
            return;
        }
        if(node_id !=-2 && st.count(x)>0){
            node_id = node_id==-1? x:-2;
            // 如果看到的是感染的节点，不应该继续找它的相邻节点
            return ;
        }
        visited[x]=true;
        ++size;
        for (int i=0; i <graph[x].size(); ++i){
            if(!visited[i] && graph[x][i]==1){
                dfs(i,visited,node_id,size,st,graph);
            }
        }
    }


    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        // 相比928的区别是这里是直接删除节点，而不单单是让节点不被感染而移出initial
        unordered_set <int> st;
        unordered_map <int,int> mp;
        for(auto x:initial){
            st.insert(x);
        }
        int n =graph.size();
        vector <bool> visited(n,false);

        int max_size=-1,ans=-1;
        for(int i =0; i<n; ++i){
            // 所有看过的节点，或者是感染的节点都跳过
            if(visited[i] || st.count(i)>0){
                continue;
            }
            int node_id=-1,size=0;

            dfs(i,visited,node_id,size,st,graph);
            // 那些连接到同一个感染节点的size应该加起来
            if(node_id>0){
                mp[node_id]+=size;
            }
            cout << i << ":" << node_id << ";" << mp[node_id] << endl;
            if(node_id >-1 && mp[node_id] >max_size || (mp[node_id] ==max_size && node_id < ans)){
                ans=node_id;
                max_size=mp[node_id];
            }
        }

        return ans<0? *min_element(initial.begin(),initial.end()) :ans;
    }
};





int main(){
    cout << "hello world" << endl;
    Solution entity;
    // vector<vector<int>> nums = {{1,1,0},{1,1,0},{0,0,1}};
    // vector<vector<int>> nums = {{1,1,0},{1,1,1},{0,1,1}};
    // vector<int> initial = {0,1};

    // vector<vector<int>> nums = {{1,0,0,0},{0,1,1,0},{0,1,1,0},{0,0,0,1}};
    // vector<int> initial = {1,3};

    // vector<vector<int>> nums ={{1,0,0,0,0,0,0,0,0},{0,1,0,0,0,0,0,0,1},{0,0,1,0,0,0,0,0,0},{0,0,0,1,0,0,0,0,1},{0,0,0,0,1,0,1,1,1},{0,0,0,0,0,1,0,0,1},{0,0,0,0,1,0,1,1,0},{0,0,0,0,1,0,1,1,0},{0,1,0,1,1,1,0,0,1}} ;
    // vector<int> initial = {8,4,2,0};

    // vector<vector<int>> nums ={{1,0,0,0,0,0,0,0,1},{0,1,0,1,0,0,0,0,0},{0,0,1,1,0,1,0,0,0},{0,1,1,1,1,0,1,0,0},{0,0,0,1,1,1,0,0,0},{0,0,1,0,1,1,0,0,0},{0,0,0,1,0,0,1,1,0},{0,0,0,0,0,0,1,1,1},{1,0,0,0,0,0,0,1,1}};
    // vector<int> initial = {7,3};

    vector<vector<int>> nums = {{1,1,0,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0},{0,0,0,1,0,0,1,0,0,1},{0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,1,0,0,0,0},{0,0,0,1,0,0,1,0,0,0},{0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,0,1,0},{0,0,0,1,0,0,0,0,0,1}};
    vector<int> initial = {2,1,9};

    cout << entity.minMalwareSpread(nums, initial);


}