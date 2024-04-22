#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <stdio.h>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

// 抽象基类 LibMat
class LibMat {
private:
    ;
public:
    LibMat();
    virtual ~LibMat();

    // 为了多态的支持，选择了virtual虚函数
    virtual void print_object() const {
        cout << "LibMat::print_object() LibMat object!\n";
    }
};

LibMat::LibMat() {
    cout << "LibMat::LibMat() default constructor!\n";
}
LibMat::~LibMat() {
    cout << "LibMat::~LibMat() default deconstructor!\n";
}


void print_object(const LibMat & mat){
    cout << " in global print_object()! \n";
    mat.print_object();
}



// 基类 LibMat 的派生类 Book 的定义
class Book : public LibMat {
public:
    Book(const string &title, const string &author);
    virtual ~Book();

    virtual void print_object() const {
        cout << "Book::print_object() " << _title << " by " << _author << " Book object!\n";
    }

    const string & title() const { return _title;}
    const string & author() const { return _author;}
protected:
    string _title;
    string _author;
};

Book::Book(const string &title, const string &author) : _title(title), _author(author) {
    cout << "Book::Book( " << _title << " by " << _author << ") default constructor!\n";
}

Book::~Book() {
    cout << "Book::~Book() default deconstructor!\n";
}


// 类 Book 的派生类 AudioBook 的定义
class AudioBook : public Book {
public:
    AudioBook(const string &title, const string &author, const string &narrator);
    virtual ~AudioBook();

    virtual void print_object() const {
        cout << "AudioBook::print_object() " << _title << " by " << _author << " and " << _narrator << " AudioBook object!\n";
    }

    const string & title() const { return _title;}
    const string & author() const { return _author;}
protected:
    string _narrator;
};

AudioBook::AudioBook(const string &title, const string &author, const string &narrator) : Book(title, author), _narrator(narrator) {
    cout << "AudioBook::AudioBook( " << _title << " by " << _author << " and " << _narrator << ") default constructor!\n";
}

AudioBook::~AudioBook() {
    cout << "AudioBook::~AudioBook() default deconstructor!\n";
}


void print_class(LibMat object, const LibMat *pointer, const LibMat &reference){
    object.print_object();
    pointer->print_object();
    reference.print_object();
    return ;
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

// 基类
class num_sequence {
public:
    // num_sequence();
    num_sequence(int len, int beg_pos, vector<int> & re) : _length(len), _beg_pos(beg_pos), _relems(re)  {}
    virtual ~num_sequence();


    // 纯虚函数
    int elem(int pos) const;
    virtual const char * what_am_i() const =0;
    ostream & print_ob(ostream & out = cout) const ;
    static int max_elems(){return _max_elem;}
    int length() const { return _length;}
    int beg_pos() const { return _beg_pos;}
protected:
    virtual void gen_elems(int pos) const =0;
    bool check_integrity(int pos, int size) const;
    const static int _max_elem=1024;

    int _length;
    int _beg_pos;
    // 这是一个应用，需要提供初始值
    vector<int> & _relems;
};

// num_sequence::num_sequence() {}

inline num_sequence::~num_sequence() {}

bool num_sequence::check_integrity(int pos, int size) const {
    if(pos <=0 || pos > _max_elem){
        cerr << "!! invalid position: " << pos << endl;
        return false;
    }
    if (pos>size){
        gen_elems(pos);
    }

    return true;
}


int num_sequence::elem(int pos) const {
    if (!check_integrity(pos,_relems.size())) {
        return 0;
    }
    return _relems[pos - 1];
}


ostream &num_sequence::print_ob(ostream &out) const {
    int out_pos = _beg_pos - 1;
    int end_pos = out_pos + _length;
    if (!check_integrity(_beg_pos,_relems.size()) || !check_integrity(end_pos,_relems.size())) {
        return out;
    }
    out << this->what_am_i() << ": ( " << _beg_pos << " , " << _length <<" ) " ;
    while (out_pos < end_pos) {
        out << _relems[out_pos++] << " ";
    }
    out << endl;
    return out;
}


ostream & operator << (ostream & out, const num_sequence & ns){
    return ns.print_ob( out );
}


class Fibonacci :public num_sequence {
public:
    Fibonacci(int len = 1, int beg_pos = 1);
    ~Fibonacci();

    // virtual int elem(int pos) const ;
    virtual const char * what_am_i() const {return "Fibonacci";}
    // virtual ostream & print_ob(ostream & out = cout) const ;
protected:
    virtual void gen_elems(int pos) const;
    // int _length;
    // int _beg_pos;
    static vector<int> _elems;
};

vector<int> Fibonacci::_elems;

// Fibonacci::Fibonacci(int len, int beg_pos) : _length(len), _beg_pos(beg_pos) {}
Fibonacci::Fibonacci(int len, int beg_pos) : num_sequence(len, beg_pos, _elems) {}

Fibonacci::~Fibonacci() {}

// int Fibonacci::elem(int pos) const {
//     if (!check_integrity(pos,_elems.size())) {
//         return 0;
//     }
//     return _elems[pos - 1];
// }

void Fibonacci::gen_elems(int pos) const {
    if (_elems.empty()) {
        _elems.push_back(1);
        _elems.push_back(1);
    }
    if (_elems.size() <= pos) {
        for (int ix = _elems.size(); ix <= pos; ++ix) {
            _elems.push_back(_elems[ix - 1] + _elems[ix - 2]);
        }
    }
}

// ostream &Fibonacci::print_ob(ostream &out) const {
//     int out_pos = _beg_pos - 1;
//     int end_pos = out_pos + _length;
//     if (!check_integrity(_beg_pos,_elems.size()) || !check_integrity(end_pos,_elems.size())) {
//         return out;
//     }
//     out << " ( " << _beg_pos << " , " << _length <<" ) " ;
//     while (out_pos < end_pos) {
//         out << _elems[out_pos++] << " ";
//     }
//     return out;
// }


// 另一个派生类
class Triangular :public num_sequence {
public:
    Triangular(int len = 1, int beg_pos = 1);
    ~Triangular();

    // virtual int elem(int pos) const ;
    virtual const char * what_am_i() const {return "Triangular";}
    // virtual ostream & print_ob(ostream & out = cout) const ;
protected:
    virtual void gen_elems(int pos) const;
    // int _length;
    // int _beg_pos;
    static vector<int> _elems;
};

vector<int> Triangular::_elems;

// Triangular::Triangular(int len, int beg_pos) : _length(len), _beg_pos(beg_pos) {}
Triangular::Triangular(int len, int beg_pos) : num_sequence(len, beg_pos, _elems) {}

Triangular::~Triangular() {}

// int Triangular::elem(int pos) const {
//     if (!check_integrity(pos,_elems.size())) {
//         return 0;
//     }
//     return _elems[pos - 1];
// }

void Triangular::gen_elems(int pos) const {
    if (_elems.size() <= pos) {
        for (int ix = _elems.size(); ix <= pos; ++ix) {
            _elems.push_back( (ix+1)*(ix+2)/2 );
        }
    }
}

// ostream &Triangular::print_ob(ostream &out) const {
//     int out_pos = _beg_pos - 1;
//     int end_pos = out_pos + _length;
//     if (!check_integrity(_beg_pos,_elems.size()) || !check_integrity(end_pos,_elems.size())) {
//         return out;
//     }
//     out << " ( " << _beg_pos << " , " << _length <<" ) " ;
//     while (out_pos < end_pos) {
//         out << _elems[out_pos++] << " ";
//     }
//     return out;
// }


void print_seq(const num_sequence *ob2, const num_sequence &ob3){
    ob2->print_ob();
    ob3.print_ob();
    return ;
}



int main() {
    cout << "hello world!" << endl;
    // LibMat lib;
    // print_object(lib);
    // Book book("The Books", "Authors");
    // print_object(book);
    // AudioBook ab("The AudioBook", "Authors", "Narrator");
    // print_object(ab);

    // cout << "print class :\n\n";
    // print_class(lib, &book, ab);

    // cout << "print class with sliced off :\n\n";
    // print_class(ab, &ab, ab);
    // cout << "  " << typeid(ab).name() << endl;;


    Fibonacci fib;
    cout << "fib at 1 for :" << fib <<endl;

    Fibonacci fib2(5,8);
    cout << "fib at 8 for :" << fib2 <<endl;

    Triangular tri;
    cout << "tri at 1 for :" << tri <<endl;

    Triangular tri2(5,1);
    cout << "tri at 1 for :" << tri2 <<endl;


    print_seq(&fib2,tri2);
}
