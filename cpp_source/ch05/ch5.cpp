//
// Created by cer on 17-9-18.
// chapter 5
// 语句

#include <iostream>
#include <vector>
using namespace std;

int divide(int a, int b){
    if (b == 0){
        // 抛出异常
        throw runtime_error("b cannot be 0!");
    }
    else{
        return a / b;
    }
}

int main(){
    int a = 1, b = 0, res;
    try{
        res = divide(a, b);
        cout << res << endl;
    }catch(runtime_error err){
        cout << err.what() << endl;
    }
    return 0;
}


