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
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        if (start >= n || end >= n) return 0.0;
        const int inf = INT_MAX / 2;
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];
            graph[x].emplace_back(y, succProb[i]);
            graph[y].emplace_back(x, succProb[i]);
        }

        vector<double> probTo(n, -1);
        priority_queue<pair<double, int>, vector<pair<double, int>>, less<> > q;

        probTo[start] = 1;
        q.emplace(1, start);

        while (!q.empty()){
            auto cur = q.top();
            q.pop();

            double cpro = cur.first;
            int cId = cur.second;

            if (cId == end) return cpro;
            if (probTo[cId] > cpro) continue;
            for ( auto ne: graph[cId]){
                int nextId = ne.first;
                double nextpro = ne.second * probTo[cId];

                if (nextpro > probTo[nextId]){
                    probTo[nextId] = nextpro;
                    q.emplace(nextpro, nextId);
                }
            }
        }

        return 0.0;
    }
};

int main(){
    // 3
    // [[0,1],[1,2],[0,2]]
    // [0.5,0.5,0.2]
    // 0
    // 2
    int n = 3, start = 0, end = 2;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> probs = {0.5, 0.5, 0.2};
    cout << "hello world" << endl;
    Solution entity;
    cout << entity.maxProbability(n,edges,probs, start, end) << endl;
    cout << "byebye world" << endl;
}