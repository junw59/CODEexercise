#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<unordered_map>

using namespace std;



int main(){
    unordered_map<int,int> mp;
    mp[0]=0;

    for(auto it=mp.begin(); it!=mp.end(); ++it){
        cout << it->first << " " << it->second << endl;
    }
    
    cout << mp.count(0) << endl;
    cout << mp.count(1) << endl;

}