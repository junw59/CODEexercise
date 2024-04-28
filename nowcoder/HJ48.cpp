#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list<int> lt;
    int num;
    cin >> num;
    int elem;
    cin >> elem;
    lt.push_back(elem);
    num--;
    while (num--){
        int val, prev;
        cin >> val >> prev;
        auto it = find(lt.begin(), lt.end(), prev);
        lt.insert(++it, val);

    }

    int del_num;
    cin >> del_num;
    auto it = find(lt.begin(), lt.end(), del_num);
    lt.erase(it);


    for( auto x: lt){
        cout << x << " " ;
    }
    cout << endl;
}
// 64 位输出请用 printf("%lld")