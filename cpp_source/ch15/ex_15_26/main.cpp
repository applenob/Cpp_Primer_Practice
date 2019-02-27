#include <iostream>
#include <string>

#include "quote.h"
#include "bulk_quote.h"
#include "limit_quote.h"
#include "disc_quote.h"


int main()
{
    Bulk_quote bq1;
    Bulk_quote bq2("ss", 2.05, 12, 0.3);
    bq2 = std::move(bq2);


    return 0;
}