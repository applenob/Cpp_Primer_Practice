#ifndef ANDQUERY_H
#define ANDQUERY_H


#include "binaryquery.h"

class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query&, const Query&);
    AndQuery(const Query& left, const Query& right):
        BinaryQuery(left, right, "&")
    {
        std::cout << "AndQuery::AndQuery()\n";
    }

    // @note: inherits rep and define eval

    QueryResult eval(const TextQuery &) const override
    {
        // this is just a placeholder rather than the real definition
    }
};

inline Query operator& (const Query& lhs, const Query& rhs)
{
    return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}

#endif // ANDQUERY_H
