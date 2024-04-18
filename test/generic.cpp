#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

template <typename T>
void display_s(const vector <T> &vec, T msg){
    cout << msg << endl;
    for(int i=0; i < vec.size(); ++i){
        T t = vec[i];
        cout << "next:" << t << endl;
    }
}

template<typename RT, typename T1, typename T2>      //RT变为第一个模板参数
RT max_2(T1 a, T2 b){
    return a>b? a:b;
}

// // 使用模板函数，可以使其适用于更多不同类型的对象和容器
// template <typename IterType, typename ElemType>
// IterType find(IterType first, IterType last, const ElemType &val){
//     for(; first!=last; ++first){
//         if( *first == val ){
//             return first;
//         }
//     }

//     return last;
// }


// 泛型算法
vector<int> filter_ver(const vector<int> &vec, int filter_val, bool (*pred) (int,int)){
    // 利用函数指针，给出满足条件的new vec
    vector <int> nec;
    for(int ix=0; ix<vec.size(); ++ix){
        if(pred(vec[ix],filter_val)){
            nec.push_back(vec[ix]);
        }
    }
    return nec;
}

bool less_f(int x1, int x2){
    return x1<x2;
}

vector<int> filter_ver_2(const vector<int> &vec, int val, less<int> lt ){
    // 利用函数指针，给出满足条件的new vec
    vector <int> nec;
    vector<int> :: const_iterator iter = vec.begin();
    
    while((iter = find_if(iter, vec.end(), bind2nd(lt,val) )) != vec.end()){
        nec.push_back(*iter);
        ++iter;
    }
    return nec;
}

template < typename inIter, typename outIter, typename eleT, typename comp >
outIter filter_ver_3(inIter first, inIter last, outIter at, const eleT &val, comp pred ){
    // 利用函数指针，给出满足条件的new vec
    while((first = find_if(first, last, bind2nd(pred,val) )) != last){
        *at++ = *first++;
    }
    return at;
}




int main(){
    cout << "hello world!" << endl;
    // vector <int> vec={1,2,3,4,5};
    // display_s(vec, 12.0);
    // cout << max_2<double,int, double>(4, 7.2) << endl;
    // cout << max_2<double>(4, 7.2) << endl;
    // cout << max_2<int>(4, 7.2) << endl;

    int arr[5] = {1,2,3,4,5};
    int * it;
    it = find(arr, arr+5,3);
    if(it!=arr+5){
        cout << "find array:" << *it << endl;
    }

    list <int> vec_li={arr,arr+5};
    list <int> ::iterator iter_li;
    iter_li = find(vec_li.begin(), vec_li.end(),3);
    if(iter_li!=vec_li.end()){
        cout << "find list:" << *iter_li << endl;
    }
    cout << *(++vec_li.begin()) << endl;

    vector <string> vec_str={"1:","2:","3:","4:","5."};
    vector<string> ::iterator iter_str;
    iter_str = find(vec_str.begin(), vec_str.end(),vec_str[3]);
    if(iter_str!=vec_str.end()){
        cout << "find string:" << *iter_str << endl;
    }

    iter_str=vec_str.begin();
    cout << iter_str->size() << endl;

    vector <int> vec={1,2,3,4,5};
    vector<int> ::iterator iter;
    iter = find(vec.begin(), vec.end(),3);
    if(iter!=vec.end()){
        cout << "find vector:" << *iter << endl;
    }
    for(auto x:vec){ cout << x << ","; } cout << endl;

    cout << "filter:" << endl;
    vector <int> nec=filter_ver(vec,2,less_f);
    for(auto x:nec){ cout << x << ","; } cout << endl;

    cout << "filter 2:" << endl;
    nec=filter_ver_2(vec,2, less<int>());
    for(auto x:nec){ cout << x << ","; } cout << endl;

    cout << "filter 3:" << endl;
    vector<int> nec2(5);
    filter_ver_3(vec.begin(), vec.end(), nec2.begin(), 2, greater<int>());
    for(auto x:nec2){ cout << x << ","; } cout << endl;

}
