#include <iostream>
#include <vector>
using namespace std;

vector<string> ones = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
vector<string> tens = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
vector<string> twenties = { "zero", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
vector<string> hundreds = { "hundred", "thousand", "million", "billion" };

string ito_str(int n){
    if (n<=9) {
        return ones[n];
    } else if (n<20){
        return tens[n%10];
    } else if (n<100) {
        return twenties[n/10]+( n%10 ? " " + ones[n%10]: "");
    } else if (n<1000) {
        return ones[n/100] + " " + hundreds[0] + ( n%100 ? " and " + ito_str(n%100): "") ;
    } else {
        return "";
    }
}

string ito_sn(int n){
    if (n<1000){
        return ito_str(n);
    }
    vector<string> ans;
    while (n>0) {
        ans.push_back( ito_str(n%1000) );
        n=n/1000;
    }
    string str_n;
    for(int i= ans.size()-1; i>0; --i){
        // cout << ans[i] << ";";
        if(i!=ans.size()-1){
            str_n += " ";
        }
        str_n += ans[i] + " " + hundreds[i];
    }
    str_n += (ans[0] == ones[0]? "": " "+ ans[0]);
    return str_n;
}

int main() {
    int num=1000;
    // cout << num  << "  "<< ito_sn(num) << endl;
    // num=999;
    // cout << num  << "  "<< ito_sn(num) << endl;
    // num=219;
    // cout << num  << "  "<< ito_sn(num) << endl;
    // num=809;
    // cout << num  << "  "<< ito_sn(num) << endl;
    // num=19;
    // cout << num  << "  "<< ito_sn(num) << endl;
    // num=2;
    // cout << num  << "  "<< ito_sn(num) << endl;
    // num=1902;
    // cout << num  << "  "<< ito_sn(num) << endl;
    // num=9012;
    // cout << num  << "  "<< ito_sn(num) << endl;
    while(cin >> num){
        cout << ito_sn(num) << endl;
    }
}
// 64 位输出请用 printf("%lld")