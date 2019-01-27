// chapter 08
// 标准IO库

#include <iostream>
#include <unistd.h>
#include <fstream>

using namespace std;

void loading(){
    for (int i = 0; i != 11; i++){
        cout << "loading " << (i * 10) << "%\r" << flush;
        sleep(1);
    }
    cout << "loaded!      " << endl;
}

void file_io(){
    string in_file_name = "test_in_file";
    string out_file_name = "test_out_file";
    ifstream infile(in_file_name.c_str());
    ofstream outfile(out_file_name.c_str());
    if (!infile){
        cerr << "err: unable to open input file: "
             << in_file_name << endl;
    }
    else{
        // 按词读取
//        string word;
//        while(infile >> word) {
//            cout << word << endl;
//        }
        // 按行读取
        string line;
        while(getline(infile,line)){
            cout << line << endl;
            // 按行写入
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();
}

int main(){
    file_io();
    return 0;
}