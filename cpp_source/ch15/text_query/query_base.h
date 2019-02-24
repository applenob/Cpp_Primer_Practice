#ifndef QUERY_BASE_H
#define QUERY_BASE_H
#include "textquery.h"
#include "queryresult.h"

/**
 * @brief abstract class acts as a base class for all concrete query types
 *        all members are private.
 */
class Query_base
{
    friend class Query;
protected:
    using line_no = TextQuery::line_no; //  used in the eval function
    virtual ~Query_base() = default;

private:
    // returns QueryResult that matches this query
    virtual QueryResult eval(const TextQuery&) const = 0;

    // a string representation of this query
    virtual std::string rep() const = 0;
};

#endif // QUERY_BASE_H
