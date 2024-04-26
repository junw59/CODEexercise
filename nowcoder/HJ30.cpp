#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

char trans_ch(char ch) {
    int binary_int;
    if (ch >= '0' && ch <= '9') {
        binary_int = ch - '0';
    } else if (ch >= 'a' && ch <= 'f') {
        binary_int = ch - 'a' + 10;
    } else if (ch >= 'A' && ch <= 'F') {
        binary_int = ch - 'A' + 10;
    }else {
        return ch;
    }
    // cout << ch << " " << binary_int << " ";

    vector<int> bi(4);
    for (int i = 0; i < 4; ++i) {
        bi[i] = binary_int % 2;
        binary_int = binary_int / 2;
    }
    // for ( auto x: bi) cout << x << " " ;
    // swap(bi[0],bi[3]);
    // swap(bi[1],bi[2]);
    // for ( auto x: bi) cout << x << " " ;
    int rev_int = 0;
    for (int i = 0; i < 4; ++i) {
        rev_int = rev_int * 2 + bi[i];
    }

    char new_ch;
    if (rev_int >= 0 && rev_int <= 9) {
        new_ch = '0' + rev_int;
    } else {
        new_ch = 'A' + rev_int - 10;
    }
    // cout << "ch:" << ch << " " <<  rev_int << " " << new_ch << endl;
    return new_ch;
}

int main() {
    string s1, s2;
    // cin >> s1 >> s2;
    // s1 = "dec";
    // s2 = "fab";
    // s1 = "ab";
    // s2 = "CD";
    // s1 = "123";
    // s2 = "15";
    s1 = "0123456789";
    s2 = "qwertyuiopasdfghjklzxcvbnm";
    // 1. 合并
    s1 += s2;
    int n = s1.size();
    cout << s1 << endl;
    // 2. 排序
    string even_s, odd_s;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            even_s.push_back(s1[i]);
        } else {
            odd_s.push_back(s1[i]);
        }
    }
    sort(even_s.begin(), even_s.end());
    sort(odd_s.begin(), odd_s.end());
    cout << even_s << endl;
    cout << odd_s << endl;

    // 重新组装
    // 3. 转换
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            // cout << even_s[i/2] << endl;
            s1[i] = trans_ch(even_s[i / 2]);
        } else {
            // cout << odd_s[i/2] << endl;
            s1[i] = trans_ch(odd_s[i / 2]);
        }
    }
    cout << s1 << endl;
}
// 64 位输出请用 printf("%lld")