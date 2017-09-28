//
// Created by cer on 17-9-26.
// chapter 10
// 关联容器
#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <fstream>

using namespace std;

void traverse_map(map<string,int> m){
    map<string,int>::iterator it = m.begin();
    while(it != m.end())
    {
        cout << it->first << " : "
             << it->second << endl;
        it ++;
    }
}

void base_map(){
    map<string, int> word_count;
    string word;
    word_count["count"] = 1;
    // 重复的键，新值会覆盖旧值
    word_count["count"] = 2;
    traverse_map(word_count);
    // 即便没有定义的键，也可不会报错，会自动初始化
    cout << word_count["new_key"] << endl;
}

void test_word_count(){
    map<string, int> word_count;
    string word;
    while (cin >> word) {
        pair<map<string, int>::iterator, bool> ret =
                word_count.insert(make_pair(word, 1));
        if (!ret.second) {
            ++(ret.first->second);
        }
    }
    traverse_map(word_count);
}

void restricted_wc(ifstream &remove_file, map<string, int> &word_count){
    set<string> excluded;
    string remove_word;
    while(remove_file >> remove_word){
        excluded.insert(remove_word);
    }
    string word;
    while (cin >> word){
        if (!excluded.count(word)){
            ++word_count[word];
        }
    }
}

void basic_multimap(){
    multimap<string, int> m;
    m.insert(make_pair("A", 1));
    m.insert(make_pair("A", 2));
    m.insert(make_pair("A", 2));
    int count = m.count("A");
    multimap<string, int>::iterator iter = m.find("A");
    for (int i = 0; i != count; ++i){
        cout << iter->first << " : " << iter->second << endl;
        iter++;
    }

}

int main(){
//    base_map();
//    test_word_count();
    basic_multimap();
    return 0;
}

