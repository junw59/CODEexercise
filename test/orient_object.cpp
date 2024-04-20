#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <stdio.h>
#include <vector>
#include <string>

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



int main() {
    cout << "hello world!" << endl;
    // LibMat lib;
    // print_object(lib);
    // Book book("The Books", "Authors");
    // print_object(book);
    AudioBook ab("The AudioBook", "Authors", "Narrator");
    print_object(ab);
}
