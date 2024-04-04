#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    void back_track(vector<string> &combine_s, string &digits, string &combine, int index, unordered_map<char, string> &phone_mp){
        if(index==digits.size()){
            combine_s.push_back(combine);
            return ;
        }


        string letter = phone_mp[digits[index]];
        for (auto word:letter){
            combine.push_back(word);
            back_track( combine_s, digits, combine, index+1, phone_mp);
            combine.pop_back();
        }
    }


    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phone_mp{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };

        vector<string> combine_s;
        string combine;
        if(digits.empty()){
            return combine_s;
        }
        back_track( combine_s, digits, combine, 0, phone_mp);
        return combine_s;
    }
};


int main(){
    Solution entity;
    vector<int> nums={1,2,3,4};
    cout << "hello world" << endl;
    vector<string> results;
    results=entity.letterCombinations("23");
    for (auto i : results){
        for ( auto j: i){
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}