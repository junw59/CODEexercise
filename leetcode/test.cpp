#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string plusone(string s, int j)
{
    if (s[j] == '9')
        s[j] = '0';
    else
        s[j] += 1;
    return s;
}

int main()
{
    cout << "hello world" << endl;
    // string a("102");
    // a[1] += 1;
    // cout << a << endl;
    // string b("112");
    // cout << a.compare(b) << endl;;
    // cout << (a[1] == '1') << endl;
    // cout << a << plusone(a,1) << endl;
    // cout << a.substr(1,2);

    // map<char, int> need, window;
    // need['c']++;
    // cout << need['c'] << endl;
    // cout << need['d'] << endl;

    vector<vector<int>> twov = {{1, 2, 3, 4, 5}, {1, 2, 3, 5, 6}};
    for (auto i : twov){
        for (auto j : i){
            cout << j << "\t";
        }
    }
}
