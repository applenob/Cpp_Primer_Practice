#include <iostream>
#include "Sales_item.h"

int main(){
    Sales_item item_1;
    Sales_item item_2;
    std::cin >> item_1;
    std::cout << item_1 << std::endl;
    std::cin >> item_2;
    std::cout << item_2 << std::endl;
    std::cout << "sum of sale items:" << item_1 + item_2 << std::endl;
    return 0;
}
