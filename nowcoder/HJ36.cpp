#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    string str_key;
    int len_s;
    // getline(cin, str_key);
    str_key = "nihao";
    len_s=str_key.size();

    string pain_str;
    // getline(cin, pain_str);
    pain_str = "ni";


    unordered_set<char> st;
    vector< pair<char,char> > vec;
    int idx=0;
    for (int i=0; i< len_s; ++i){
        if(st.count(str_key[i])>0){
            continue;
        }else {
            st.insert(str_key[i]);
            vec.emplace_back(make_pair('a'+idx,str_key[i]));
            ++idx;
        }
    }

    for (int i=0; i< 26; ++i){
        if(st.count('a'+i)>0){
            continue;
        }else {
            st.insert('a'+i);
            vec.emplace_back(make_pair('a'+idx,'a'+i));
            ++idx;
        }
    }

    // for(auto x:vec){
    //     cout << x.first << x.second << endl;
    // }

    string new_str;
    for(int i=0; i < pain_str.size(); ++i){
        char ch =pain_str[i]-'a';
        // cout << ch <<vec[ch].first << vec[ch].second << endl ;
        new_str.push_back(vec[ch].second);
    }

    cout << new_str << endl;

}
// 64 位输出请用 printf("%lld")