//
// Created by cer
// chapter 1
// 开始

#include <iostream>
#include "Sales_item.h"

void basic_io(){
    std::cout << "Enter two numbers:" << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    std::cout << "The sum of " << v1 << " and " << v2
              << " is " << v1 + v2 << std::endl;
}

void basic_while(){
    int sum = 0, val = 1;
    while (val <= 10){
        sum += val;
        ++val;
    }
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
}

void basic_for(){
    int sum = 0;
    for (int val = 1; val <= 10; ++val){
        sum += val;
    }
    std::cout << "Sum of 1 to 10 inclusive is "
              << sum << std::endl;
}

void basic_if(){
    std::cout << "Enter two numbers:" << std::endl;
    int v1, v2;
    std::cin >> v1 >> v2;
    int lower, upper;
    if (v1<=v2){
        lower = v1;
        upper = v2;
    } else {
        lower = v2;
        upper = v1;
    }
    int sum = 0;
    for (int val = lower; val <= upper; ++val)
        sum += val;
    std::cout << "Sum of " << lower
              << " to " << upper
              << " inclusive is "
              << sum << std::endl;
}

void basic_cin(){
    int sum = 0, value;
    while (std::cin >> value)
        sum += value;
    std::cout << "Sum is: " << sum << std::endl;
}

void q_1_3(){
    std::cout << "Hello, World" << std::endl;
}

void q_1_4(){
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << std::endl;
}

void q_1_5(){
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 * v2;
    std::cout << std::endl;
}

void q_1_9(){
    int sum = 0, val = 50;
    while (val <= 100){
        sum += val;
        val += 1;
    }
    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;
}

void q_1_10(){
    int val = 10;
    while (val >= 0){
        std::cout << val << " ";
        val -= 1;
    }
    std::cout << std::endl;
}

void q_1_11(){
    int start = 0, end = 0;
    std::cout << "Please input two num: ";
    std::cin >> start >> end;
    if (start <= end) {
        while (start <= end){
            std::cout << start << " ";
            ++start;
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "start should be smaller than end !!!";
    }
}

void q_1_16(){
    int sum = 0;
    for (int value = 0; std::cin >> value; )
        sum += value;
    std::cout << sum << std::endl;
}

void count_num(){
    // 统计输入中每个值连续出现了多少次
    int currVal = 0, val = 0;
    if (std::cin >> currVal){
        int cnt = 1;
        while (std::cin >> val){
            if (val == currVal)
                ++cnt;
            else {
                std::cout << currVal << " occurs "
                          << cnt << " times " << std::endl;
                currVal = val;
                cnt = 1;
            }
        }
        std::cout << currVal << " occurs "
                  << cnt << " times " << std::endl;
    }
}

void q_1_20(){
    for (Sales_item item; std::cin >> item; std::cout << item << std::endl);
}

void q_1_21(){
    Sales_item item_1;
    Sales_item item_2;
    std::cin >> item_1;
    std::cout << item_1 << std::endl;
    std::cin >> item_2;
    std::cout << item_2 << std::endl;
    std::cout << "sum of sale items: " << item_1 + item_2 << std::endl;
}

void q_1_22(){
    Sales_item sum_item;
    std::cin >> sum_item;
    std::cout << sum_item << std::endl;
    for (Sales_item item; std::cin >> item; std::cout << item << std::endl){
        sum_item += item;
    }
    std::cout << "sum of sale items: " << sum_item << std::endl;
}

void q_1_23(){
    Sales_item total;
    if (std::cin >> total){
        Sales_item trans;
        while (std::cin >> trans){
            if (total.isbn() == trans.isbn()) {
                total += trans;
            }
            else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return;
    }
}

int main() {
//    basic_io();
//    basic_while();
//    basic_for();
//    basic_if();
//    basic_cin();
//    q_1_3();
//    q_1_4();
//    q_1_5();
// /* 正常注释 /* 嵌套注释 */ 正常注释*/
//    std::cout << /* "*/" /* "/*" */;
//    q_1_9();
//    q_1_10();
//    q_1_11();
//    q_1_16();
//    count_num();
//    q_1_20();
//    q_1_21();
//    q_1_22();
    q_1_23();
    return 0;
}