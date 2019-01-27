## 练习19.1

> 使用 malloc 编写你自己的 operator new(sizt_t)函数，使用 free 编写operator delete(void *)函数。

## 练习19.2

> 默认情况下，allocator 类使用 operator new 获取存储空间，然后使用 operator delete 释放它。利用上一题中的两个函数重新编译并运行你的 StrVec 程序。

## 练习19.3

> 已知存在如下的类继承体系，其中每个类分别定义了一个公有的默认构造函数和一个析构函数：
```cpp
class A { /* ... */};
class B : public A { /* ... */};
class C : public B { /* ... */};
class D : public B, public A { /* ... */};
```
下面哪个 dynamic_cast 将失败？
```cpp
(a) A *pa = new C;
	B *pb = dynamic_cast<B*>(pa);
(b) B *pb = new B;
	C *pc = dynamic_cast<C*>(pb);
(c) A *pa = new D;
	B *pb = dynamic_cast<B*>(pa);
```

## 练习19.4

> 使用上一个练习定义的类改写下面的代码，将表达式*pa 转换成类型C&：
```cpp
if (C *pc = dynamic_cast<C*>(pa))
{
	//使用C的成员
} else {
	//使用A的成员
}
```

## 练习19.5

> 在什么情况下你应该用 dynamic_cast 替代虚函数？

## 练习19.6

> 编写一条表达式将 Query_base 指针动态转换为 AndQuery 指针。分别使用 AndQuery 的对象以及其他类型的对象测试转换是否有效。打印一条表示类型转换是否成功的信息，确保实际输出的结果与期望的一致。

## 练习19.7

> 编写与上一个练习类似的转换，这一次将 Query_base 对象转换为 AndQuery 的引用。重复上面的测试过程，确保转换能正常工作。

## 练习19.8

> 编写一条 typeid 表达式检查两个 Query_base 对象是否指向同一种类型。再检查该类型是否是 AndQuery。

## 练习19.9

> 编写与本节最后一个程序类似的代码，令其打印你的编译器为一些常见类型所起的名字。如果你得到的输出结果与本书类似，尝试编写一个函数将这些字符串翻译成人们更容易读懂的形式。

## 练习19.10

> 已知存在如下的类继承体系，其中每个类定义了一个默认公有的构造函数和一个虚析构函数。下面的语句将打印哪些类型名字？
```cpp
class A { /* ... */ };
class B : public A { /* ... */ };
class C : public B { /*...*/ };
(a) A *pa = new C;
	cout << typeid(pa).name() << endl;
(b) C cobj;
	A& ra = cobj;
	cout << typeid(&ra).name() << endl;
(c) B *px = new B;
	A& ra = *px;
	cout << typeid(ra).name() << endl;
```

## 练习19.11

> 普通的数据指针和指向数据成员的指针有何区别？

## 练习19.12

> 定义一个成员指针，令其可以指向 Screen 类的 cursor 成员。通过该指针获得 Screen::cursor 的值。

## 练习19.13

> 定义一个类型，使其可以表示指向 Sales_data 类的 bookNo 成员的指针。

## 练习19.14

> 下面的代码合法吗？如果合法，代码的含义是什么？如果不合法，解释原因。
```cpp
auto pmf = &Screen::get_cursor;
pmf = &Screen::get;
```

## 练习19.15

> 普通函数指针和指向成员函数的指针有何区别？

## 练习19.16

> 声明一个类型别名，令其作为指向 Sales_data 的 avg_price 成员的指针的同义词。

## 练习19.17

> 为 Screen 的所有成员函数类型各定义一个类型别名。

## 练习19.18

> 编写一个函数，使用 count_if 统计在给定的 vector 中有多少个空 string。

## 练习19.19

> 编写一个函数，令其接受vector<Sales_data>并查找平均价格高于某个值的第一个元素。

## 练习19.20

> 将你的 QueryResult 类嵌套在 TextQuery 中，然后重新运行12.3.2节中使用了 TextQuery 的程序。

## 练习19.21

> 编写你自己的 Token 类。

## 练习19.22

> 为你的 Token 类添加一个 Sales_data 类型的成员。

## 练习19.23

> 为你的 Token 类添加移动构造函数和移动赋值运算符。

## 练习19.24

> 如果我们将一个 Token 对象付给它自己将发生什么情况？

## 练习19.25

> 编写一系列赋值运算符，令其分别接收 union 中各种类型的值。

## 练习19.26

> 说明下列声明语句的含义并判断它们是否合法：
```cpp
extern "C" int compute(int *, int);
extern "C" double compute(double *, double);
```