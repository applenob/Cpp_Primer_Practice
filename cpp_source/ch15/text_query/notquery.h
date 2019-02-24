#ifndef NOTQUERY_H
#define NOTQUERY_H
#include "query_base.h"
#include "query.h"


/**
 * @brief The NotQuery class
 *
 *The ~ operator generates a NotQuery, which holds a Query,
 *which it negates.
 */
class NotQuery : public Query_base
{
    friend Query operator~(const Query& operand);
    NotQuery(const Query& q): query(q)
    {
        std::cout << "NotQuery::NotQuery()\n";
    }

    // virtuals:
    std::string rep() const override
    {
        std::cout << "NotQuery::rep()\n";
        return "~(" + query.rep() + ")";
    }

    QueryResult eval(const TextQuery &) const override;

    Query query;
};

inline Query operator~(const Query& operand)
{
    return std::shared_ptr<Query_base>(new NotQuery(operand));
    //    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // note : There is an imlplicit conversion here.
    //        The Query constructor that takes shared_ptr is not
    //        "explicit", thus the compiler allows this conversion.
}

#endif // NOTQUERY_H
