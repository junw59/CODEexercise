#include <iostream>

using namespace std; 

int main(){
    system("chcp 65001");
    int  var=666;     // 声明int类型变量var
    int * ptr;    // 声明指针变量ptr
    ptr = &var;   // 先使用 & 运算符获取变量var的地址，再把该地址赋值给指针变量ptr
    int ** pptr;  // 声明二级指针变量pptr
    pptr = &ptr;  // 先使用 & 运算符获取变量ptr的地址，再把该地址赋值给二级指针变量pptr
    int & ref1 = var;   // 声明引用变量ref1, ref1是变量var的别名(引用必须在创建时被初始化)
    int & ref2 = *ptr;  // 先使用*运算符获取指针变量ptr所指向的变量(即var)，再用该变量(var)初始化引用变量ref2(声明引用变量ref2的同时对它进行初始化)。也就是说，该行代码执行后，ref2也是变量var的别名 var = 20
    cout << "Value of var: "; 
    cout << var << endl; 
    cout << "Value of &var: "; 
    cout << &var << "\t(var的地址)" << endl; 
    cout << endl; 
    cout << "Value of ptr: "; 
    cout << ptr << "\t(等于&var)" << endl; 
    cout << "Value of *ptr: "; 
    cout << *ptr << "\t\t(等于var)" << endl; 
    cout << "Value of &ptr: "; 
    cout << &ptr << "\t(ptr的地址)" << endl; 
    cout << endl; 
    cout << "Value of pptr: "; 
    cout << pptr << "\t(等于&ptr)" << endl; 
    cout << "Value of *pptr: "; 
    cout << *pptr << "\t(等于ptr, 等于&var)" << endl; 
    cout << "Value of **pptr: "; 
    cout << **pptr << "\t\t(等于*ptr, 等于var)" << endl; 
    cout << "Value of &pptr: "; 
    cout << &pptr << "\t(pptr的地址)" << endl; 
    cout << endl; 
    cout << "Value of ref1: "; 
    cout << ref1 << "\t\t(等于var)" << endl; 
    cout << "Value of &ref1: "; 
    cout << &ref1 << "\t(等于&var)" << endl; 
    cout << endl; 
    cout << "Value of ref2: "; 
    cout << ref2 << "\t\t(等于var)" << endl; 
    cout << "Value of &ref2: "; 
    cout << &ref2 << "\t(等于&var)" << endl; 
    return 0; 
}
