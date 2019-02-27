#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "query_base.h"
#include "query.h"



/**
 * @brief The BinaryQuery class
 *An abstract class holds data needed by the query types that operate on two operands
 */
class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query&l, const Query& r, std::string s):
        lhs(l), rhs(r), opSym(s)
    {
        std::cout << "BinaryQuery::BinaryQuery()  where s=" + s + "\n";
    }

    // @note:  abstract class: BinaryQuery doesn't define eval

    std::string rep() const override
    {
        std::cout << "BinaryQuery::rep()\n";
        return "(" + lhs.rep() + " "
                   + opSym + " "
                + rhs.rep() + ")";
    }

    Query lhs, rhs;
    std::string opSym;
};

#endif // BINARYQUERY_H
