#include <iostream>
#include <vector>
#include <initializer_list>

struct X {
    X() { std::cout << "X()" << std::endl; }
    X(const X&) { std::cout << "X(const X&)" << std::endl; }
    X& operator=(const X&) { std::cout << "X& operator=(const X&)" << std::endl; return *this; }
    ~X() { std::cout << "~X()" << std::endl; }
};

void f(const X &rx, X x)
{
    std::cout << "code: std::vector<X> vec;" << std::endl;
    std::vector<X> vec;
    std::cout << "code: vec.reserve(2);" << std::endl;
    vec.reserve(2);
    std::cout << "code: vec.push_back(rx);" << std::endl;
    vec.push_back(rx);
    std::cout << "code: vec.push_back(x);" << std::endl;
    vec.push_back(x);
}

int main()
{
    std::cout << "code: X *px = new X;" << std::endl;    
    X *px = new X;
    std::cout << "code: f(*px, *px);" << std::endl;
    f(*px, *px);
    std::cout << "code: delete px;" << std::endl;
    delete px;

    return 0;
}