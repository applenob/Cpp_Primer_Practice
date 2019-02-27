/***************************************************************************
 *  @file       queryresult.h
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark     using class StrBlob
 ***************************************************************************/

//
// Exercise 12.33:
// In Chapter 15 we’ll extend our query system and will need some additional
// members in the QueryResult class.
//
// Add members named begin and end that
// return iterators into the set of line numbers returned by a given query,
// and a member named get_file that returns a shared_ptr to the file in the
// QueryResult object.
//

#ifndef QUERYRESULT_H
#define QUERYRESULT_H

#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include <string>
#include "textquery.h"

/**
 * @brief Query Result
 */
class QueryResult
{
    friend std::ostream& print(std::ostream&, const QueryResult&);

public:
    // constructor
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> sp_l,
                StrBlob f) :
        sought(s), sp_lines(sp_l), file(f) { }

    // added for ex12.33
    // ? Think about wether the "const"s here are expected.
    const StrBlob& get_file() const{ return file; }

    std::set<TextQuery::line_no>::iterator
    begin() { return sp_lines->begin(); }

    std::set<TextQuery::line_no>::iterator
    end()   { return sp_lines->end();   }



private:
    // three data members
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> sp_lines;
    StrBlob file;

};

/**
 * @brief print the result to the output stream specified.
 */
std::ostream&
print(std::ostream&, const QueryResult &);
#endif // QUERYRESULT_H
