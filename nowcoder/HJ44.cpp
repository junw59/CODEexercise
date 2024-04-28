#include <iostream>
#include <vector>
using namespace std;

bool check_box(vector<vector<int>>& vec2, int row, int col, int aim) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if ( aim == vec2[row / 3 *3 + i][col / 3 *3 + j]) {
                // cout << "exist:" << row / 3 + i << col / 3 + j << endl;
                return true;
            }
        }
    }
    return false;
}

bool check_row(vector<vector<int>>& vec2, int row, int aim) {
    for (int i = 0; i < 9; ++i) {
        if ( aim == vec2[row][i]) {
            // cout << "exist:" << row << i << endl;
            return true;
        }
    }
    return false;
}

bool check_col(vector<vector<int>>& vec2, int col, int aim) {
    for (int i = 0; i < 9; ++i) {
        if ( aim == vec2[i][col]) {
            // cout << "exist:" << i << col << endl;
            return true;
        }
    }
    return false;
}

// bool get_sudo(vector<vector<int>>& vec2, vector<pair<int, int>>& empty_i) {
//     int n = 9;
//     for ( auto item : empty_i) {
//         // cout << "check:" << item.first << item.second << endl;
//         for (int i = 1; i < n+1; ++i) {
//             if (!check_box(vec2, item.first, item.second, i) &&
//                 !check_row(vec2, item.first, i) &&
//                 !check_col(vec2, item.second, i) ) {
//                 vec2[item.first][item.second] = i;
//                 break;
//             }
//         }
//     }
//     return true;
// }


void dfs(vector<vector<int>>& vec2, vector<pair<int, int>>& empty_i, int idx, int n, bool &sol){
    if(idx==n){
        sol=true;
        return ;
    }

    auto item=empty_i[idx];
    for (int i = 1; i < 10; ++i) {
        if (!check_box(vec2, item.first, item.second, i) &&
            !check_row(vec2, item.first, i) &&
            !check_col(vec2, item.second, i) ) {
            vec2[item.first][item.second] = i;
            dfs(vec2,empty_i,idx+1,n,sol);
            if(sol){
                return;
            }
            vec2[item.first][item.second] = 0;
        }
    }
}

bool get_sudo_dfs(vector<vector<int>>& vec2, vector<pair<int, int>>& empty_i) {
    int n =empty_i.size();
    auto item=empty_i[0];
    bool sol =false;
    for (int i = 1; i < 10; ++i) {
        if (!check_box(vec2, item.first, item.second, i) &&
            !check_row(vec2, item.first, i) &&
            !check_col(vec2, item.second, i) ) {
            vec2[item.first][item.second] = i;
            dfs(vec2,empty_i,1,n,sol);
            if (sol){
                return sol;
            }
            vec2[item.first][item.second] = 0;
        }
    }

    return true;
}

int main() {
    int n = 9;
    vector<pair<int, int>> empty_i;
    // vector<vector<int>> vec2(n, vector<int>(n, 0));
    vector<vector<int>> vec2={
    // {0, 9, 2, 4, 8, 1, 7, 6, 3} ,
    // {4, 1, 3, 7, 6, 2, 9, 8, 5} ,
    // {8, 6, 7, 3, 5, 9, 4, 1, 2} ,
    // {6, 2, 4, 1, 9, 5, 3, 7, 8} ,
    // {7, 5, 9, 8, 4, 3, 1, 2, 6} ,
    // {1, 3, 8, 6, 2, 7, 5, 9, 4} ,
    // {2, 7, 1, 5, 3, 8, 6, 4, 9} ,
    // {3, 8, 6, 9, 1, 4, 2, 5, 7} ,
    // {0, 4, 5, 2, 7, 6, 8, 3, 1} ,

    {0, 9, 5, 0, 2, 0, 0, 6, 0} ,
    {0, 0, 7, 1, 0, 3, 9, 0, 2} ,
    {6, 0, 0, 0, 0, 5, 3, 0, 4} ,
    {0, 4, 0, 0, 1, 0, 6, 0, 7} ,
    {5, 0, 0, 2, 0, 7, 0, 0, 9} ,
    {7, 0, 3, 0, 9, 0, 0, 2, 0} ,
    {0, 0, 9, 8, 0, 0, 0, 0, 6} ,
    {8, 0, 6, 3, 0, 2, 1, 0, 5} ,
    {0, 5, 0, 0, 7, 0, 2, 8, 3} ,
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // cin >> vec2[i][j];
            cout << vec2[i][j] << " ";
            if (vec2[i][j] == 0) {
                empty_i.emplace_back(make_pair(i, j));
            }
        }
        cout << endl;
    }

    cout << "solution is:" << endl;
    // get_sudo(vec2, empty_i);
    get_sudo_dfs(vec2, empty_i);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << vec2[i][j] << " ";
        }
        cout << endl;
    }

}
// 64 位输出请用 printf("%lld")