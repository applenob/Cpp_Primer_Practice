//
// Created by cer on 17-9-18.
// chapter 5
// 表达式

#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> ivec;
    int cnt = 10;
    while (cnt > 0){
        ivec.push_back(cnt--);
    }
    vector<int>::iterator iter = ivec.begin();
    // prints 10, 9, 8, 7 ... 1
    while (iter != ivec.end()){
        cout << *iter++ << endl;
    }
}

