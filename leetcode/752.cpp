#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<string> q;
        set<string> visited;
        for ( auto s : deadends) visited.insert(s);

        q.push("0000");
        if ( visited.count("0000")) return -1;
        visited.insert("0000");
        int step = 0;

        while( !q.empty()){
            int sz = q.size();

            for ( int i = 0; i < sz; i++){
                string cur = q.front();
                q.pop();

                if ( cur == target ) return step;

                for (int j = 0; j < 4; j++){
                    string up = plusone(cur, j);
                    string down = minusone(cur, j);

                    if ( !visited.count(up) ){
                        q.push(up);
                        visited.insert(up);
                    }

                    if ( !visited.count(down) ){
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }

            step++;
        }

        return -1;
    }

    string plusone(string s, int j){
        if( s[j] == '9') s[j] = '0';
        else s[j] += 1;
        return s;
    }

    string minusone(string s, int j){
        if( s[j] == '0') s[j] = '9';
        else s[j] -= 1;
        return s;
    }
};

int main(){
    Solution entity;
    // ["0201","0101","0102","1212","2002"]
    // "0202"
    vector<string> dead={"0201","0101","0102","1212","2002"};
    string target("0202");

    cout << "hello world!" << endl;
    cout << entity.openLock(dead, target) << endl;
}