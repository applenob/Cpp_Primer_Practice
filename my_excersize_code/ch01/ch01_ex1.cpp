#include <iostream>
#include "Sales_item.h"

int main(){
    for(Sales_item item; std::cin >> item; std::cout << item << std::endl);
    return 0;
}
