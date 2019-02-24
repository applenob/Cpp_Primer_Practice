
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

#include "queryresult.h"
#include "textquery.h"
#include "query_base.h"
#include "query.h"
#include "andquery.h"
#include "orquery.h"



int main()
{
    std::ifstream file("storyDataFile.txt");

    TextQuery tQuery(file);

    Query q = Query("hello")  | Query("am");

    return 0;
}
