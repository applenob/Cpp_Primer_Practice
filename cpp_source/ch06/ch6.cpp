//
// Created by cer on 17-9-19.
// chapter 06
// 函数

#include <iostream>
#include <string>

using namespace std

int fact(int i)
{
    return i > 1 ? i * fact(i - 1) : 1;
}

void interactive_fact()
{
    string const prompt = "Enter a number within [1, 13) :\n";
    string const out_of_range = "Out of range, please try again.\n";
    for (int i; cout << prompt, cin >> i; )
    {
        if (i < 1 || i > 12)
        {
            cout << out_of_range;
            continue;
        }
        cout << fact(i) << endl;
    }
}

bool str_subrange(const string &str1, const string &str2){
    if(str1.size()==str2.size())
        return str1==str2;
    string::size_type size={min(str1.size(),str2.size())};
    string::size_type i=0;
    while(i!=size){
        if(str1[i]!=str2[i])
        return ; //error! no return value!
  }
}

int main()
{
//    interactive_fact();
    str_subrange();
    return 0;
}