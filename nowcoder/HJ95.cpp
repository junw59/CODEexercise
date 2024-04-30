#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> ones = {"零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖",};
vector<string> tens = {"", "拾", "佰", "仟",};
vector<string> wans = {"", "万", "亿", "万亿",};


string tran_4(string num) {
    int n = num.size();
    string ans = "";
    int curr = n - 1;
    while (num[curr] == '0') {
        --curr;
    }
    int zeros = false;
    while (curr >= 0) {
        // if (num[curr])
        if (curr == n - 2 && num[curr] == '1') {
            ans = tens[1] + ans;
        } else {
            ans = ones[ num[curr] - '0' ] + tens[ n - 1 - curr ] + ans;
        }
        --curr;
    }
    // cout << num << ans << endl;
    return ans;
}


string trans_chinese(double money) {
    string ans = "";
    int dec = (int)(money * 100+0.5) % 100;
    if (dec == 0) {
        ans = "整";
    } else {
        if (dec / 10 != 0) {
            ans += ones[dec / 10] + "角";
        }
        if (dec % 10 != 0) {
            ans += ones[dec % 10] + "分";
        }
    }
    int forward = (int)(money * 100) / 100;
    int idx = 0;
    while (forward) {
        if(idx==0){
            ans = "元" + ans;
        }
        ans = tran_4(to_string(forward % 10000)) + wans[idx++] + ans;
        forward /= 10000;
    }


    // string dec = to_string((int)(money*100)%100);
    // string forward = to_string((int)(money*100)/100);
    return ans;
}

int main() {
    system("chcp 65001"); // 将命令行编码切换到 UTF-8

    // cout << "hello 你好" << endl;
    double money;
    while (cin >> money) {
        cout << "人民币" << trans_chinese(money) << endl;
    }
}
// 64 位输出请用 printf("%lld")