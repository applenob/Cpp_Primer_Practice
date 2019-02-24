#ifndef QUERY_H
#define QUERY_H

#include <iostream>
#include <string>
#include <memory>
#include "query_base.h"
#include "queryresult.h"
#include "textquery.h"
#include "wordquery.h"



/**
 * @brief interface class to manage the Query_base inheritance hierachy
 * Query类对外提供接口，同时隐藏了Quer_base的继承体系。
 * 每个Query对象都有一个指向Query_base对象的shared_ptr。
 */
class Query
{
    friend Query operator~(const Query&);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    // build a new WordQuery
    Query(const std::string& s) : q(new WordQuery(s))
    {
        std::cout << "Query::Query(const std::string& s) where s="+s+"\n";
    }

    // interface functions: call the corresponding Query_base operatopns
    QueryResult eval(const TextQuery& t) const
    { return q->eval(t); }
    std::string rep() const
    {
        std::cout << "Query::rep() \n";
        return q->rep();
    }

private:
    // constructor only for friends
    Query(std::shared_ptr<Query_base> query) :
        q(query)
    {
        std::cout << "Query::Query(std::shared_ptr<Query_base> query)\n";
    }
    std::shared_ptr<Query_base> q;
};

inline std::ostream&
operator << (std::ostream& os, const Query& query)
{
    // make a virtual call through its Query_base pointer to rep();
    return os << query.rep();
}

#endif // QUERY_H
