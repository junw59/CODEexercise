#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;


class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_map <int, int> mp;
        for(int i=0; i<n; i++){
            mp[i]=0;
        }
        for (vector<int> &temp: edges){
            mp[temp[1]]++;
        }

        for(int i=0; i<n; i++){
            if ( mp[i] >0){
                mp.erase(i);
            }
        }

        return mp.size()==1 ? mp.begin()->first : -1;
    }
};



int main(){
    cout << "hello world" << endl;
    Solution entity;
    // vector<vector<int>> nums={{0,2},{1,3},{1,2}};
    vector<vector<int>> nums={{0,1},{1,2}};
    cout << entity.findChampion(3, nums) << endl;

    return 0;
}