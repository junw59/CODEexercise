#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;

class Solution {
public:
    string get_digit(string &s, int &p_str){
        string sub;
        while (isdigit(s[p_str])){
            sub.push_back(s[p_str]);
            p_str++;
        }
        return sub;
    }

    string get_string(vector<string> &sub_v){
        // 获取vector对应的字符串
        string sub;
        for (auto ch: sub_v){
            sub+=ch;
        }
        return sub;
    }

    string decodeString(string s) {
        vector <string> sta;
        int p_str=0;

        while (p_str<s.size()){
            char ch = s[p_str];
            cout << ch << endl;

            if(isdigit(ch)){
                string digit = get_digit(s,p_str);
                sta.push_back(digit);
            } else if (isalpha(ch)|| ch =='['){
                sta.push_back(string(1,ch));
                p_str++;
            } else {
                p_str++;
                vector<string> sub_v;
                // 把需要重复的字母拿出来
                while (sta.back()!="["){
                    sub_v.push_back(sta.back());
                    sta.pop_back();
                }
                // 反转得到需要的顺序
                reverse(sub_v.begin(),sub_v.end());
                sta.pop_back();
                // 需要重复的次数，可能是多位数
                int stop_time = stoi(sta.back());
                sta.pop_back();
                string o= get_string(sub_v);
                string t;
                while (stop_time>0){
                    t+=o;
                    stop_time--;
                }
                sta.push_back(t);
            }
        }
        return get_string(sta);
    }
};

int main(){
    Solution entity;
    cout << "hello world" << endl;
    cout << entity.decodeString("3[a]2[2[bc]]");

    return 0;
}