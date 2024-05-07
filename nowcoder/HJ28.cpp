#include <iostream>
#include <vector>
using namespace std;

bool is_prime(int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

bool find_mat(int idx, vector<bool>& used, vector<int>& mat_even, vector<vector<bool>>& mp) {
    for (int i = 0; i < used.size(); ++i) { // 遍历所有的偶数
        if (mp[i][idx] && !used[i]) {
            // 如果可以配对，而且没有被使用
            used[i] = true;
            if (mat_even[i] == -1 || find_mat(mat_even[i], used, mat_even, mp)) {
                mat_even[i] = idx;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int a, b;
    while (cin >> a) { // 注意 while 处理多个 case
        vector<int> odds;
        vector<int> evens;
        while (a--) {
            cin >> b;
            if (b % 2 == 0) {
                evens.push_back(b);
            } else {
                odds.push_back(b);
            }
        }
        int n1 = evens.size();
        int n2 = odds.size();
        int num_m = 0;
        if (n1 != 0 && n2 != 0) {
            vector<vector<bool>> mp(n1, vector<bool> (n2, false));
            // 先列出可能的组成prime的数对
            for (int i = 0; i < n1; ++i) {
                for (int j = 0; j < n2; ++j) {
                    mp[i][j] = is_prime(evens[i] + odds[j]);
                }
            }

            vector<int> mat_even(n1, -1); // 和每个偶数配对的数
            for (int i = 0; i < n2; ++i) {
                vector<bool> used(n1, false); //被配对过的偶数
                if (find_mat(i, used, mat_even, mp)) {
                    // 如果能找到最佳配对方法
                    ++num_m;
                }
            }
        }
        cout << num_m << endl;
    }
}
// 64 位输出请用 printf("%lld")