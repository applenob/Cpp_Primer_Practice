//
// Created by cer on 17-9-15.
// chapter 2
// 变量和基本类型

#include <iostream>
#include "../Sales_item.h"

void basic_class(){
    Sales_item book;
    std::cin >> book;
    std::cout << book << std::endl;
}

void q_2_3(){
    unsigned u = 10, u2 = 42;
    std::cout << u2 - u << std::endl;
    std::cout << u - u2 << std::endl;
    int i = 10, i2 = 42;
    std::cout << i2 - i << std::endl;
    std::cout << i - i2 << std::endl;
    std::cout << i - u << std::endl;
    std::cout << u - i << std::endl;
}

int main(){
    q_2_3();
    return 0;
}

