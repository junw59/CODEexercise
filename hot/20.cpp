#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2==1){
            return false;
        }

        unordered_map <char,char> pairs{
            {')','('},
            {'}','{'},
            {']','['},
        };
        stack<char> sta;

        for (auto ch : s){
            if(pairs.count(ch)>0){
                // 说明找到了右边的括号
                if(sta.empty() || sta.top()!=pairs[ch]){
                    return false;
                }
                sta.pop();
            }else {
                sta.push(ch);
            }
        }

        return sta.empty();
    }
};


int main(){
    Solution entity;
    cout << "hello world" << endl;
    cout << entity.isValid("()[]{}");

    return 0;
}