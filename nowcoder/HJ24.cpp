#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void cal_inc(vector<int> &increa_n, vector<int> &height){
    for (int i=1; i <height.size(); ++i){
        for(int j =i-1; j>=0; --j){
            if(height[i]>height[j]){
                increa_n[i]=max(increa_n[i], increa_n[j]+1);
            }
        }
    }
}

void cal_dec(vector<int> &decrea_n, vector<int> &height){
    int n =height.size();
    for (int i=n-1; i >0; --i){
        for(int j =i+1; j<n; ++j){
            if(height[i]>height[j]){
                decrea_n[i]=max(decrea_n[i], decrea_n[j]+1);
            }
        }
    }
}


int main() {
    int n;
    while (cin >> n) {
        if(n==-1) break;
        vector<int> height(n);
        vector<int> increa_n(n,1);
        vector<int> decrea_n(n,1);
        int x;
        for(int i=0; i<n; ++i){
            cin >> x;
            height.push_back(x);
            // cout << x << endl;
        }

        // 计算最大上升下降序列
        cal_inc(increa_n, height);
        cal_dec(decrea_n, height);
        for(auto x:increa_n){
            cout << x << " ";
        }
        cout << endl;
        for(auto x:decrea_n){
            cout << x << " ";
        }
        cout << endl;

        int min_out=n;
        for(int i=0; i<n; ++i){
            min_out=min(min_out, n - (increa_n[i]+decrea_n[i]-1) );
        }
        cout << min_out << endl;
    }
}
// 64 位输出请用 printf("%lld")