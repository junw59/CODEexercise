#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double cal(double a, double b, char c){
    switch (c) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}

bool check_24(vector<double> const &vec, vector<char> const &chs){
    // cout << "check:" << endl;
    if(vec.size()!=4 || chs.size()!=3){
        return false;
    }
    double f = cal(vec[0], vec[1], chs[0]);
    double s = cal(f, vec[2], chs[1]);
    double t = cal(s, vec[3], chs[2]);
    // cout << t << endl;
    if ( abs( t-24 ) < 1e-6 ){
    // if ( cal(s, vec[3], chs[2]) == 24){
        return true;
    }
    return false;
}

bool valid_24(vector<double> &vec, vector<char> &chs){
    sort(vec.begin(),vec.end());
    do{
        for(int i=0; i<4; ++i){
            for(int j=0; j<4; ++j){
                for(int k=0; k<4; ++k){
                    if(check_24(vec,{chs[i],chs[j],chs[k]})){
                        // cout << vec[0] << " " << chs[i] << vec[1] << " " << chs[j] << vec[2] << " " << chs[k] << vec[3] << " " << endl;
                        return true;
                    }
                }
            }
        }
    }while(next_permutation(vec.begin(), vec.end()));
    return false;
}

int main() {
    vector<double> vec(4);
    vector<char> chs= {'+', '-', '*', '/'};
    while (cin >> vec[0] >> vec[1] >> vec[2] >> vec[3]) {
            // cout << "true" << endl;
        if(valid_24(vec, chs)){
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
}

// 64 位输出请用 printf("%lld")