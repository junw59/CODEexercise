#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    // {
    //     string a;
    //     // cin >> a ; // 不能读取空格
    //     // getline(cin,a); // 可以读取空格
    //     // a[1]='f';
    //     // cout << a.length() << a << endl;
    //     // char b[100];
    //     // cin >> noskipws >> b ;
    //     // cin.getline(b,10) ; // 指定读取的字符个数
    //     // cin >> b ;
    //     // gets(b); // string 里的
    //     // cout << b << endl;
    // }


    // {
    //     vector <pair <char,char>> vec;
    //     pair <char,char> ch ={'Z','a'};
    //     cout << ch.first << ch.second << endl;
    //     // vec.push_back(ch);
    //     vec.emplace_back(ch);
    //     cout << ch.first << ch.second << endl;
    //     // vec.push_back(make_pair('z','A'));
    //     // vec.emplace_back(make_pair('z','A'));
    //     // vec.emplace_back(move(make_pair('z','A')));
    // }

    // {
    //     float dec=0.19;
    //     cout << dec*100 << " " << int(dec*100) << " " << floor(dec*100) << " " << int(dec*100)%100 << " " << endl;
    //     double decd=dec;
    //     cout << decd*100 << " " << int(decd*100) << " " << floor(decd*100) << " " << int(decd*100)%100 << " " << endl;
    // }

    {
        vector<float> nums={1.2, 2.5, 3.6, 4.8};
        do{
            for(auto x : nums){
                cout << x << " ";
            }
            cout << endl;
        }while( next_permutation(nums.begin(), nums.end()));
    }
}
