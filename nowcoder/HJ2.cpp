#include <iostream>
using namespace std;
#include<string>
int main() {
    string str;
    getline(cin,str);
    char ch;
    cin >> ch;
    char ch2;
    cout << str << endl;
    cout << ch << endl;
    if(ch>='a' && ch<='z'){
        ch2=ch-'a'+'A';
    }else if (ch>='A' && ch<='Z'){
        ch2=ch-'A'+'a';
    }
    int num=0;
    for(int i=0; i < str.length(); ++i){
        if(str[i]==ch || str[i]==ch2)
        ++num;
    }
    cout << num << endl;
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }
}
// 64 位输出请用 printf("%lld")