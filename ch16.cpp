//
// Created by cer on 17-10-2.
// chapter 16
// 模板和泛型编程
#include <iostream>

using namespace std;

template <typename T>
int compare(const T &v1, const T &v2){
    if (v1 < v2){
        return -1;
    }
    if ( v2 < v1){
        return 1;
    }
    return 0;
}

void basic_template(){
    cout << compare(1, 0) << endl;
    string s1 = "hi", s2 = "world";
    cout << compare(s1, s2) << endl;
}

int main(){
    basic_template();
    return 0;
}