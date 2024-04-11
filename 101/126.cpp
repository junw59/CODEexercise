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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> dict ={wordList.begin(),wordList.end()};
        if (dict.count(endWord)<1){
            return ans;
        }
        dict.erase(beginWord);
        dict.erase(endWord);
        // 先构建单词的连接图，
        unordered_map <string, unordered_set<string>> next;
        bool found = false;
        queue <string> q1;
        q1.push(beginWord);

        unordered_map<string, int> steps = {{beginWord, 0}};
        int step=0;
        while (!q1.empty()) {
            ++step;
            int size = q1.size();
            // unordered_set<string> del_word;
            for (int i = 0; i < size; ++i) {
                string curr_word = q1.front();
                q1.pop();
                int word_len = curr_word.size();
                string next_word = curr_word;
                // 将每一个字母都转换试试
                for (int j = 0; j < word_len; ++j) {
                    // 待会还要换回来
                    char origin_ch = next_word[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        next_word[j] = ch;
                        if(steps[next_word]==step){
                            // 解决的是多个word指向同一个的问题
                            // next[curr_word].insert(next_word);
                            next[next_word].insert(curr_word);
                        }
                        if(next_word==endWord){
                            // 可能有多个word都对应 endWord  
                            // next[curr_word].insert(next_word);
                            next[next_word].insert(curr_word);
                            found=true;
                        }
                        if(dict.count(next_word)>0){
                            // cout << curr_word << "  " << next_word <<endl;
                            // next[curr_word].insert(next_word);
                            next[next_word].insert(curr_word);
                            q1.push(next_word);
                            // del_word.insert(next_word);
                            // 同层指向同样的下一个单词就会错误，因此改在后面删除
                            dict.erase(next_word);
                            steps[next_word]=step;
                        }
                    }
                    next_word[j] = origin_ch;
                }
            }
            // for (const string &next_word: del_word){
            //     dict.erase(next_word);
            // }


            if( found){
                cout << "found it!" << endl;
                break;
            }
        }

        if(found){
            // 通过回溯得到路径，此时已经是最短的路径了，并且endWord一定在next的最后
            vector<string> path;
            path.push_back(endWord);
            // backtrack(ans, path, next, beginWord, endWord);
            reverse_backtrack(ans, path, next, beginWord, endWord);
        }

        return ans;
    }


    void reverse_backtrack(vector<vector<string>> &ans, vector<string> &path, unordered_map <string, unordered_set<string>> &next, string start, string target){
        // 从最后开始找目标路径
        if(start == target){
            ans.push_back({path.rbegin(), path.rend()});
            return ;
        }

        for(const string &next_word : next[target]){
            path.push_back(next_word);
            reverse_backtrack(ans, path, next, start, next_word);
            path.pop_back();
        }

    }



    vector<vector<string>> findLadders2(string beginWord, string endWord, vector<string>& wordList) {
        // 通过交替起点和终点,减少路径
        vector<vector<string>> ans;
        unordered_set<string> dict ={wordList.begin(),wordList.end()};
        if (dict.count(endWord)<1){
            return ans;
        }
        dict.erase(beginWord);
        dict.erase(endWord);
        // 先构建单词的连接图，
        unordered_map <string, unordered_set<string>> next;
        bool found = false;
        unordered_set<string> q1;
        q1.insert(beginWord);
        unordered_set<string> q2;
        q2.insert(endWord);

        bool forward=true;
        while (!q1.empty()) {
            unordered_set<string> del_word;
            int size = q1.size();
            for (string curr_word : q1) {
                // string curr_word = q1.front();
                // q1.pop();
                int word_len = curr_word.size();
                string next_word = curr_word;
                // 将每一个字母都转换试试
                for (int j = 0; j < word_len; ++j) {
                    // 待会还要换回来
                    char origin_ch = next_word[j];
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        next_word[j] = ch;
                        if(q2.count(next_word)>0){
                            // 可能有多个word都对应 endWord  
                            forward ? next[curr_word].insert(next_word):next[next_word].insert(curr_word);
                            found=true;
                        }
                        if(dict.count(next_word)>0){
                            // cout << curr_word << "  " << next_word <<endl;
                            forward ? next[curr_word].insert(next_word):next[next_word].insert(curr_word);
                            del_word.insert(next_word);
                            // 同层指向同样的下一个单词就会错误，因此
                            // dict.erase(next_word);
                        }
                    }
                    next_word[j] = origin_ch;
                }
            }

            if( found){
                cout << "found it!" << endl;
                break;
            }

            for (const string &next_word: del_word){
                dict.erase(next_word);
            }

            if(del_word.size()<=q2.size()){
                q1=del_word;
            }else {
                forward=!forward;
                q1=q2;
                q2=del_word;
            }
        }

        if(found){
            // 通过回溯得到路径，此时已经是最短的路径了，并且endWord一定在next的最后
            vector<string> path;
            path.push_back(beginWord);
            backtrack(ans, path, next, beginWord, endWord);
        }

        return ans;
    }


    void backtrack(vector<vector<string>> &ans, vector<string> &path, unordered_map <string, unordered_set<string>> &next, string start, string target){
        if(start == target){
            ans.push_back(path);
            return ;
        }

        for(const string &next_word : next[start]){
            path.push_back(next_word);
            backtrack(ans, path, next, next_word, target);
            path.pop_back();
        }
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    vector<vector<string>> results;
    // results = entity.findLadders("hit", "cog", word_list);
    word_list={"ted","tex","red","tax","tad","den","rex","pee"};
    results = entity.findLadders("red", "tax", word_list);

    for (auto i : results) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}