#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

string plusone(string s, int j){
    if( s[j] == '9') s[j] = '0';
    else s[j] += 1;
    return s;
}

int main(){
    string a("102");
    cout << "hello world" << endl;
    a[1] += 1;
    cout << a << endl;
    string b("112");
    cout << a.compare(b) << endl;;
    cout << (a[1] == '1') << endl;
    cout << a << plusone(a,1) << endl;
}
