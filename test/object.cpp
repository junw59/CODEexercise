#include <stdio.h>
#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;


// 定义其迭代器
class Triangular_iterator{
private:
    int _index;
public:
    // 想要的是第n个，但是在数组中的下标是n-1
    Triangular_iterator(int index):_index(index-1){}
    // 注意const的含义
    bool operator==(const Triangular_iterator&) const;
    bool operator!=(const Triangular_iterator&) const;
    // int operator*() const;
    // int operator*();
    Triangular_iterator & operator++(); // prefix 前置版本
    Triangular_iterator operator++(int); // postfix 后置版本
    int index() const;


    friend int operator*( const Triangular_iterator &rhs);

};


class Triangular{
private:
    int _length;
    int _beg_pos;
    mutable int _next;
public:
// 放在public的才能随意访问，而放在private的只能在类里面访问
    static vector<int> _elems;
    static int get_elem(int pos);
    Triangular();
    Triangular(int len);
    Triangular(int len, int beg_pos);
    ~Triangular();

    int elem(int pos) const;
    void gen_elem(int pos);
    void display(ostream &out);

    // friend 使得这个函数可以访问类中的元素
    // 下面这俩只能要一个
    friend int operator*( const Triangular_iterator &rhs);
    // friend int Triangular_iterator::operator*() const;

    // 只有先行定义了 Triangular_iterator 才能继续使用
    typedef Triangular_iterator iterator;
    Triangular_iterator begin() const{
        return Triangular_iterator(_beg_pos);
    }
    Triangular_iterator end() const{
        return Triangular_iterator(_beg_pos+_length);
    }
};

// 静态成员需要在程序代码中提供
vector<int> Triangular::_elems;

Triangular::Triangular(){
    _length=1;
    _beg_pos=1;
    _next=0;
    _elems=vector<int>();
    gen_elem(_beg_pos+_length-1);
}

Triangular::Triangular(int len):_length(len), _beg_pos(1) {
    gen_elem(_beg_pos+_length-1);
}
Triangular::Triangular(int len, int beg_pos):_length(len),_beg_pos(beg_pos) {
    gen_elem(_beg_pos+_length-1);
}
Triangular::~Triangular(){};

int Triangular::elem(int pos) const{
    return _elems[pos-1];
}

int Triangular::get_elem(int pos){
    return _elems[pos-1];
}

void Triangular::gen_elem(int pos) {
    int n =_elems.size();
    for(; n < pos; ++n){
        if(n==0){
            _elems.push_back(1);
        } else {
            _elems.push_back((n+2)*(n+1)/2 );
        }
    }
}

void Triangular::display(ostream &out){
    for(auto x: _elems){
        out << x << " ";
    }
    out << endl;
}




// 定义迭代对象

inline int Triangular_iterator::index() const{
    return _index;
}

inline bool Triangular_iterator::operator==(const Triangular_iterator& rhs) const{
    return _index == rhs._index;
}

inline bool Triangular_iterator::operator!=(const Triangular_iterator& rhs) const{
    return !( *this== rhs);
}

inline  Triangular_iterator& Triangular_iterator::operator++(){
    // 前置的++，返回的是递增后的指针
    ++_index;
    return *this;
}


inline  Triangular_iterator Triangular_iterator::operator++(int){
    // 后置的++，返回的是原来的指针,所以需要一个中间变量
    Triangular_iterator temp = *this;
    ++_index;
    return temp;
}



// // 成员函数的形式
// inline int Triangular_iterator::operator*() const{
//     // return _index;
//     return Triangular::_elems[_index];
// }

// 非成员函数的形式
inline int operator*( const Triangular_iterator &rhs){
    // return rhs.index();
    return Triangular::_elems[rhs.index()];
}


//// function call
//// function object 通常是作为参数传递给泛型算法
class LessThan{
private:
    int _val;
public:
    LessThan (int val) : _val(val){}
    int com_val() {return _val;}
    void com_val(int n_val) {_val=n_val;}

    // 重载了括号运算符() ?
    bool operator() (int _value) const;
};

inline bool LessThan::operator() (int _value) const{
    return _value < _val;
}

void print_less(const vector<int> &vec, int comp, ostream &out=cout){
    LessThan lt(comp);
    vector<int>::const_iterator it=vec.begin();
    vector<int>::const_iterator it_end=vec.end();

    out << "less than " << comp << " are: ";
    while((it=find_if(it,it_end,lt))!=it_end){
        out << *it << " ";
        ++it;
    }
}



class num_sequence{
public:
    // 重新命名的函数指针变量
    typedef void (num_sequence:: *PtrType) (int);
    // 枚举类型 enum
    enum ns_type{
        ns_unset, ns_fibonacci, ns_triangular
    };
    // 函数检查数值是否是合理数列序号
    static ns_type nstype(int num){
        // cout << static_cast <ns_type > (num) << endl;
        return num <= 0 || num>=num_seq? ns_unset : static_cast <ns_type > (num);
    }

    void fibonacci (int);
    void triangular (int);
    int elem(int);

    num_sequence(){}
    ~num_sequence(){}
    int num_of_seq(){return num_seq;}
    void set_sequence(ns_type nst){
        switch (nst){
        default:
            cout << "invalid type setting to 0\n";
            // break;
        case ns_unset:
            _pmf=0;
            _elem=0;
            _isa = ns_unset;
            break;
        case ns_fibonacci:
        case ns_triangular:
            _pmf=func_tbl[nst];
            _elem= &seq[nst];
            _isa = nst;
            break;
        }
    }

    const string what_am_i() const {
        static vector<string> names ={
            "not Set", "fibonacci", "triangular"
        };
        return names[_isa];
    }

private:
    PtrType _pmf;
    vector<int> * _elem;
    ns_type _isa;
    static const int num_seq=3;
    static vector<vector<int>> seq;
    static PtrType func_tbl[num_seq];
};


void num_sequence::fibonacci (int pos){
    int size = seq[_isa].size();
    for(int n = size; n<pos; ++n){
        if (n<2){
            seq[_isa].push_back(1);
        }else {
            seq[_isa].push_back(seq[_isa][n-2]+seq[_isa][n-1]);
        }
    }
}

void num_sequence::triangular (int pos){
    int size = seq[_isa].size();
    for(int n =size; n<pos; ++n){
        seq[_isa].push_back( (n+1)*(n+2)/2);
    }
}

// 静态的局部成员变量，需要在函数外声明，
const int num_sequence::num_seq;
vector<vector<int>> num_sequence::seq (num_seq);
num_sequence::PtrType num_sequence::func_tbl[num_seq]={
    0,
    & num_sequence::fibonacci,
    & num_sequence::triangular
};

int num_sequence::elem(int pos) {
    if(pos > _elem->size()){
        (this->*_pmf)(pos);
    }
    return (*_elem)[pos-1];
}

inline void display(ostream &out, num_sequence &ns, int pos){
    out << "The element at position "
        << pos << " for the " 
        << ns.what_am_i() << " seq is "
        << ns.elem(pos) << endl;
    return ;
}


int main(){
    cout << "hello world!" << endl;
    Triangular entity(20);
    entity.display(cout);
    // cout<< entity.elem(9) <<endl;

    // // 对于静态成员函数，可以这样用：
    // cout<< Triangular::get_elem(3) <<endl;
    // cout<< Triangular::_elems[0] << endl;

    // Triangular::iterator it = entity.begin();
    // Triangular::iterator end_it = entity.end();
    // cout << it.index() << endl;
    // while(it!=end_it){
    //     // cout << it.index() << " ";
    //     cout << *it << ", ";
    //     ++it;
    // }
    // cout << " iterator end\n";


    // vector<int> vec={1,3,6,10,15,21,28,36,45,55,66,78};
    // int comp=20;
    // print_less(vec,comp,cout);


    // PtrType pm;

    num_sequence ns;
    const int pos=8;
    for(int ix=1; ix<ns.num_of_seq(); ++ix){
        ns.set_sequence( num_sequence:: nstype(ix) );
        int elem_val = ns.elem(pos);
        cout << elem_val << endl;
        display(cout, ns, pos);
    }

}
