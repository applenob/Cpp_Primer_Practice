#include <iostream>

int main()
{
    int start = 0, end = 0;
    std::cout << "Please input two num: ";
    std::cin >> start >> end;
    if (start <= end) {
        while (start <= end){
            std::cout << start << " ";
            ++start;
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "start should be smaller than end !!!";
    }
} 
