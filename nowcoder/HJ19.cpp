#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    string str;
    vector<string> names;
    unordered_map<string, int> mp;
    while (getline(cin,str)) {
        if(str=="\n") break;
        int a,b;
        for(int i =0; i< str.length(); ++i){
            if(str[i]=='\\'){
                a=i;
            }else if (str[i]==' '){
                b=i;
            }
        }
        string name;
        if(b-a-1 >16){
            name=str.substr(b-16);
        }else{
            name=str.substr(a+1);
        }
        if(mp.count(name)==0){
            names.push_back(name);
        }
        ++mp[name];
        cout << name << ' ' << mp[name] << endl;
    }
    for (int i = names.size()-8>=0?names.size()-8: 0;i<names.size(); ++i){
        cout << names[i] << ' ' << mp[names[i]] << endl;
    }
}
// 64 位输出请用 printf("%lld")