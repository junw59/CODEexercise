#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin,str);
    vector<int> a(26,0);
    int n = str.length();
    int min_t=21;
    for(int i =0; i < n; ++i){
        ++a[str[i]];
    }
    for(int i =0; i < n; ++i){
        min_t=min(min_t,a[str[i]]);
    }

    cout << min_t << endl;
    string new_str;
    for(int i=0; i< n; ++i){
        if(a[str[i]] >0 && a[str[i]]!=min_t){
            new_str.push_back(str[i]);
        }
    }
    cout << new_str << endl;

}
// 64 位输出请用 printf("%lld")