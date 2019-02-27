#include "limit_quote.h"


void Limit_quote::debug() const
{
    std::cout //<< "data members of this class:\n"
              << "max_qty= " << this->quantity << " "
              << "discount= " << this->discount<< " \n";
}