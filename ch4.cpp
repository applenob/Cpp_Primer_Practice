//
// Created by cer on 17-9-18.
// chapter 4
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;

void basic_array(){
    const size_t array_size = 10;
    int a[array_size];
    for (size_t i=0; i != array_size; ++i){
        a[i] = i;
    }
}

void basic_pointer(){
    string s = "hello world";
    string *sp = &s;
    cout << *sp << endl;
    int ival = 1024;
    int *pi = &ival;
    int **ppi = &pi;
    cout << "The value of ival" << endl
         << "direct value: " << ival << endl
         << "indirect value: " << *pi << endl
         << "doubly indirect value: " << **ppi << endl;
    const double dval1 = 1.11;
    const double dval2 = 2.22;
    const double *cptr = &dval1;
    cout << "The value of const pointer point to: " << *cptr << endl;
    cptr = &dval2;
    cout << "The value of const pointer point to: " << *cptr << endl;
}

int main(){
    basic_pointer();
}



