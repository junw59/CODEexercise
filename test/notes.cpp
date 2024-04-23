#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

class A {
public:
    int num;
};


class B1: virtual public A {
public:
    void func1();
};

class B2: virtual public A {
public:
    void func2();
};

class C:public B1, public B2 {
public:
    void func3();
};



///////// functional
void hello(int count){
    cout << "function hello " << count << endl;
}

class StaticHello{
public :
    static void hello(int count){
        cout << "class StaticHello::hello " << count << endl;
    }
};

class Hello{
public :
    void operator() (int count){
        i+=count;
        cout << "class Hello::() i: " << i << endl;
    }
    void operator() (int a, int b){
        cout << "class Hello::() a+b: " << a+b << endl;
    }
    void hello(int count){
        cout << "class Hello::hello " << count << endl;
    }
    int i =0;
};

////// lambda 的实现
class LambdaHello{
public:
    LambdaHello(int i): _i(i) {}
    void operator() (int count) {
        ++_i;
        cout << "class lambda hello " << count << " i=" << _i << endl;
    }
private:
    int _i;
};


/////// bind 的实现
class BindHello{
public:
    BindHello(function<void(int)> _fn, int _count): fn(_fn), count(_count){};
    void operator()(){
        fn(count);
    }
private:
    function<void(int)> fn;
    int count;
};

class BindChello{
public:
    typedef void (Hello::*Fn)(int);
    BindChello(Fn _fn, Hello *_c): fn(_fn), c(_c){};
    void operator() (int count){
        (c->*fn)(count);
    }
private:
    Fn fn;
    Hello *c;
};

int main() {
    {
        C c{};
        c.B1::num=1;
        c.B2::num=2;
        cout << " c.B2::num "<< c.B1::num << " c.B2::num "<< c.B2::num << endl;
    }

    {
        int a= 1;
        double b=2.0;
        decltype(a+b) c = a+b;
        cout << "a+b=" << c << typeid(c).name() << endl;

        auto f = [](int a, double b){
            return a+b;
        };
        decltype(f(a,b)) d= b;
        cout << "d=" << d << typeid(d).name() << endl;

        decltype(a+=b) e=a;
        e=190;
        cout << "a=" << a << endl;
    }

    {
        // function 类模板的使用
        function<void (int)> func1=hello;
        func1(1);
        function<void (int)> func2=&StaticHello::hello;
        func2(2);

        // 仿函数
        function<void(int)> func3=Hello();
        func3(3);
        func3(6);
        function<void(int,int)> func4=Hello();
        func4(3,5);

        // 保存成员函数
        function<void(Hello*,int)> func5= &Hello::hello;
        Hello h;
        func5(&h,5);


        int i=0;
        // 值捕获，mutable可读可写但是不修改外部变量
        auto func7=[i](int count) mutable ->void{
            ++i;
            cout << "lambda hello " << count << " i=" << i << endl;
        };
        func7(9);
        func7(2);
        cout << "i= " << i << endl;

        // 引用捕获，可以修改外部变量
        auto func8=[&i](int count)->void{
            ++i;
            cout << "lambda hello " << count << " i=" << i << endl;
        };
        func8(9);
        func8(2);
        cout << "i= " << i << endl;
        func7(12);

        auto func9 = LambdaHello(i);
        func9(9);


        auto func10=bind(&hello,100);
        func10();
        auto func11=bind(&Hello::hello,&h,101);
        func11();
        auto func12=bind(&Hello::hello,&h,placeholders::_1);
        func12(102);

        auto func13=BindHello(&hello,100);
        func13();
        auto func14=BindChello(&Hello::hello,&h);
        func14(102);
    }
}


