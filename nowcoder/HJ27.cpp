#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool is_brother(string s1, string s2){
    if(s1.length()!=s2.length()|| s1==s2){
        return false;
    }
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if( s1==s2){
        return true;
    }
    return false;
}


int main() {
    int n;
    while (cin>>n) {
        vector<string> strs(n);
        for( int i=0; i <n; ++i){
            cin >> strs[i];
        }
        string tar_str;
        cin >> tar_str;
        int k;
        cin >> k;
        vector<string> bros;
        for( int i=0; i <n; ++i){
            if(is_brother(tar_str, strs[i])){
                bros.emplace_back(strs[i]);
            }
        }

        cout << bros.size() << endl;
        if (k -1< bros.size()){
            sort(bros.begin(),bros.end());
            cout << bros[k-1] << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")