//
// Created by cer on 17-9-15.
// chapter 3
// 标准库类型

#include <iostream>
#include <vector>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::bitset;

void basic_getline(){
    string line;
    while (getline(cin, line))
        cout << line << endl;
}

void basic_string(){
    string s = "Test String.";
    cout << "Size: " << s.size() << endl
         << "Empty: " << s.empty() << endl
         << "char at index 0:" << s[0] << endl;
    for(string::size_type i=0; i<s.size(); i++){
        cout << s[i];
    }
    cout << endl;
}

void basic_vector(){
    vector<int> v;
    for (int i = 0; i != 10; i++){
        v.push_back(i);
    }
    for (vector<int>::iterator iter = v.begin();
         iter != v.end(); ++iter){
        *iter = 0;
    }
    // 不能直接输出vector
}

void basic_bieset(){
    bitset<16> bitvec1(0xffff);
    string bit_str = "1100";
    bitset<32> bitvec2(bit_str); //从右到左读取字符串，只能是string对象，不能是字面值
    bitset<16> bitvec3(bit_str, 0, 3); // 只要前三位
    cout << bitvec1 << endl
         << bitvec2 << endl
         << bitvec3 << endl
         << bitvec2.test(3) <<" " <<bitvec2.test(3) << endl
         << bitvec2.to_ulong() << endl;
}

int main(){
//    basic_getline();
//    basic_string();
    basic_bieset();
}