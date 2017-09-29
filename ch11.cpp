//
// Created by cer on 17-9-26.
// chapter 11
// 泛型算法

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

void basic_find(){
    // 初始化vector，list和array
    vector<int> vec;
    for (int i=0; i!=10; i++){
        vec.push_back(i);
    }
    list<int> l;
    for (int i=0; i!=10; i++){
        l.push_back(i);
    }
    int ia[10] = {1,2,3,4,5,6,7,8,9,10};

    int search_value = 7;
    vector<int>::const_iterator result =
            find(vec.begin(), vec.end(), search_value);
    cout << "The value: " << search_value
         << (result == vec.end()? " is not present": " is present")
         << "in the vector." << endl;
    list<int>::const_iterator result2 =
            find(l.begin(), l.end(), search_value);
    cout << "The value: " << search_value
         << (result2 == l.end()? " is not present": " is present")
         << "in the list." << endl;
    int *result3 = find(ia, ia+10, search_value);
    cout << "The value: " << search_value
         << (result3 == ia+10? " is not present": " is present")
         << "in the array." << endl;
}

void basic_count(){
    vector<string> vec;
    string word;
    while (cin >> word){
        vec.push_back(word);
    }
    string target = "a";
    int res = count(vec.begin(), vec.end(), target);
    cout << "target string \"a\" appears " << res
         << " times." << endl;
}

void basic_find_first_of(){
    vector<int> vec;
    for (int i=0; i!=10; i++){
        vec.push_back(i);
    }
    list<int> l;
    for (int i=8; i!=19; i++){
        l.push_back(i);
    }
    int count = 0;
    vector<int>::iterator it = vec.begin();
    while ((it = find_first_of(it, vec.end(),l.begin(),l.end()))
           !=vec.end()){
        count++;
        it++;
    }
    cout << "Found " << count
         << " vals on both containers." << endl;
}

int main(){
//    basic_find();
//    basic_count();
    basic_find_first_of();
    return 0;
}

