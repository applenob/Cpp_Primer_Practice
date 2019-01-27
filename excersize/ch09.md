## 练习9.1

> 对于下面的程序任务，vector、deque和list哪种容器最为适合？解释你的选择的理由。如果没有哪一种容器优于其他容器，也请解释理由。
* (a) 读取固定数量的单词，将它们按字典序插入到容器中。我们将在下一章中看到，关联容器更适合这个问题。
* (b) 读取未知数量的单词，总是将单词插入到末尾。删除操作在头部进行。
* (c) 从一个文件读取未知数量的整数。将这些数排序，然后将它们打印到标准输出。

* (a) `list` ，因为需要频繁的插入操作。
* (b) `deque` ，总是在头尾进行插入、删除操作。
* (c) `vector` ，不需要进行插入删除操作。

## 练习9.2

> 定义一个list对象，其元素类型是int的deque。

```cpp
std::list<std::deque<int>> l;
```

## 练习9.3

> 构成迭代器范围的迭代器有何限制？

两个迭代器 `begin` 和 `end`需满足以下条件：
* 它们指向同一个容器中的元素，或者是容器最后一个元素之后的位置。
* 我们可以通过反复递增 begin 来到达 end。换句话说，end 不在 begin 之前。

## 练习9.4

> 编写函数，接受一对指向vector<int>的迭代器和一个int值。在两个迭代器指定的范围中查找给定的值，返回一个布尔值来指出是否找到。

```cpp
bool find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
{
	while (begin++ != end)
	{
		if (*begin == i) 
			return true;
    }	
    return false;
}
```

## 练习9.5

> 重写上一题的函数，返回一个迭代器指向找到的元素。注意，程序必须处理未找到给定值的情况。

```cpp
vector<int>::const_iterator find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int i)
{
	while (begin != end)
	{
		if (*begin == i) 
			return begin;
		++begin;
    }	
    return end;
}
```

## 练习9.6

> 下面的程序有何错误？你应该如何修改它？
```cpp
list<int> lst1;
list<int>::iterator iter1 = lst1.begin(),
					iter2 = lst1.end();
while (iter1 < iter2) /* ... */
```

修改成如下：
```cpp
while (iter1 != iter2)
```

## 练习9.7

> 为了索引int 的 vector中的元素，应该使用什么类型？

```cpp
vector<int>::size_type
```

## 练习9.8

> 为了读取string 的list 中的元素，应该使用什么类型？如果写入list，又应该使用什么类型？

```cpp
list<string>::const_iterator // 读
list<string>::iterator // 写
```

## 练习9.9

> begin 和 cbegin 两个函数有什么不同？

`begin` 返回的是普通迭代器，`cbegin` 返回的是常量迭代器。

## 练习9.10

> 下面4个对象分别是什么类型？
```cpp
vector<int> v1;
const vector<int> v2;
auto it1 = v1.begin(), it2 = v2.begin();
auto it3 = v1.cbegin(), it4 = v2.cbegin();
```

这里的代码在 VS2013 下是有错误的。
* 错误	1	error C3538: 在声明符列表中，“auto”必须始终推导为同一类型	
因此代码要改为

```cpp
auto it1 = v1.begin();
auto it2 = v2.begin(), it3 = v1.cbegin(), it4 = v2.cbegin();
```

`it1` 是 `vector<int>::iterator`

`it2`，`it3` 和 `it4` 是 `vector<int>::const_iterator`


## 练习9.11

> 对6种创建和初始化 vector 对象的方法，每一种都给出一个实例。解释每个vector包含什么值。

```cpp
vector<int> vec;    // 0
vector<int> vec(10);    // 0
vector<int> vec(10, 1);  // 1
vector<int> vec{ 1, 2, 3, 4, 5 }; // 1, 2, 3, 4, 5
vector<int> vec(other_vec); // 拷贝 other_vec 的元素
vector<int> vec(other_vec.begin(), other_vec.end()); // 拷贝 other_vec 的元素
```

## 练习9.12

> 对于接受一个容器创建其拷贝的构造函数，和接受两个迭代器创建拷贝的构造函数，解释它们的不同。

* 接受一个容器创建其拷贝的构造函数，必须容器类型和元素类型都相同。
* 接受两个迭代器创建拷贝的构造函数，只需要元素的类型能够相互转换，容器类型和元素类型可以不同。

## [练习9.13](exercise9_13.cpp)

> 如何从一个list<int>初始化一个vector<double>？从一个vector<int>又该如何创建？编写代码验证你的答案。

```cpp
list<int> ilst(5, 4);
vector<int> ivc(5, 5);

vector<double> dvc(ilst.begin(), ilst.end());
vector<double> dvc2(ivc.begin(), ivc.end());
```

## 练习9.14

> 编写程序，将一个list中的char * 指针元素赋值给一个vector中的string。

```cpp
    std::list<const char*> l{ "hello", "world" };
    std::vector<std::string> v;
    v.assign(l.cbegin(), l.cend());
```

## 练习9.15

> 编写程序，判定两个vector<int>是否相等。

```cpp
    std::vector<int> vec1{ 1, 2, 3, 4, 5 };
    std::vector<int> vec2{ 1, 2, 3, 4, 5 };
    std::vector<int> vec3{ 1, 2, 3, 4 };

    std::cout << (vec1 == vec2 ? "true" : "false") << std::endl;
    std::cout << (vec1 == vec3 ? "true" : "false") << std::endl;
```

## 练习9.16

> 重写上一题的程序，比较一个list<int>中的元素和一个vector<int>中的元素。

```cpp
    std::list<int>      li{ 1, 2, 3, 4, 5 };
    std::vector<int>    vec2{ 1, 2, 3, 4, 5 };
    std::vector<int>    vec3{ 1, 2, 3, 4 };

    std::cout << (std::vector<int>(li.begin(), li.end()) == vec2 ? "true" : "false") << std::endl;
    std::cout << (std::vector<int>(li.begin(), li.end()) == vec3 ? "true" : "false") << std::endl;
```

## 练习9.17

> 假定c1 和 c2 是两个容器，下面的比较操作有何限制？
```cpp
	if (c1 < c2)
```

* c1 和 c2 必须是相同类型的容器并且保存相同类型的元素
* 元素类型要支持关系运算符

## [练习9.18](exercise9_18.cpp)

> 编写程序，从标准输入读取string序列，存入一个deque中。编写一个循环，用迭代器打印deque中的元素。

## 练习9.19

> 重写上一题的程序，用list替代deque。列出程序要做出哪些改变。

只需要在声明上做出改变即可，其他都不变。
```cpp
deque<string> input; 
//改为
list<string> input;
```

## [练习9.20](exercise9_20.cpp)

> 编写程序，从一个list<int>拷贝元素到两个deque中。值为偶数的所有元素都拷贝到一个deque中，而奇数值元素都拷贝到另一个deque中。

## 练习9.21

> 如果我们将第308页中使用 insert 返回值将元素添加到list中的循环程序改写为将元素插入到vector中，分析循环将如何工作。

一样的。如书上所说：
> 第一次调用 `insert` 会将我们刚刚读入的 `string` 插入到 `iter` 所指向的元素之前的位置。`insert` 返回的迭代器恰好指向这个新元素。我们将此迭代器赋予 `iter` 并重复循环，读取下一个单词。只要继续有单词读入，每步 while 循环就会将一个新元素插入到 `iter` 之前，并将 `iter` 改变为新加入元素的尾置。此元素为（新的）首元素。因此，每步循环将一个元素插入到 `list` 首元素之前的位置。

## 练习9.22

> 假定iv是一个int的vector，下面的程序存在什么错误？你将如何修改？
```cpp
vector<int>::iterator iter = iv.begin(),
					  mid = iv.begin() + iv.size() / 2;
while (iter != mid)
	if (*iter == some_val)
		iv.insert(iter, 2 * some_val);
```

* 循环不会结束
* 迭代器可能会失效

要改为下面这样：
```cpp
while (iter != mid)
{
	if (*iter == some_val)
	{
		iter = v.insert(iter, 2 * some_val);
		++iter;
    }
	++iter;
}
```

## 练习9.23

> 在本节第一个程序中，若 c.size() 为1，则val、val2、val3和val4的值会是什么？

都会是同一个值（容器中仅有的那个）。

## [练习9.24](exercise9_24.cpp)

> 编写程序，分别使用 at、下标运算符、front 和 begin 提取一个vector中的第一个元素。在一个空vector上测试你的程序。

## 练习9.25

> 对于第312页中删除一个范围内的元素的程序，如果 elem1 与 elem2 相等会发生什么？如果 elem2 是尾后迭代器，或者 elem1 和 elem2 皆为尾后迭代器，又会发生什么？

* 如果 elem1 和 elem2 相等，那么不会发生任何操作。
* 如果elem2 是尾后迭代器，那么删除从 elem1 到最后的元素。
* 如果两者皆为尾后迭代器，也什么都不会发生。

## 练习9.26

> 使用下面代码定义的ia，将ia 拷贝到一个vector和一个list中。是用单迭代器版本的erase从list中删除奇数元素，从vector中删除偶数元素。
```cpp
int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
```

```cpp
vector<int> vec(ia, end(ia));
list<int> lst(vec.begin(), vec.end());

for (auto it = lst.begin(); it != lst.end(); )
	if (*it & 0x1)
		it = lst.erase(it);
	else 
		++it;

for (auto it = vec.begin(); it != vec.end(); )
	if (!(*it & 0x1))
		it = vec.erase(it);
	else
		++it;			
```

## [练习9.27](exercise9_27.cpp)

> 编写程序，查找并删除forward_list<int>中的奇数元素。

## 练习9.28

> 编写函数，接受一个forward_list<string>和两个string共三个参数。函数应在链表中查找第一个string，并将第二个string插入到紧接着第一个string之后的位置。若第一个string未在链表中，则将第二个string插入到链表末尾。

```cpp
void find_and_insert(forward_list<string>& flst, const string& s1, const string& s2)
{
	auto prev = flst.before_begin();
	auto curr = flst.begin();
	while (curr != flst.end())
	{
		if (*curr == s1)
		{
			flst.insert_after(curr, s2);
			return;
	    }
	    prev = curr;
	    ++curr;
    }
    flst.insert_after(prev, s2);
}
```

## 练习9.29

> 假定vec包含25个元素，那么vec.resize(100)会做什么？如果接下来调用vec.resize(10)会做什么？

* 将75个值为0的元素添加到vec的末尾
* 从vec的末尾删除90个元素

## 练习9.30

> 接受单个参数的resize版本对元素类型有什么限制（如果有的话）？

元素类型必须提供一个默认构造函数。

## 练习9.31

> 第316页中删除偶数值元素并复制奇数值元素的程序不能用于list或forward_list。为什么？修改程序，使之也能用于这些类型。

```cpp
iter += 2;
```
因为复合赋值语句只能用于 string、vector、deque、array，所以要改为：
```cpp
++iter;
++iter;
```
如果是forward_list的话，要增加一个首先迭代器 prev：
```cpp
auto prev = flst.before_begin();
//...
curr == flst.insert_after(prev, *curr);
++curr; ++curr;
++prev; ++prev;
```

## 练习9.32

> 在第316页的程序中，向下面语句这样调用insert是否合法？如果不合法，为什么？
```cpp
iter = vi.insert(iter, *iter++);
```

不合法。因为参数的求值顺序是未指定的。

## [练习9.33](exercise9_33.cpp)

> 在本节最后一个例子中，如果不将insert的结果赋予begin，将会发生什么？编写程序，去掉此赋值语句，验证你的答案。

begin 将会失效。

## [练习9.34](exercise9_34.cpp)

> 假定vi是一个保存int的容器，其中有偶数值也有奇数值，分析下面循环的行为，然后编写程序验证你的分析是否正确。
```cpp
iter = vi.begin();
while (iter != vi.end())
	if (*iter % 2)
		iter = vi.insert(iter, *iter);
	++iter;
```

循环永远不会结束。

## 练习9.35

> 解释一个vector的capacity和size有何区别。

* capacity 的值表明，在不重新分配内存空间的情况下，容器可以保存多少元素
* 而 size 的值是指容器已经保存的元素的数量

## 练习9.36

> 一个容器的capacity可能小于它的size吗？

不可能。

## 练习9.37

> 为什么list或array没有capacity成员函数？

因为 list 是链表，而 array 不允许改变容器大小。

## [练习9.38](exercise9_38.cpp)

> 编写程序，探究在你的标准实现中，vector是如何增长的。

```
capacity: 0  size: 0
capacity: 1  size: 1
capacity: 2  size: 2
capacity: 3  size: 3
capacity: 4  size: 4
capacity: 6  size: 5
capacity: 6  size: 6
capacity: 9  size: 7
capacity: 9  size: 8
capacity: 9  size: 9
capacity: 13  size: 10
capacity: 13  size: 11
capacity: 13  size: 12
capacity: 13  size: 13
capacity: 19  size: 14
capacity: 19  size: 15
capacity: 19  size: 16
capacity: 19  size: 17
capacity: 19  size: 18
capacity: 19  size: 19
capacity: 28  size: 20
capacity: 28  size: 21
capacity: 28  size: 22
capacity: 28  size: 23
capacity: 28  size: 24
capacity: 28  size: 25
capacity: 28  size: 26
capacity: 28  size: 27
capacity: 28  size: 28
capacity: 42  size: 29
capacity: 42  size: 30
capacity: 42  size: 31
capacity: 42  size: 32
capacity: 42  size: 33
capacity: 42  size: 34
capacity: 42  size: 35
capacity: 42  size: 36
capacity: 42  size: 37
capacity: 42  size: 38
capacity: 42  size: 39
capacity: 42  size: 40
capacity: 42  size: 41
capacity: 42  size: 42
capacity: 63  size: 43
capacity: 63  size: 44
capacity: 63  size: 45
capacity: 63  size: 46
capacity: 63  size: 47
capacity: 63  size: 48
capacity: 63  size: 49
capacity: 63  size: 50
capacity: 63  size: 51
capacity: 63  size: 52
capacity: 63  size: 53
capacity: 63  size: 54
capacity: 63  size: 55
capacity: 63  size: 56
capacity: 63  size: 57
capacity: 63  size: 58
capacity: 63  size: 59
capacity: 63  size: 60
capacity: 63  size: 61
capacity: 63  size: 62
capacity: 63  size: 63
capacity: 94  size: 64
capacity: 94  size: 65
capacity: 94  size: 66
capacity: 94  size: 67
capacity: 94  size: 68
capacity: 94  size: 69
capacity: 94  size: 70
capacity: 94  size: 71
capacity: 94  size: 72
capacity: 94  size: 73
capacity: 94  size: 74
capacity: 94  size: 75
capacity: 94  size: 76
capacity: 94  size: 77
capacity: 94  size: 78
capacity: 94  size: 79
capacity: 94  size: 80
capacity: 94  size: 81
capacity: 94  size: 82
capacity: 94  size: 83
capacity: 94  size: 84
capacity: 94  size: 85
capacity: 94  size: 86
capacity: 94  size: 87
capacity: 94  size: 88
capacity: 94  size: 89
capacity: 94  size: 90
capacity: 94  size: 91
capacity: 94  size: 92
capacity: 94  size: 93
capacity: 94  size: 94
capacity: 141  size: 95
capacity: 141  size: 96
capacity: 141  size: 97
capacity: 141  size: 98
capacity: 141  size: 99
请按任意键继续. . .
```

## 练习9.39

> 解释下面程序片段做了什么：
```cpp
vector<string> svec;
svec.reserve(1024);
string word;
while (cin >> word)
	svec.push_back(word);
svec.resize(svec.size() + svec.size() / 2);
```

定义一个 vector，为它分配1024个元素的空间。然后通过一个循环从标准输入中读取字符串并添加到vector当中。循环结束后，改变vector的容器大小（元素数量）为原来的1.5倍，使用元素的默认初始化值填充。如果容器的大小超过1024，vector也会重新分配空间以容纳新增的元素。

## 练习9.40

> 如果上一题的程序读入了256个词，在resize之后容器的capacity可能是多少？如果读入了512个、1000个、或1048个呢？

* 如果读入了256个词，capacity 仍然是 1024
* 如果读入了512个词，capacity 仍然是 1024
* 如果读入了1000或1048个词，capacity 取决于具体实现。

## 练习9.41

> 编写程序，从一个vector<char>初始化一个string。

```cpp
    vector<char> v{ 'h', 'e', 'l', 'l', 'o' };
    string str(v.cbegin(), v.cend());
```

## 练习9.42

> 假定你希望每次读取一个字符存入一个string中，而且知道最少需要读取100个字符，应该如何提高程序的性能？

使用 `reserve(100)` 函数预先分配100个元素的空间。

## [练习9.43](exercise9_43.cpp)

> 编写一个函数，接受三个string参数是s、oldVal 和newVal。使用迭代器及insert和erase函数将s中所有oldVal替换为newVal。测试你的程序，用它替换通用的简写形式，如，将"tho"替换为"though",将"thru"替换为"through"。

## [练习9.44](exercise9_44.cpp)

> 重写上一题的函数，这次使用一个下标和replace。

## [练习9.45](exercise9_45.cpp)

> 编写一个函数，接受一个表示名字的string参数和两个分别表示前缀（如"Mr."或"Mrs."）和后缀（如"Jr."或"III"）的字符串。使用迭代器及insert和append函数将前缀和后缀添加到给定的名字中，将生成的新string返回。

## [练习9.46](exercise9_46.cpp)

> 重写上一题的函数，这次使用位置和长度来管理string，并只使用insert。

## [练习9.47](exercise9_47.cpp)

> 编写程序，首先查找string"ab2c3d7R4E6"中每个数字字符，然后查找其中每个字母字符。编写两个版本的程序，第一个要使用find_first_of，第二个要使用find_first_not_of。

## 练习9.48

> 假定name和numbers的定义如325页所示，numbers.find(name)返回什么？

返回 `string::npos`

## [练习9.49](exercise9_49.cpp)

> 如果一个字母延伸到中线之上，如d 或 f，则称其有上出头部分（ascender）。如果一个字母延伸到中线之下，如p或g，则称其有下出头部分（descender）。编写程序，读入一个单词文件，输出最长的既不包含上出头部分，也不包含下出头部分的单词。

## [练习9.50](exercise9_50.cpp)

> 编写程序处理一个vector<string>，其元素都表示整型值。计算vector中所有元素之和。修改程序，使之计算表示浮点值的string之和。

## [练习9.51](exercise9_51.cpp)

> 设计一个类，它有三个unsigned成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的string参数。你的构造函数应该能处理不同的数据格式，如January 1,1900、1/1/1990、Jan 1 1900 等。

## [练习9.52](exercise9_52.cpp)

> 使用stack处理括号化的表达式。当你看到一个左括号，将其记录下来。当你在一个左括号之后看到一个右括号，从stack中pop对象，直至遇到左括号，将左括号也一起弹出栈。然后将一个值（括号内的运算结果）push到栈中，表示一个括号化的（子）表达式已经处理完毕，被其运算结果所替代。

这道题可以延伸为逆波兰求值，以及中缀转后缀表达式。 