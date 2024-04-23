#include <iostream>
#include <map>
using namespace std;

int main() {
    int a, b;
    int num;
    cin >> num;
    map<int, int> mp;
    while (num--) {
        cin >> a >> b;
        mp[a] += b;
    }
    for(auto x:mp){
        if (x.second > 0) {
            cout << x.first << ' ' << x.second << endl;
        }
    }
}
// 64 位输出请用 printf("%lld")