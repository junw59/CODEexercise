#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    getchar();
    string str;
    while(n--){
        getline(cin,str);
        vector<int> fre(26,0);
        for(int i=0; i<str.size(); ++i){
            ++fre[str[i]-'a'];
        }
        sort(fre.begin(), fre.end(), [](int a, int b){return a>b;});
        int beau=0;
        for(int i=0; i<26; ++i){
            beau+=fre[i]*(26-i);
        }
        cout << beau << endl;
    }
}
// 64 位输出请用 printf("%lld")