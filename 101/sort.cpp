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



int main(){
    cout << "hello world" << endl;
    // Solution entity;
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> results;
    // results = entity.findLadders("hit", "cog", word_list);
    word_list={"ted","tex","red","tax","tad","den","rex","pee"};
    // results = entity.findLadders("red", "tax", word_list);

    for (auto i : results) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}