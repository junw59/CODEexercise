#include <iostream>

int main() {
    int x = 10;
    int y = 20;

    // 定义一个 Lambda 表达式，它捕获了 x 和 y 并通过引用
    auto lambda = [&x, &y]() {
        // 在这里，x 和 y 可以通过引用被访问和修改
        x += 1;
        y -= 1;
        std::cout << "x is now " << x << " and y is now " << y << std::endl;
    };

    // 调用 Lambda 表达式
    lambda();
    std::cout << "x is now " << x << " and y is now " << y << std::endl;


    auto lambda2 = [](int x, int y) {
        // 在这里，x 和 y 可以通过copy被访问和修改，但是不会改变外部变量
        x += 1;
        y -= 1;
        std::cout << "x is now " << x << " and y is now " << y << std::endl;
    };

    // 调用 Lambda 表达式
    lambda2(x,y);
    std::cout << "x is now " << x << " and y is now " << y << std::endl;

    auto lambda3 =[&](){
        // 可以直接通过引用访问外部变量
        x+=1;
        y+=1;
        std::cout << "x is now " << x << " and y is now " << y << std::endl;
    };
    // 调用 Lambda 表达式
    lambda3();
    std::cout << "x is now " << x << " and y is now " << y << std::endl;

    return 0;
}