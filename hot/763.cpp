#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;



class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector <int> last(26);
        // 计算char出现在最后的位置
        for (int i = 0; i < n; i++){
            last[s[i]-'a']=i;
        }

        int end = 0,start=0;
        vector<int> ans;
        for ( int i = 0; i < n; i++){
            end = max(end, last[s[i]-'a']);
            if( i == end){
                ans.push_back(end-start+1);
                start = end+1;
            }
        }
        return ans;
    }
};



int main(){
    Solution entity;
    vector<int> nums={2,3,1,1,4};
    cout << "hello world" << endl;
    vector<int> results;
    results=entity.partitionLabels("ababcbacadefegdehijhklij");
    for (auto i : results){
        cout << i << endl;
    }

    return 0;
}