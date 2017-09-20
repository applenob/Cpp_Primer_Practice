//
// Created by cer on 17-9-19.
// chapter 07
// 函数
#include <iostream>

using namespace std;

// 非引用的实参
int normal_swap(int v1, int v2){
    int temp = v2;
    v2 = v1;
    v1 = temp;
}

// 引用实参
int ref_swap(int &v1, int &v2){
    int temp = v2;
    v2 = v1;
    v1 = temp;
}

void cmp_conf(){
    int a = 1, b = 2;
    cout << "swap前： a: " << a << ", b: " << b << endl;
    normal_swap(a, b);
    cout << "非引用实参调用swap： a: " << a << ", b: " << b << endl;
    ref_swap(a, b);
    cout << "引用实参调用swap： a: " << a << ", b: " << b << endl;
}

size_t count_calls(){
    static size_t ctr = 0;
    return ++ctr;
}

void test_static(){
    for (size_t i = 0; i != 10; ++i){
        cout << count_calls() << endl;
    }
}

int main(){
//    cmp_conf();
    test_static();
    return 0;
}

