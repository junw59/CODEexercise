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

                    // 队列可以有重复的，所以需要及时修改 visited
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

class Solution2 {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> q1;
        set<string> q2;
        set<string> visited;
        for ( auto s : deadends) visited.insert(s);

        q1.insert("0000");
        q2.insert(target);
        if ( visited.count("0000")) return -1;
        visited.insert("0000");
        int step = 0;

        while( !q1.empty() && !q2.empty()){
            set<string> wait;
            for ( auto cur : q1){
                // if ( cur == target ) return step;
                if ( q2.count(cur) ) return step;
                // wait 和q1 不同，不能随up down 更新visited
                visited.insert(cur);

                for (int j = 0; j < 4; j++){
                    string up = plusone(cur, j);
                    string down = minusone(cur, j);

                    // 如果在这里更新 visited，将无法抵达真正的答案，因为q1和q2会互换扩散
                    if ( !visited.count(up) ){
                        wait.insert(up);
                        // visited.insert(up);
                    }

                    if ( !visited.count(down) ){
                        wait.insert(down);
                        // visited.insert(down);
                    }
                }
            }

            q1 = q2;
            q2 = wait;
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
    Solution2 entity2;
    // ["0201","0101","0102","1212","2002"]
    // "0202"
    vector<string> dead={"0201","0101","0102","1212","2002"};
    string target("0202");

    cout << "hello world!" << endl;
    cout << entity.openLock(dead, target) << "\t" << entity2.openLock(dead, target) << endl;
}