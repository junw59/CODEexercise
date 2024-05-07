#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    string s1,s2;
    while (cin >> s1 >> s2) {
    // {s1="123";s2="212";
        stack<char> st1;
        stack<char> st2;
        string ans;
        for(char &x :s1){
            st1.push(x);
        }
        for(char &x :s2){
            st2.push(x);
        }
        int carr=0;
        while (!st1.empty() || !st2.empty()) {
            int add_n=carr;
            if (!st1.empty()){
                add_n+=st1.top()-'0';
                st1.pop();
            }
            if (!st2.empty()){
                add_n+=st2.top()-'0';
                st2.pop();
            }
            carr=add_n/10;
            ans.push_back(add_n%10+'0');
        }
        if(carr>0){
            ans.push_back(carr%10+'0');
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
}
// 64 位输出请用 printf("%lld")