#include<iostream>
#include<string>

using namespace std;

int main(){
    string a;
    // cin >> a ; // 不能读取空格
    getline(cin,a); // 可以读取空格
    a[1]='f';
    cout << a.length() << a << endl;
    char b[100];
    // cin >> noskipws >> b ;
    cin.getline(b,10) ; // 指定读取的字符个数
    // cin >> b ;
    // gets(b); // string 里的
    cout << b << endl;

}