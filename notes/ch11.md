# 第十一章 关联容器

- 关联容器和顺序容器的不同：关联容器中的元素时按照**关键字**来保存和访问的。
- 关联容器支持通过关键字来高效地查找和读取元素，基本的关联容器类型是 `map`和 `set`。

**关联容器类型**：

| 容器类型 | 解释 |
|-----|-----|
| 按顺序存储 |  |
| `map` | 关键数组：保存`关键字-值`对 |
| `set` | 关键字即值，即只保存关键字的容器 |
| `multimap` | 支持同一个键多次出现的`map` |
| `multiset` | 支持同一个键多次出现的`set` |
| 无序集合 |  |
| `unordered_map` | 用哈希函数组织的`map` |
| `unordered_set` | 用哈希函数组织的`set` |
| `unordered_multimap` | 哈希组织的`map`，关键字可以重复出现 |
| `unordered_multiset` | 哈希组织的`set`，关键字可以重复出现 |

## 关联容器概述

### 定义关联容器

- 需要指定元素类型。
- 列表初始化：
  - `map`：`map<string, int> word_count = {{"a", 1}, {"b", 2}};`
  - `set`：`set<string> exclude = {"the", "a"};`

### 关键字类型的要求

- 对于有序容器，关键字类型必须定义元素比较的方法。默认是`<`。
- 如果想传递一个比较的函数，可以这样定义：`multiset<Sales_data, decltype(compareIsbn)*> bookstore(compareIsbn);`

### pair

- 在`utility`头文件中定义。
- 一个`pair`保存两个数据成员，两个类型不要求一样。

**pair的操作**：

| 操作 | 解释 |
|-----|-----|
| `pair<T1, T2> p;` | `p`是一个`pair`，两个类型分别是`T1`和`T2`的成员都进行了值初始化。 |
| `pair<T1, T2> p(v1, v2);` | `first`和`second`分别用`v1`和`v2`进行初始化。 |
| `pair<T1, T2>p = {v1, v2};` | 等价于`p(v1, v2) |
| `make_pair(v1, v2);` | `pair`的类型从`v1`和`v2`的类型推断出来。 |
| `p.first` | 返回`p`的名为`first`的数据成员。 |
| `p.second` | 返回`p`的名为`second`的数据成员。 |
| `p1 relop p2` | 运算关系符按字典序定义。 |
| `p1 == p2` | 必须两对元素两两相等 |
| `p1 != p2` | 同上 |

## 关联容器操作

**关联容器额外的类型别名**：

| 类型别名 | 解释 |
|-----|-----|
| `key_type` | 此容器类型的关键字类型 |
| `mapped_type` | 每个关键字关联的类型，只适用于`map` |
| `value_type` | 对于`map`，是`pair<const key_type, mapped_type>`; 对于`set`，和`key_type`相同。 |

### 关联容器迭代器

- 解引用一个关联容器迭代器时，会得到一个类型为容器的`value_type`的值的引用。
- `set`的迭代器是`const`的。
- 遍历关联容器：使用`begin`和`end`，遍历`map`、`multimap`、`set`、`multiset`时，迭代器按**关键字升序**遍历元素。

### 添加元素

**关联容器`insert`操作**：

| `insert`操作 | 关联容器 |
|-----|-----|
| `c.insert(v)`  `c.emplace(args)` | `v`是`value_type`类型的对象；`args`用来构造一个元素。 对于`map`和`set`，只有元素的关键字不存在`c`中才插入或构造元素。函数返回一个`pair`，包含一个迭代器，指向具有指定关键字的元素，以及一个指示插入是否成功的`bool`值。对于`multimap`和`multiset`则会插入范围中的每个元素。|
| `c.insert(b, e)` `c.insert(il)` | `b`和`e`是迭代器，表示一个`c::value_type`类型值的范围；`il`是这种值的花括号列表。函数返回`void`。对于 `map`和`set`，只插入关键字不在`c`中的元素。 |
| `c.insert(p, v)`  `c.emplace(p, args)` | 类似`insert(v)`，但将迭代器`p`作为一个提示，指出从哪里开始搜索新元素应该存储的位置。返回一个迭代器，指向具有给定关键字的元素。 |

向`map`添加元素：
- `word_count.insert({word, 1});`
- `word_count.insert(make_pair(word, 1));`
- `word_count.insert(pair<string, size_t>(word, 1));`
- `word_count.insert(map<string, size_t>::value_type (word, 1));`

### 删除元素

**从关联容器中删除元素**：

| 操作 | 解释 |
|-----|-----|
| `c.erase(k)` | 从`c`中删除每个关键字为`k`的元素。返回一个`size_type`值，指出删除的元素的数量。 |
| `c.erase(p)` | 从`c`中删除迭代器`p`指定的元素。`p`必须指向`c`中一个真实元素，不能等于`c.end()`。返回一个指向`p`之后元素的迭代器，若`p`指向`c`中的尾元素，则返回`c.end()` |
| `c.erase(b, e)` | 删除迭代器对`b`和`e`所表示范围中的元素。返回`e`。 |

### 下标操作

**`map`和`unordered_map`的下标操作**：

| 操作 | 解释 |
|-----|-----|
| `c[k]` | 返回关键字为`k`的元素；如果`k`不在`c`中，添加一个关键字为`k`的元素，对其值初始化。 |
| `c.at(k)` | 访问关键字为`k`的元素，带参数检查；若`k`不存在在`c`中，抛出一个`out_of_range`异常。 |

### 查找元素

**在一个关联容器中查找元素**:

| 操作 | 解释 |
|-----|-----|
| `c.find(k)` | 返回一个迭代器，指向第一个关键字为`k`的元素，若`k`不在容器中，则返回尾后迭代器 |
| `c.count(k)` | 返回关键字等于`k`的元素的数量。对于不允许重复关键字的容器，返回值永远是0或1。 |
| `c.lower_bound(k)` | 返回一个迭代器，指向第一个关键字**不小于**`k`的元素。 |
| `c.upper_bound(k)` | 返回一个迭代器，指向第一个关键字**大于**`k`的元素。 |
| `c.equal_range(k)` | 返回一个迭代器`pair`，表示关键字等于`k`的元素的范围。若`k`不存在，`pair`的两个成员均等于`c.end()`。 |

- `lower_bound`和`upper_bound`不适用于无序容器。
- 下标和`at`操作只适用于非`const`的`map`和`unordered_map`。

## 无序容器

- 有序容器使用比较运算符来组织元素；无序容器使用哈希函数和关键字类型的`==`运算符。
- 理论上哈希技术可以获得更好的性能。
- 无序容器在存储上组织为一组桶(bucket)，每个桶保存零个或多个元素。无序容器使用一个哈希函数将元素映射到桶。

**无序容器管理操作**：

| 操作 | 解释 |
|-----|-----|
| **桶接口** |  |
| `c.bucket_count()` | 正在使用的桶的数目 |
| `c.max_bucket_count()` | 容器能容纳的最多的桶的数目 |
| `c.bucket_size(n)` | 第`n`个桶中有多少个元素 |
| `c.bucket(k)` | 关键字为`k`的元素在哪个桶中 |
| **桶迭代** |  |
| `local_iterator` | 可以用来访问桶中元素的迭代器类型 |
| `const_local_iterator` | 桶迭代器的`const`版本 |
| `c.begin(n)`，`c.end(n)` | 桶`n`的首元素迭代器 |
| `c.cbegin(n)`，`c.cend(n)` | 与前两个函数类似，但返回`const_local_iterator`。 |
| **哈希策略** |  |
| `c.load_factor()` | 每个桶的平均元素数量，返回`float`值。 |
| `c.max_load_factor()` | `c`试图维护的平均比桶大小，返回`float`值。`c`会在需要时添加新的桶，以使得`load_factor<=max_load_factor` |
| `c.rehash(n)` | 重组存储，使得`bucket_count>=n`，且`bucket_count>size/max_load_factor` |
| `c.reverse(n)` | 重组存储，使得`c`可以保存`n`个元素且不必`rehash`。 |
