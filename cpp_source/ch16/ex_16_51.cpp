#include <iostream>

using namespace std;

template <typename T, typename ... Args>
void foo(const T &t, const Args& ... rest){
    cout << "sizeof...(Args): " << sizeof...(Args) << endl;
    cout << "sizeof...(rest): " << sizeof...(rest) << endl;
};

void test_param_packet(){
    int i = 0;
    double d = 3.14;
    string s = "how now brown cow";

    foo(i, s, 42, d);
    foo(s, 42, "hi");
    foo(d, s);
    foo("hi");
}

int main(){
    test_param_packet();
    return 0;
}