#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(){
    map<string, int> word_count;
    string tmp;
    while (cin >> tmp){
        word_count[tmp] += 1;
    }
    for (const auto& elem : word_count)
		std::cout << elem.first << " : " << elem.second << endl;
	return 0;
}