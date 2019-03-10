#include <iostream>
#include <tuple>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

#include "ex_17_4_SalesData.h"

using namespace std;

// matches有三个成员：1.一个书店的索引。2.指向书店中元素的迭代器。3.指向书店中元素的迭代器。
typedef tuple<vector<Sales_data>::size_type,
              vector<Sales_data>::const_iterator,
              vector<Sales_data>::const_iterator>
    matches;

// files保存每家书店的销售记录
// findBook返回一个vector，每家销售了给定书籍的书店在其中都有一项
vector<matches> findBook(const vector<vector<Sales_data>> &files,
                         const string &book)
{
    vector<matches> ret; //初始化为空vector
    // 对每家书店，查找给定书籍匹配的记录范围
    for (auto it = files.cbegin; it != files.cend(); ++it)
    {
        // 查找具有相同ISBN的Sales_data范围，found是一个迭代器pair
        auto found = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (found.first != found.second)  // 此书店销售了给定书籍
            // 记住此书店的索引及匹配的范围
            ret.push_back(make_tuple(it - files.cbegin(), found.first, found.second));
    }
    return ret; //如果未找到匹配记录，ret为空
}

void reportResults(istream &in, ostream &os,
                       const vector<vector<Sales_data> > &files){
    string s;  //要查找的书
    while (in >> s){
        auto trans = findBook(files, s);
        if (trans.empty()){
            cout << s << " not found in any stores" << endl;
            continue;  // 获得下一本要查找的书
        }
        for (const auto &store : trans)  // 对每家销售了给定书籍的书店
            // get<n>返回store中tuple的指定的成员
            os << "store " << get<0>(store) << " sales: "
               << accumulate(get<1>(store), get<2>(store), Sales_data(s))
               << endl;
    }
}

int main(){
    return 0;
}