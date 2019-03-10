# 第十七章 标准库特殊设施

## tuple类型

- `tuple`是类似`pair`的模板，每个成员类型都可以不同，但`tuple`可以有任意数量的成员。
- 但每个确定的`tuple`类型的成员数目是固定的。
- 我们可以将`tuple`看做一个“快速而随意”的数据结构。

**tuple支持的操作**：

| 操作 | 解释 |
|-----|-----|
| `tuple<T1, T2, ..., Tn> t;` | `t`是一个`tuple`，成员数为`n`，第`i`个成员的类型是`Ti`所有成员都进行值初始化。 |
| `tuple<T1, T2, ..., Tn> t(v1, v2, ..., vn);` | 每个成员用对应的初始值`vi`进行初始化。此构造函数是`explicit`的。 |
| `make_tuple(v1, v2, ..., vn)` | 返回一个用给定初始值初始化的`tuple`。`tuple`的类型从初始值的类型**推断**。 |
| `t1 == t2` | 当两个`tuple`具有相同数量的成员且成员对应相等时，两个`tuple`相等。 |
| `t1 relop t2` | `tuple`的关系运算使用**字典序**。两个`tuple`必须具有相同数量的成员。 |
| `get<i>(t)` | 返回`t`的第`i`个数据成员的引用：如果`t`是一个左值，结果是一个左值引用；否则，结果是一个右值引用。`tuple`的所有成员都是`public`的。 |
| `tuple_size<tupleType>::value` | 一个类模板，可以通过一个`tuple`类型来初始化。它有一个名为`value`的`public constexpr static`数据成员，类型为`size_t`，表示给定`tuple`类型中成员的数量。 |
| `tuple_element<i, tupleType>::type` | 一个类模板，可以通过一个整型常量和一个`tuple`类型来初始化。它有一个名为`type`的`public`成员，表示给定`tuple`类型中指定成员的类型。 |

### 定义和初始化tuple

定义和初始化示例：

- `tuple<size_t, size_t, size_t> threeD;`
- `tuple<size_t, size_t, size_t> threeD{1,2,3};`
- `auto item = make_tuple("0-999-78345-X", 3, 2.00)；`

访问tuple成员：

- `auto book = get<0>(item);`
- `get<2>(item) *= 0.8;`

### 使用tuple返回多个值

- `tuple`最常见的用途是从一个函数返回多个值。

## bitset类型

- 处理二进制位的有序集；
- `bitset`也是类模板，但尖括号中输入的是`bitset`的长度而不是元素类型，因为元素类型是固定的，都是一个二进制位。

初始化`bitset`的方法：

| 操作 | 解释 |
|-----|-----|
| `bitset<n> b;` | `b`有`n`位；每一位均是0.此构造函数是一个`constexpr`。 |
| `bitset<n> b(u);` | `b`是`unsigned long long`值`u`的低`n`位的拷贝。如果`n`大于`unsigned long long`的大小，则`b`中超出`unsigned long long`的高位被置为0。此构造函数是一个`constexpr`。 |
| `bitset<n> b(s, pos, m, zero, one);` | `b`是`string s`从位置`pos`开始`m`个字符的拷贝。`s`只能包含字符`zero`或`one`：如果`s`包含任何其他字符，构造函数会抛出`invalid_argument`异常。字符在`b`中分别保存为`zero`和`one`。`pos`默认为0，`m`默认为`string::npos`，`zero`默认为'0'，`one`默认为'1'。 |
| `bitset<n> b(cp, pos, m, zero, one);` | 和上一个构造函数相同，但从`cp`指向的字符数组中拷贝字符。如果未提供`m`，则`cp`必须指向一个`C`风格字符串。如果提供了`m`，则从`cp`开始必须至少有`m`个`zero`或`one`字符。 |

初始化案例；
- `bitset<13> bitvec1(0xbeef);`
- `bitset<32> bitvec4("1100");`

`bitset`操作：

| 操作 | 解释 |
|-----|-----|
| `b.any()` | `b`中是否存在1。 |
| `b.all()` | `b`中都是1。 |
| `b.none()` | `b`中是否没有1。 |
| `b.count()` | `b`中1的个数。 |
| `b.size()` |  |
| `b.test(pos)` | `pos`下标是否是1 |
| `b.set(pos)` | `pos`置1 |
| `b.set()` | 所有都置1 |
| `b.reset(pos)` | 将位置`pos`处的位复位 |
| `b.reset()` | 将`b`中所有位复位 |
| `b.flip(pos)` | 将位置`pos`处的位取反 |
| `b.flip()` | 将`b`中所有位取反 |
| `b[pos]` | 访问`b`中位置`pos`处的位；如果`b`是`const`的，则当该位置位时，返回`true`；否则返回`false`。 |
| `b.to_ulong()` | 返回一个`unsigned long`值，其位模式和`b`相同。如果`b`中位模式不能放入指定的结果类型，则抛出一个`overflow_error`异常。 |
| `b.to_ullong()` | 类似上面，返回一个`unsigned long long`值。 |
| `b.to_string(zero, one)` | 返回一个`string`，表示`b`中位模式。`zero`和`one`默认为0和1。 |
| `os << b` | 将`b`中二进制位打印为字符`1`或`0`，打印到流`os`。 |
| `is >> b` | 从`is`读取字符存入`b`。当下一个字符不是1或0时，或是已经读入`b.size()`个位时，读取过程停止。 |

## 正则表达式

- 正则表达式（reqular expression）是一种描述字符序列的方法，是一种很强大的工具。

正则表达式库组件：

| 组件 | 解释 |
|-----|-----| 
| `regex` | 表示一个正则表达式的类 |
| `regex_match` | 将一个字符序列与一个正则表达式匹配 |
| `regex_search` | 寻找第一个与正则表达式匹配的子序列 |
| `regex_replace` | 使用给定格式替换一个正则表达式 |
| `sregex_iterator` | 迭代器适配器，调用`regex_searcg`来遍历一个`string`中所有匹配的子串 |
| `smatch` | 容器类，保存在`string`中搜索的结果 |
| `ssub_match` | `string`中匹配的子表达式的结果 |


`regex_match`和`regex_search`的参数：

| 操作 | 解释 |
|-----|-----|
| `(seq, m, r, mft)` | 在字符序列`seq`中查找`regex`对象`r`中的正则表达式。`seq`可以是一个`string`、标识范围的一对迭代器、一个指向空字符结尾的字符数组的指针。 |
| `(seq, r, mft)` | `m`是一个`match`对象，用来保存匹配结果的相关细节。`m`和`seq`必须具有兼容的类型。`mft`是一个可选的`regex_constants::match_flag_type`值。 |

- 这些操作会返回`bool`值，指出是否找到匹配。

### 使用正则表达式库

- `regex`使用的正则表达式语言是`ECMAScript`，模式`[[::alpha::]]`匹配任意字母。
- 由于反斜线是C++中的特殊字符，在模式中每次出现`\`的地方，必须用一个额外的反斜线`\\`告知C++我们需要一个反斜线字符。
- 简单案例：
  - `string pattern("[^c]ei"); pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*"` 查找不在字符c之后的字符串ei
  - `regex r(pattern);` 构造一个用于查找模式的regex
  - `smatch results;` 定义一个对象保存搜索结果
  - `string test_str = "receipt freind theif receive";`
  - `if (regex_search(test_str, results, r)) cout << results.str() << endl;` 如有匹配子串，打印匹配的单词。

`regex`（和`wregex`）选项：

| 操作 | 解释 |
|-----|-----|
| `regex r(re)` `regex r(re, f)` | `re`表示一个正则表达式，它可以是一个`string`、一对表示字符范围的迭代器、一个指向空字符结尾的字符数组的指针、一个字符指针和一个计数器、一个花括号包围的字符列表。`f`是指出对象如何处理的标志。`f`通过下面列出来的值来设置。如果未指定`f`，其默认值为`ECMAScript`。 |
| `r1 = re` | 将`r1`中的正则表达式替换Wie`re`。`re`表示一个正则表达式，它可以是另一个`regex`对象、一个`string`、一个指向空字符结尾的字符数组的指针或是一个花括号包围的字符列表。 |
| `r1.assign(re, f)` | 和使用赋值运算符（=）的效果相同：可选的标志`f`也和`regex`的构造函数中对应的参数含义相同。 |
| `r.mark_count()` | `r`中子表达式的数目 |
| `r.flags()` | 返回`r`的标志集 |

定义`regex`时指定的标志：

| 操作 | 解释 |
|-----|-----|
| `icase` | 在匹配过程中忽略大小写 |
| `nosubs` | 不保存匹配的子表达式 |
| `optimize` | 执行速度优先于构造速度 |
| `ECMAScript` | 使用`ECMA-262`指定的语法 |
| `basic` | 使用`POSIX`基本的正则表达式语法 |
| `extended` | 使用`POSIX`扩展的正则表达式语法 |
| `awk` | 使用`POSIX`版本的`awk`语言的语法 |
| `grep` | 使用`POSIX`版本的`grep`的语法 |
| `egrep` | 使用`POSIX`版本的`egrep`的语法 |

- 可以将正则表达式本身看做是一种简单程序语言设计的程序。在运行时，当一个`regex`对象被初始化或被赋予新模式时，才被“编译”。
- 如果编写的正则表达式存在错误，会在运行时抛出一个`regex_error`的异常。
- 避免创建不必要的正则表达式。构建一个`regex`对象可能比较耗时。

### 匹配与regex迭代器类型

`sregex_iterator`操作（用来获得所有匹配）：

| 操作 | 解释 |
|-----|-----|
| `sregex_iterator it(b, e, r);` | 一个`sregex_iterator`，遍历迭代器`b`和`e`表示的`string`。它调用`sregex_search(b, e, r)`将`it`定位到输入中第一个匹配的位置。 |
| `sregex_iterator end;` | `sregex_iterator`的尾后迭代器 |
| `*it`， `it->` | 根据最后一个调用`regex_search`的结果，返回一个`smatch`对象的引用或一个指向`smatch`对象的指针。 |
| `++it` ， `it++` | 从输入序列当前匹配位置开始调用`regex_search`。前置版本返回递增后迭代器；后置版本返回旧值。 |
| `it1 == it2` | 如果两个`sregex_iterator`都是尾后迭代器，则它们相等。两个非尾后迭代器是从相同的输入序列和`regex`对象构造，则它们相等。 |

示例：

```cpp
// 将字符串file中所有匹配模式r的子串输出
for (sregex_iterator it(file.begin(), file.end(), r), end_it; it != end_it; ++it){
    cout << it ->str() << endl;
}
```

`smatch`操作：

| 操作 | 解释 |
|-----|-----|
| `m.ready()` | 如果已经通过调用`regex_search`或`regex_match`设置了`m`，则返回`true`；否则返回`false`。如果`ready`返回`false`，则对`m`进行操作是未定义的。 |
| `m.size()` | 如果匹配失败，则返回0，；否则返回最近一次匹配的正则表达式中子表达式的数目。 |
| `m.empty()` | 等价于`m.size() == 0` |
| `m.prefix()` | 一个`ssub_match`对象，标识当前匹配之前的序列 |
| `m.suffix()` | 一个`ssub_match`对象，标识当前匹配之后的部分 |
| `m.format(...)` |  |
| `m.length(n)` | 第`n`个匹配的子表达式的大小 |
| `m.position(n)` | 第`n`个子表达式距离序列开始的长度 |
| `m.str(n)` | 第`n`个子表达式匹配的`string` |
| `m[n]` | 对应第`n`个子表达式的`ssub_match`对象 |
| `m.begin(), m.end()` | 表示`m`中`ssub_match`元素范围的迭代器。 |
| `m.cbegin(), m.cend()` | 常量迭代器 |

### 使用子表达式

- 正则表达式语法通常用括号表示子表达式。
- 子表达式的索引从1开始。
- 在`fmt`中用`$`后跟子表达式的索引号来标识一个特定的子表达式。

示例：

```cpp
if (regex_search(filename, results, r))
    cout << results.str(1) << endl;  // .str(1)获取第一个子表达式匹配结果
```

`ssub_match`子匹配操作：

| 操作 | 解释 |
|-----|-----|
| `matched` | 一个`public bool`数据成员，指出`ssub_match`是否匹配了 |
| `first`， `second` | `public`数据成员，指向匹配序列首元素和尾后位置的迭代器。如果未匹配，则`first`和`second`是相等的。 |
| `length()` | 匹配的大小，如果`matched`为`false`，则返回0。 |
| `str()` | 返回一个包含输入中匹配部分的`string`。如果`matched`为`false`，则返回空`string`。 |
| `s = ssub` | 将`ssub_match`对象`ssub`转化为`string`对象`s`。等价于`s=ssub.str()`，转换运算符不是`explicit`的。 |

### 使用regex_replace

正则表达式替换操作：

| 操作 | 解释 |
|-----|-----|
| `m.format(dest, fmt, mft)`, `m.format(fmt, mft)` | 使用格式字符串`fmt`生成格式化输出，匹配在`m`中，可选的`match_flag_type`标志在`mft`中。第一个版本写入迭代器`dest`指向的目的为止，并接受`fmt`参数，可以是一个`string`，也可以是一个指向空字符结尾的字符数组的指针。`mft`的默认值是`format_default`。 |
| `rege_replace(dest, seq, r, fmt, mft)`，  `regex_replace(seq, r, fmt, mft)` | 遍历`seq`，用`regex_search`查找与`regex`对象`r`相匹配的子串，使用格式字符串`fmt`和可选的`match_flag_type`标志来生成输出。`mft`的默认值是`match_default` |

示例：

```cpp
string phone = "(\\()?(\\d{3})(\\))?([-. ])?(\\d{3})([-. ]?)(\\d{4})"
string fmt = "$2.$5.$7";  // 将号码格式改为ddd.ddd.dddd
regex r(phone);  // 用来寻找模式的regex对象
string number = "(908) 555-1800";
cout << regex_replace(number, r, fmt) << endl;
```

匹配标志：

| 操作 | 解释 |
|-----|-----|
| `match_default` | 等价于`format_default` |
| `match_not_bol` | 不将首字符作为行首处理 |
| `match_not_eol` | 不将尾字符作为行尾处理 |
| `match_not_bow` | 不将首字符作为单词首处理 |
| `match_not_eow` | 不将尾字符作为单词尾处理 |
| `match_any` | 如果存在多于一个匹配，则可以返回任意一个匹配 |
| `match_not_null` | 不匹配任何空序列 |
| `match_continuous` | 匹配必须从输入的首字符开始 |
| `match_prev_avail` | 输入序列包含第一个匹配之前的内容 |
| `format_default` | 用`ECMAScript`规则替换字符串 |
| `format_sed` | 用`POSIX sed`规则替换字符串 |
| `format_no_copy` | 不输出输入序列中未匹配的部分 |
| `format_first_only` | 只替换子表达式的第一次出现 |

## 随机数

- 新标准之前，C和C++都依赖一个简单的C库函数`rand`来生成随机数，且只符合均匀分布。
- 新标准：**随机数引擎** + **随机数分布类**， 定义在   `random`头文件中。
- C++程序应该使用`default_random_engine`类和恰当的分布类对象。

### 随机数引擎和分布

随机数引擎操作

| 操作 | 解释 |
|-----|-----|
| `Engine e;` | 默认构造函数；使用该引擎类型默认的种子 |
| `Engine e(s);` | 使用整型值`s`作为种子 |
| `e.seed(s)` | 使用种子`s`重置引擎的状态 |
| `e.min()`，`e.max()` | 此引擎可生成的最小值和最大值 |
| `Engine::result_type` | 此引擎生成的`unsigned`整型类型 |
| `e.discard(u)` | 将引擎推进`u`步；`u`的类型为`unsigned long long` |

示例：

```cpp
// 初始化分布类型
uniform_int_distribution<unsigned> u(0, 9);
// 初始化引擎
default_random_engine e;
// 随机生成0-9的无符号整数
cout << u(e) << endl;
```

**设置随机数发生器种子**：

- 种子就是一个数值，引擎可以利用它从序列中一个新位置重新开始生成随机数。
- 种子可以使用系统函数`time(0)`。

### 其他随机数分布

分布类型的操作：

| 操作 | 解释 |
|-----|-----|
| `Dist d;` | 默认够赞函数；使`d`准备好被使用。其他构造函数依赖于`Dist`的类型；分布类型的构造函数是`explicit`的。 |
| `d(e)` | 用相同的`e`连续调用`d`的话，会根据`d`的分布式类型生成一个随机数序列；`e`是一个随机数引擎对象。 |
| `d.min()`,`d.max()` | 返回`d(e)`能生成的最小值和最大值。 |
| `d.reset()` | 重建`d`的状态，是的随后对`d`的使用不依赖于`d`已经生成的值。 |

## IO库再探

### 格式化输入与输出

- 使用操纵符改变格式状态。
- 控制布尔值的格式： `cout << boolalpha << true << endl;`
- 指定整型的进制：`cout << dec << 20 << endl;`

定义在`iostream`中的操纵符：

| 操纵符 | 解释 |
|-----|-----|
| `boolalpha` | 将`true`和`false`输出为字符串 |
| `* noboolalpha` | 将`true`和`false`输出为1,0 |
| `showbase` | 对整型值输出表示进制的前缀 |
| `* noshowbase` | 不生成表示进制的前缀 |
| `showpoint` | 对浮点值总是显示小数点 |
| `* noshowpoint` | 只有当浮点值包含小数部分时才显示小数点 |
| `showpos` | 对非负数显示`+` |
| `* noshowpos` | 对非负数不显示`+` |
| `uppercase` | 在十六进制中打印`0X`，在科学计数法中打印`E` |
| `* nouppercase` | 在十六进制中打印`0x`，在科学计数法中打印`e` |
| `* dec` | 整型值显示为十进制 |
| `hex` | 整型值显示为十六进制 |
| `oct` | 整型值显示为八进制 |
| `left` | 在值的右侧添加填充字符 |
| `right` | 在值的左侧添加填充字符 |
| `internal` | 在符号和值之间添加填充字符 |
| `fixed` | 浮点值显示为定点十进制 |
| `scientific` | 浮点值显示为科学计数法 |
| `hexfloat` | 浮点值显示为十六进制（C++11） |
| `defaultfloat` | 充值浮点数格式为十进制（C++11） |
| `unitbuf` | 每次输出操作后都刷新缓冲区 |
1| `* nounitbuf` | 恢复正常的缓冲区刷新模式 |
| `* skipws` | 输入运算符跳过空白符 |
| `noskipws` | 输入运算符不跳过空白符 |
| `flush` | 刷新`ostream`缓冲区 |
| `ends` | 插入空字符，然后刷新`ostream`缓冲区 |
| `endl` | 插入换行，然后刷新`ostream`缓冲区 |

其中`*`表示默认的流状态。

### 未格式化的输入/输出操作

单字节低层IO操作：

| 操作 | 解释 |
|-----|-----|
| `is.get(ch)` | 从`istream is`读取下一个字节存入字符`cn`中。返回`is`。 |
| `os.put(ch)` | 将字符`ch`输出到`ostream os`。返回`os`。 |
| `is.get()` | 将`is`的下一个字节作为`int`返回 |
| `is.putback(ch)` | 将字符`ch`放回`is`。返回`is`。 |
| `is.unget()` | 将`is`向后移动一个字节。返回`is`。 |
| `is.peek()` | 将下一个字节作为`int`返回，但不从流中删除它。 |

多字节低层IO操作：

| 操作 | 解释 |
|-----|-----|
| `is.get(sink, size, delim)` | 从`is`中读取最多`size`个字节，并保存在字符数组中，字符数组的起始地址由`sink`给出。读取过程直到遇到字符`delim`或读取了`size`个字节或遇到文件尾时停止。如果遇到了`delim`，则将其留在输入流中，不读取出来存入`sink`。 |
| `is.getline(sink, size, delim)` | 与接收三个参数的`get`版本类似，但会读取并丢弃`delim`。 |
| `is.read(sink, size)` | 读取最多`size`个字节，存入字符数组`sink`中。返回`is`。 |
| `is.gcount()` | 返回上一个未格式化读取从`is`读取的字节数 |
| `os.write(source, size)` | 将字符数组`source`中的`size`个字节写入`os`。返回`os`。 |
| `is.ignore(size, delim)` | 读取并忽略最多`size`个字符，包括`delim`。与其他未格式化函数不同，`ignore`有默认参数：`size`默认值是1，`delim`的默认值为文件尾。 |

- 注意：一般情况下，主张使用标准库提供的高层抽象，低层函数容易出错。

### 流随机访问

- 只适用于`fstream`和`sstream`。
- 通过将标记`seek`到一个给定位置来重定位它。
- `tell`告诉我们标记的当前位置。

| 操作 | 解释 |
|-----|-----|
| `tellg()`，`tellp` | 返回一个输入流中（`tellg`）或输出流中（`tellp`）标记的当前位置。 |
| `seekg(pos)`，`seekp(pos)`  | 在一个输入流或输出流中将标记重定位到给定的绝对地址。`pos`通常是一个当前`teelg`或`tellp`返回的值。 |
| `seekp(off, from)`，`seekg(off, from)` | 在一个输入流或输出流中将标记定位到`from`之前或之后`off`个字符，`from`可以是下列值之一：`beg`，偏移量相对于流开始位置；`cur`，偏移量相对于流当前位置；`end`，偏移量相对于流结尾位置。 |