#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;


int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        // b=0 是降序， b=1 是升序
        if(b==0){
            priority_queue<pair<int,string>, vector<pair<int,string>>, less<pair<int,string>> > que;
            int score;
            string name;
            while(a--){
                cin>> name >> score;
                que.emplace(score, name);
            }

            while(!que.empty()){
                auto x = que.top();
                que.pop();
                cout << x.second << " " << x.first << endl;
            }
        }
    }
}
// 64 位输出请用 printf("%lld")