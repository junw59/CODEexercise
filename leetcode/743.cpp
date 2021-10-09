#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        const int inf = INT_MAX / 2;
        // vector<vector<int>> graph(n, vector<n, inf>);
        // for (auto edge: tiems){
        //     int x = edge[0] - 1;
        //     int y = edge[1] - 1;
        //     graph[x][y] = edge[2];
        // }
        vector<vector<pair<int, int>>> graph(n);
        for (auto edge: times){
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            graph[x].emplace_back(y, edge[2]);
        }

        vector<int> distTo(n, inf);

        distTo[k-1] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > q;
        q.emplace(0, k - 1);

        while (!q.empty()){
            auto cur = q.top();
            q.pop();

            int time = cur.first, nodeid = cur.second;
            if (distTo[nodeid] < time) continue; // 找到一个新的节点，看看距离有没有变短

            for ( auto ne : graph[nodeid]){
                int nextId = ne.first, nextTime = ne.second + distTo[nodeid];

                if ( nextTime < distTo[nextId]){
                    distTo[nextId] = nextTime;
                    q.emplace(nextTime, nextId);
                }
            }
        }

        int ans = *max_element(distTo.begin(), distTo.end());
        return ans == inf ? -1 : ans;
    }

};

int main(){
    // [[2,1,1],[2,3,1],[3,4,1]],4
    cout << "hello world" << endl;
}