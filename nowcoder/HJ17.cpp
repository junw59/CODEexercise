#include <iostream>
#include <vector>
using namespace std;

bool check_i(char ch){
    if (ch>='0' && ch<='9'){
        return true;
    }
    return false;
}

void move_with(char ch, int n, int &x, int &y){
    switch(ch){
        case 'A': x-= n;break;
        case 'D': x+= n;break;
        case 'W': y+= n;break;
        case 'S': y-= n;break;
        default: break;
    }
}

int main() {
    string str;
    getline(cin,str);
    vector<string> vec;
    int l=0;
    for (int i=0;i<str.length(); ++i){
        if(str[i]==';'){
            vec.push_back(str.substr(l,i-l));
            l=i+1;
        }
    }
    int x=0,y=0;
    for(auto seg:vec){
        int n=0;
        if(seg.length()==3 && check_i(seg[1]) && check_i(seg[2])){
            n = (seg[1]-'0')*10+(seg[2]-'0');
            move_with(seg[0],n,x,y);
        } else if(seg.length()==2 && check_i(seg[1]) ){
            n = seg[1]-'0';
            move_with(seg[0],n,x,y);
        }else{
            continue;
        }
    }
    cout << x << " " << y << endl;

}
// 64 位输出请用 printf("%lld")