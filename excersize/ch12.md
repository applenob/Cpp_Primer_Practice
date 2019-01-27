## 练习12.1

> 在此代码的结尾，b1 和 b2 各包含多少个元素？
```cpp
StrBlob b1;
{
	StrBlob b2 = {"a", "an", "the"};
	b1 = b2;
	b2.push_back("about");
}
```

它们实际操作的是同一个vector，都包含4个元素。在代码的结尾，b2 被析构了，不影响 b1 的元素。

## 练习12.2 : [头文件](exercise12_2.h) | [主函数](exercise12_2.cpp)

> 编写你自己的StrBlob 类，包含const 版本的 front 和 back。

## 练习12.3

> StrBlob 需要const 版本的push_back 和 pop_back吗？如需要，添加进去。否则，解释为什么不需要。

不需要。`push_back` 和 `pop_back` 会改变对象的内容。而 const 对象是只读的，因此不需要。

## 练习12.4

> 在我们的 check 函数中，没有检查 i 是否大于0。为什么可以忽略这个检查？

因为 size_type 是一个无符号整型，当传递给 check 的参数小于 0 的时候，参数值会转换成一个正整数。

## 练习12.5

> 我们未编写接受一个 initializer_list explicit 参数的构造函数。讨论这个设计策略的优点和缺点。

构造函数不是 explicit 的，意味着可以从 initializer_list 隐式转换为 StrBlob。在 StrBlob 对象中，只有一个数据成员 data，而 StrBlob 对象本身的含义，也是一个**管理字符串的序列**。因此，从 initializer_list 到 StrBlob 的转换，在逻辑上是可行的。而这个设计策略的缺点，可能在某些地方我们确实需要 initializer_list，而编译器仍会将之转换为 StrBlob。

## [练习12.6](exercise12_6.cpp)

> 编写函数，返回一个动态分配的 int 的vector。将此vector 传递给另一个函数，这个函数读取标准输入，将读入的值保存在 vector 元素中。再将vector传递给另一个函数，打印读入的值。记得在恰当的时刻delete vector。

## [练习12.7](exercise12_7.cpp)

> 重做上一题，这次使用 shared_ptr 而不是内置指针。

## 练习12.8

> 下面的函数是否有错误？如果有，解释错误原因。
```cpp
bool b() {
	int* p = new int;
	// ...
	return p;
}
```

有错误。没有释放指针 p 。

## 练习12.9

> 解释下面代码执行的结果。
```cpp
int *q = new int(42), *r = new int(100);
r = q;
auto q2 = make_shared<int>(42), r2 = make_shared<int>(100);
r2 = q2;
```

r 和 q 指向 42，而之前 r 指向的 100 的内存空间并没有被释放，因此会发生内存泄漏。r2 和 q2 都是智能指针，当对象空间不被引用的时候会自动释放。

## 练习12.10

> 下面的代码调用了第413页中定义的process 函数，解释此调用是否正确。如果不正确，应如何修改？
```cpp
shared_ptr<int> p(new int(42));
process(shared_ptr<int>(p));
```

正确。`shared_ptr<int>(p)` 会创建一个临时的智能指针，这个智能指针与 p 引用同一个对象，此时引用计数为 2。当表达式结束时，临时的智能指针被销毁，此时引用计数为 1。

## 练习12.11

> 如果我们像下面这样调用 process，会发生什么？
```cpp
process(shared_ptr<int>(p.get()));
```

这样会创建一个新的智能指针，它的引用计数为 1，这个智能指针所指向的空间与 p 相同。在表达式结束后，这个临时智能指针会被销毁，引用计数为 0，所指向的内存空间也会被释放。而导致 p 所指向的空间被释放，使得 p 成为一个空悬指针。

## 练习12.12

> p 和 sp 的定义如下，对于接下来的对 process 的每个调用，如果合法，解释它做了什么，如果不合法，解释错误原因：
```cpp
auto p = new int();
auto sp = make_shared<int>();
(a) process(sp);
(b) process(new int());
(c) process(p);
(d) process(shared_ptr<int>(p));
```

* (a) 合法。将sp 拷贝给 process函数的形参，在函数里面引用计数为 2，函数结束后引用计数为 1。
* (b) 不合法。不能从内置指针隐式转换为智能指针。
* (c) 不合法。不能从内置指针隐式转换为智能指针。
* (d) 合法。但是智能指针和内置指针一起使用可能会出现问题，在表达式结束后智能指针会被销毁，它所指向的对象也被释放。而此时内置指针 p 依旧指向该内存空间。之后对内置指针 p 的操作可能会引发错误。

## 练习12.13

> 如果执行下面的代码，会发生什么？
```cpp
auto sp = make_shared<int>();
auto p = sp.get();
delete p;
```

智能指针 sp 所指向空间已经被释放，再对 sp 进行操作会出现错误。

## [练习12.14](exercise12_14.cpp)

> 编写你自己版本的用 shared_ptr 管理 connection 的函数。

## [练习12.15](exercise12_15.cpp)

> 重写第一题的程序，用 lambda 代替end_connection 函数。

## [练习12.16](exercise12_16.cpp)

> 如果你试图拷贝或赋值 unique_ptr，编译器并不总是能给出易于理解的错误信息。编写包含这种错误的程序，观察编译器如何诊断这种错误。

**尝试引用已删除的函数.**

## 练习12.17

> 下面的 unique_ptr 声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。
```cpp
int ix = 1024, *pi = &ix, *pi2 = new int(2048);
typedef unique_ptr<int> IntP;
(a) IntP p0(ix);
(b) IntP p1(pi);
(c) IntP p2(pi2);
(d) IntP p3(&ix);
(e) IntP p4(new int(2048));
(f) IntP p5(p2.get());
```

* (a) 不合法。在定义一个 unique_ptr 时，需要将其绑定到一个new 返回的指针上。
* (b) 合法。但是可能会有后续的程序错误。当 p1 被释放时，p1 所指向的对象也被释放，所以导致 pi 成为一个空悬指针。
* (c) 合法。但是也可能会使得 pi2 成为空悬指针。
* (d) 不合法。当 p3 被销毁时，它试图释放一个栈空间的对象。
* (e) 合法。
* (f) 不合法。p5 和 p2 指向同一个对象，当 p5 和 p2 被销毁时，会使得同一个指针被释放两次。

## 练习12.18

> shared_ptr 为什么没有 release 成员？

release 成员的作用是放弃控制权并返回指针，因为在某一时刻只能有一个 unique_ptr 指向某个对象，unique_ptr 不能被赋值，所以要使用 release 成员将一个 unique_ptr 的指针的所有权传递给另一个 unique_ptr。而 shared_ptr 允许有多个 shared_ptr 指向同一个对象，因此不需要 release 成员。

## [练习12.19](exercise12_19.h)

> 定义你自己版本的 StrBlobPtr，更新 StrBlob 类，加入恰当的 friend 声明以及 begin 和 end 成员。

## [练习12.20](exercise12_20.cpp)

> 编写程序，逐行读入一个输入文件，将内容存入一个 StrBlob 中，用一个 StrBlobPtr 打印出 StrBlob 中的每个元素。

## 练习12.21

> 也可以这样编写 StrBlobPtr 的 deref 成员：
```cpp
std::string& deref() const {
	return (*check(curr, "dereference past end"))[curr];
}
```
你认为哪个版本更好？为什么？

原来的版本更好，可读性更高。

## 练习12.22

> 为了能让 StrBlobPtr 使用 const StrBlob，你觉得应该如何修改？定义一个名为ConstStrBlobPtr 的类，使其能够指向 const StrBlob。

构造函数改为接受 `const Strblob &` , 然后给 Strblob 类添加两个 const 成员函数 cbegin 和 cend，返回 ConstStrBlobPtr。

## [练习12.23](exercise12_23.cpp)

> 编写一个程序，连接两个字符串字面常量，将结果保存在一个动态分配的char数组中。重写这个程序，连接两个标准库string对象。

## [练习12.24](exercise12_24.cpp)

> 编写一个程序，从标准输入读取一个字符串，存入一个动态分配的字符数组中。描述你的程序如何处理变长输入。测试你的程序，输入一个超出你分配的数组长度的字符串。

## 练习12.25

> 给定下面的new表达式，你应该如何释放pa？
```cpp
int *pa = new int[10];
```

```cpp
delete [] pa;
```

## [练习12.26](exercise12_26.cpp)

> 用 allocator 重写第427页中的程序。

## 练习12.27 : [头文件](exercise12_27.h) | [实现](exercise12_27.cpp) | [主函数](exercise12_27_main.cpp)

> TextQuery 和 QueryResult 类只使用了我们已经介绍过的语言和标准库特性。不要提前看后续章节内容，只用已经学到的知识对这两个类编写你自己的版本。

## [练习12.28](exercise12_28.cpp)

> 编写程序实现文本查询，不要定义类来管理数据。你的程序应该接受一个文件，并与用户交互来查询单词。使用vector、map 和 set 容器来保存来自文件的数据并生成查询结果。

## 练习12.29

> 我们曾经用do while 循环来编写管理用户交互的循环。用do while 重写本节程序，解释你倾向于哪个版本，为什么？

```cpp
do {
    std::cout << "enter word to look for, or q to quit: ";
    string s;
    if (!(std::cin >> s) || s == "q") break;
    print(std::cout, tq.query(s)) << std::endl;
} while ( true );
```
我更喜欢 while，这可能是习惯的问题。

## 练习12.30 : [头文件](exercise12_27.h) | [实现](exercise12_27.cpp) | [主函数](exercise12_27_main.cpp)

> 定义你自己版本的 TextQuery 和 QueryResult 类，并执行12.3.1节中的runQueries 函数。

## 练习12.31

> 如果用vector 代替 set 保存行号，会有什么差别？哪个方法更好？为什么？

如果用 vector 则会有单词重复的情况出现。而这里保存的是行号，不需要重复元素，所以 set 更好。

## 练习12.32

> 重写 TextQuery 和 QueryResult类，用StrBlob 代替 vector<string> 保存输入文件。

TextQuery 和 QueryResult 类中的 file 成员，改为 指向 StrBlob 的智能指针。在访问 StrBlob 时，要使用 StrBlobPtr 。

## 练习12.33

> 在第15章中我们将扩展查询系统，在 QueryResult 类中将会需要一些额外的成员。添加名为 begin 和 end 的成员，返回一个迭代器，指向一个给定查询返回的行号的 set 中的位置。再添加一个名为 get_file 的成员，返回一个 shared_ptr，指向 QueryResult 对象中的文件。

```cpp
class QueryResult{
public:
	using Iter = std::set<line_no>::iterator;	
	// ...
	Iter begin() const { return lines->begin(); }
	Iter end() const { return lines->end(); }
	shared_ptr<std::vector<std::string>> get_file() const 
	{ 
		return std::make_shared<std::vector<std::string>>(file); 
	}
private:
	// ...
};
```