//
// Created by cer on 17-9-20.
// chapter 09
//
#include <iostream>
#include <vector>
#include <list>
#include <deque>

using namespace std;

void test_copy(){
    vector<int> v1(10, 1);
    //直接复制
    vector<int> v2(v1);
    //使用迭代器复制
    list<double> l1(v1.begin(), v1.end());
    deque<int> d1(l1.begin(), l1.end());
}

bool is_same(vector<int> v, list<int> l){
    vector<int>::iterator iter_v = v.begin();
    list<int>::iterator iter_l = l.begin();
    while (true){
//        cout << *iter_v << *iter_l << endl;
        if (iter_v == v.end() && iter_l == l.end()){
            return true;
        }
        if (iter_v == v.end() && iter_l != l.end()){
            return false;
        }
        if (*iter_v != *iter_l){
            return false;
        }
        ++iter_v;
        ++iter_l;
    }
}

void test_is_same(){
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v(a, a+10);
    list<int> l(a, a+10);
    cout << is_same(v, l) << endl;
}

int main(){
//    test_copy();
    test_is_same();
    return 0;
}

