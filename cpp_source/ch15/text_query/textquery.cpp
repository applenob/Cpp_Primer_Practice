/***************************************************************************
 *  @file       textquery.cpp
 *  @author     Alan.W
 *  @date       30  DEC 2013
 *  @remark     The TextQuery class using StrBlob
 ***************************************************************************/

//
// Exercise 12.32:
// Rewrite the TextQuery and QueryResult classes to use a StrBlob instead of a
// vector<string> to hold the input file.
//  Relevant post on Stack Overflow:
//  http://stackoverflow.com/questions/20823225/what-will-happen-if-a-user-defined-constructor-omits-ininitialization-for-data-m
//

#include "textquery.h"
#include "queryresult.h"
#include <iostream>
#include <sstream>
#include <iterator>

/**
 * @brief constructor using StrBlob.
 */
TextQuery::TextQuery(std::ifstream &fin) :
    file(StrBlob()),
    wordMap(std::map<std::string, std::shared_ptr<std::set<line_no>>>())
{
    std::string line;

    // each line
    while(std::getline(fin, line))
    {
        file.push_back(line);
        int n = file.size() - 1;    // the current line number

        // each word
        std::stringstream lineSteam(line);
        std::string word;
        while(lineSteam >> word)
        {
            std::shared_ptr<std::set<line_no>>&                          
                           sp_lines = wordMap[word];
            // if null
            if(!sp_lines)
            {
                sp_lines.reset(new std::set<line_no>);
            }
            sp_lines->insert(n);
        }
    }
}

/**
 * @brief do a query opertion and return QueryResult object.
 */
QueryResult
TextQuery::query(const std::string &sought) const
{
    // dynamicaly allocated set used for the word does not appear.
    static std::shared_ptr<std::set<line_no>> noData(new std::set<line_no>);

    // fetch the iterator to the matching element in the map<word, lines>.
    //std::map<std::string, std::shared_ptr<std::set<index_Tp>>>::const_iterator
    auto iter = wordMap.find(sought);
    if(iter == wordMap.end())
        return QueryResult(sought, noData, file);
    else
        return QueryResult(sought, iter->second, file);
}
