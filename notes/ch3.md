# 第三章 字符串、向量和数组

## using声明
- 使用某个命名空间：例如 `using std::cin`表示使用命名空间`std`中的名字`cin`。
- 头文件中不应该包含using声明。

## string
- 标准库类型string表示可变长的字符序列。
- `#include <string>`，然后 `using std::string;`
- **string对象**：注意，不同于字符串字面值。
- `s.emtpy()`是否为空；
- `s.size()`尺寸；
- `string::size_type`定义了size的类型；
- `+`：字符串连接；
- `str[i]` 可以作为左值。
- `getline(is, s)` 从is中读取一行赋给s，返回is。
- `<, <=, >, >=` 利用字符在字典中的顺序进行比较，对大小写敏感。
- string io：
    - 执行读操作：忽略掉开头的空白（包括空格、换行符和制表符），直到遇到下一处空白为止。
    - `getline`：读取一整行，包括空白符。
- 字符串字面值和string是不同的类型。

**ctype.h vs. cctype**：C++修改了c的标准库，名称为去掉“.h”，前面加“c”。

## vector
- vector是一个容器，也是一个类模板；
- 通过将类型放在类模板名称后面的尖括号中来指定类型，如`vector<int> ivec`。
- `v.push_back(e)`在尾部增加元素；
- 下标操作`v[i]`；
- `v.emtpy()`是否为空；
- `v.size()`尺寸；
- `vector<int>::iterator iter`;
- `iter.begin();`返回迭代器指向的第一个元素；
- `iter.end();`返回迭代器指向的最后一个元素的下一个（哨兵）；
- 使用解引用符`*`访问迭代器指向的元素。

**容器**：可以包含其他对象；但所有的对象必须类型相同。

**迭代器（iterator）**：每种标准容器都有自己的迭代器。C++倾向于用迭代器而不是下标遍历元素。

**const_iterator**：只能读取容器内元素不能改变。

**difference_type**：保证足够大以存储任何两个迭代器对象间的距离。

## bitset
- 处理二进制位的有序集；
- bitset也是类模板，但尖括号中输入的是bitset的长度而不是元素类型，因为元素类型是固定的，都是一个二进制位。
- `b.any();`b中是否存在1；
- `b.none();`b中是否没有1；
- `b.count();`b中1的个数；
- `b.size();`
- `b[i];`
- `b.test(pos);`pos下标是否是1；
- `b.set();`所有都置1；
- `b.set(pos);`pos置1；
- `b.reset();`
- `b.reset(pos);`
- `b.flip();`
- `b.flip(pos);`
- `b.to_ulong();`
