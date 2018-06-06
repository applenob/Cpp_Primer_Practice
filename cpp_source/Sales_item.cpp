//
// Created by cer on 17-9-15.
//

#include <iostream>
#include "Sales_item.h"

using namespace std;

class Sales_item{
public:
    double avg_price() const;
    bool same_isbn(const Sales_item &rhs) const{
        return isbn == rhs.isbn;
    }
    Sales_item(): units_sold(0), revenue(0.0) {}
private:
    string isbn;
    unsigned units_sold;
    double revenue;
};