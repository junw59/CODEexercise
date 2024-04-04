#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;



class Solution {
public:
    bool valid(string & str){
        int bal=0;
        for ( auto i :str){
            if( i == '('){
                bal++;
            }else {
                bal--;
            }
            if (bal < 0 ){
                return false;
            }
        }
        return bal==0;
    }


    void generate_all(vector<string> &ans, string &curr, int n){
        // 直接枚举所有可能性，然后判断是否满足
        if( n == curr.size()){
            if (valid(curr)){
                ans.push_back(curr);
            }
            return ;
        }

        curr.push_back('(');
        generate_all(ans, curr, n);
        curr.pop_back();
        curr.push_back(')');
        generate_all(ans, curr, n);
        curr.pop_back();
    }


    void generate_all_judge(vector<string> &ans, string &curr, int n, int left, int right){
        // 每次判断是否能够继续添加()，
        if( 2*n == curr.size()){
            ans.push_back(curr);
            return ;
        }

        if (left< n){
            curr.push_back('(');
            generate_all_judge(ans, curr, n, left+1, right);
            curr.pop_back();
        }
        if (left > right){
            curr.push_back(')');
            generate_all_judge(ans, curr, n, left, right+1);
            curr.pop_back();
        }
    }


    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        // generate_all(ans, curr, n*2);
        generate_all_judge(ans, curr, n, 0, 0);
        return ans;
    }
};



int main(){
    Solution entity;
    vector<int> nums={1,2,3,4};
    cout << "hello world" << endl;
    vector<string> results;
    results=entity.generateParenthesis(3);
    for (auto i : results){
        for ( auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}