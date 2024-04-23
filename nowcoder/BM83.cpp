#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @param n int整型 
     * @return string字符串
     */
    string trans(string s, int n) {
        // write code here
        if(n==0){
            return s;
        }
        string ans;
        for(int i=0; i<n; ++i){
            if(s[i]>='A' && s[i]<= 'Z'){
                ans.push_back(s[i]-'A'+'a');
            }else if(s[i]>='a' && s[i]<= 'z'){
                ans.push_back(s[i]-'a'+'A');
            }else {
                ans.push_back(s[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        for(int i=0; i<n; ++i){
            int j =i;
            while(j<n && ans[j]!=' '){
                ++j;
            }
            reverse(ans.begin()+i,ans.begin()+j);
            i=j;
        }
        return ans;
    }
};


int main(){
    cout << "hello world" << endl;
    Solution entity;
    cout << entity.trans("This is a sample", 16);

    return 0;
}