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
    int minimumEffortPath(vector<vector<int>>& heights) {
        const int inf = INT_MAX / 2;
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> effort(m, vector<int> (n, inf));

        int x = 0, y = 0;
        effort[0][0] = 0;

        priority_queue<pair<int, vector<int> >, vector<pair<int, vector<int> >>, greater<> > q;
        q.emplace(0, vector<int> (2, 0));

        while (!q.empty()){
            auto cur = q.top();
            q.pop();

            int consum = cur.first;
            vector<int> posion = cur.second;
            int curx = posion[0];
            int cury = posion[1];
            if ( curx == m - 1 && cury == n - 1) return consum;
            if (consum > effort[curx][cury]) continue;

            for (auto ne: get_adj(heights, curx, cury)){
                int nextx = ne[0];
                int nexty = ne[1];

                int new_effort = max(effort[curx][cury], abs(heights[curx][cury] - heights[nextx][nexty]) );
                if (new_effort < effort[nextx][nexty]){
                    effort[nextx][nexty] = new_effort;
                    vector<int> pos = {nextx, nexty};
                    q.emplace(new_effort,pos);
                }
            }
        }
        return -1;
        // return effort[heights.size()][heights[0].size()];
    }

    vector<vector<int>> get_adj(vector<vector<int>>& heights, int x, int y){
        vector<vector<int>> adj = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> edges;
        for (auto next: adj){
            int nx = x + next[0];
            int ny = y + next[1];
            if (nx < 0 || nx >= heights.size() || ny < 0 || ny >= heights[0].size()) continue;
            vector<int> pos = {nx, ny};
            edges.push_back(pos);
        }
        return edges;
    }
};

int main(){
    // [[1,2,2],[3,8,2],[5,3,5]]; [[1,2,3],[3,8,4],[5,3,5]]; [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
    // vector<vector<int>> times = {{1,2,3},{3,8,2},{5,3,5}};
    vector<vector<int>> times = {{1,2,3},{3,8,4},{5,3,5}};
    // vector<vector<int>> times = {{1,2,1,1,1},{1,2,1,2,1},{1,2,1,2,1},{1,2,1,2,1},{1,1,1,2,1}};
    cout << "hello world" << endl;
    Solution entity;
    cout << entity.minimumEffortPath(times) << endl;
    cout << "byebye world" << endl;
}