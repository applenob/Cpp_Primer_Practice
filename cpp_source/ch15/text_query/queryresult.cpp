/***************************************************************************
 *  @file       queryresult.cpp
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark     using class StrBlob
 ***************************************************************************/


#include "queryresult.h"


/**
 * @brief   print the result to the output stream specified.
 * @note    class QueryResult's friend
 */
std::ostream
&print(std::ostream &os, const QueryResult &qr)
{
    os << qr.sought << " occurs " << qr.sp_lines->size() << " "
       << "times"   <<  "\n";

    // print each line in which the word appears
    for ( auto &index : *qr.sp_lines)
    {
        os << "\t(line " << index + 1 << ") ";
        const StrBlobPtr wp(qr.file, index);
        os << wp.deref() << "\n";
    }
    return os;

}
