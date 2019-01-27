## 练习18.1

> 在下列 throw 语句中异常对象的类型是什么？
```cpp
(a) range_error r("error");
	throw r;
(b) exception *p = &r;
	throw *p;
```

## 练习18.2

> 当在指定的位置发生了异常时将出现什么情况？
```cpp
void exercise(int *b, int *e)
{
	vector<int> v(b, e);
	int *p = new int[v.size()];
	ifstream in("ints");
	//此处发生异常
}
```

## 练习18.3

> 要想让上面的代码在发生异常时能正常工作，有两种解决方案。请描述这两种方法并实现它们。

## 练习18.4

> 查看图18.1所示的继承体系，说明下面的 try 块有何错误并修改它。
```cpp
try {
	// 使用 C++ 标准库
} catch (exception) {
	// ...
} catch (const runtime_error &re) {
	// ...
} catch (overflow_error eobj) { /* ... */ }
```

## 练习18.5

> 修改下面的main函数，使其能捕获图18.1所示的任何异常类型：
```cpp
int main(){
	// 使用 C++标准库
}
```
处理代码应该首先打印异常相关的错误信息，然后调用 abort 终止函数。

## 练习18.6

> 已知下面的异常类型和 catch 语句，书写一个 throw 表达式使其创建的异常对象能被这些catch语句捕获：
```cpp
(a) class exceptionType { };
	catch(exceptionType *pet) { }
(b) catch(...) { }
(c) typedef int EXCPTYPE;
	catch(EXCPTYPE) { }
```

## 练习18.7

> 根据第16章的介绍定义你自己的Blob 和 BlobPtr，注意将构造函数写成函数try语句块。

## 练习18.8

> 回顾你之前编写的各个类，为它们的构造函数和析构函数添加正确的异常说明。如果你认为某个析构函数可能抛出异常，尝试修改代码使得该析构函数不会抛出异常。

## 练习18.9

> 定义本节描述的书店程序异常类，然后为 Sales_data 类重新编写一个复合赋值运算符并令其抛出一个异常。

## 练习18.10

> 编写程序令其对两个 ISBN 编号不相同的对象执行 Sales_data 的加法运算。为该程序编写两个不同的版本：一个处理异常，另一个不处理异常。观察并比较这两个程序的行为，用心体会当出现了一个未被捕获的异常时程序会发生什么情况。

## 练习18.11

> 为什么 what 函数不应该抛出异常？

## 练习18.12

> 将你为之前各章练习编写的程序放置在各自的命名空间中。也就是说，命名空间chapter15包含Query程序的代码，命名空间chapter10包含TextQuery的代码；使用这种结构重新编译Query代码实例。

## 练习18.13

> 什么时候应该使用未命名的命名空间？

## 练习18.14

> 假设下面的operator*声明的是嵌套的命名空间 mathLib::MatrixLib 的一个成员：
```cpp
namespace mathLib {
	namespace MatrixLib {
		class matrix { /* ... */ };
		matrix operator* (const matrix &, const matrix &);
		// ...
	}
}
```
请问你应该如何在全局作用域中声明该运算符？

## 练习18.15

> 说明 using 指示与 using 声明的区别。

## 练习18.16

> 假定在下面的代码中标记为“位置1”的地方是对命名空间 Exercise中所有成员的using声明，请解释代码的含义。如果这些using声明出现在“位置2”又会怎样呢？将using声明变为using指示，重新回答之前的问题。
```cpp
namespace Exercise {
	int ivar = 0;
	double dvar = 0;
	const int limit = 1000;
}
int ivar = 0;
//位置1
void main() {
	//位置2
	double dvar = 3.1416;
	int iobj = limit + 1;
	++ivar;
	++::ivar;
}
```

## 练习18.17

> 实际编写代码检验你对上一题的回答是否正确。

## 练习18.18

> 已知有下面的 swap 的典型定义，当 mem1 是一个 string 时程序使用 swap 的哪个版本？如果 mem1 是 int 呢？说明在这两种情况下名字查找的过程。
```cpp
void swap(T v1, T v2)
{
	using std::swap;
	swap(v1.mem1, v2.mem1);
	//交换类型的其他成员
}
```

## 练习18.19

> 如果对 swap 的调用形如 std::swap(v1.mem1, v2.mem1) 将会发生什么情况？

## 练习18.20

> 在下面的代码中，确定哪个函数与compute调用匹配。列出所有候选函数和可行函数，对于每个可行函数的实参与形参的匹配过程来说，发生了哪种类型转换？
```cpp
namespace primerLib {
	void compute();
	void compute(const void *);
}
using primerLib::compute;
void compute(int);
void compute(double, double = 3.4);
void compute(char*, char* = 0);
void f()
{
	compute(0);
}
```

## 练习18.21

> 解释下列声明的含义，在它们当作存在错误吗？如果有，请指出来并说明错误的原因。
```cpp
(a) class CADVehicle : public CAD, Vehicle { ... };
(b) class DbiList : public List, public List { ... };
(c) class iostream : public istream, public ostream { ... };
```

## 练习18.22

> 已知存在如下所示的类的继承体系，其中每个类都定义了一个默认构造函数：
```cpp
class A { ... };
class B : public A { ... };
class C : public B { ... };
class X { ... };
class Y { ... };
class Z : public X, public Y { ... };
class MI : public C, public Z { ... };
```
对于下面的定义来说，构造函数的执行顺序是怎样的？
```cpp
MI mi;
```

## 练习18.23

> 使用练习18.22的继承体系以及下面定义的类 D，同时假定每个类都定义了默认构造函数，请问下面的哪些类型转换是不被允许的？
```cpp
class D : public X, public C { ... };
p *pd = new D;
(a) X *px = pd;
(b) A *pa = pd;
(c) B *pb = pd;
(d) C *pc = pd;
```

## 练习18.24

> 在第714页，我们使用一个指向 Panda 对象的 Bear 指针进行了一系列调用，假设我们使用的是一个指向 Panda 对象的 ZooAnimal 指针将会发生什么情况，请对这些调用语句逐一进行说明。

## 练习18.25

> 假设我们有两个基类 Base1 和 Base2，它们各自定义了一个名为 print 的虚成员和一个虚析构函数。从这两个基类中文名派生出下面的类，它们都重新定义了 print 函数：
```cpp
class D1 : public Base1 { /* ... */};
class D2 : public Base2 { /* ... */};
class MI : public D1, public D2 { /* ... */};
```
通过下面的指针，指出在每个调用中分别使用了哪个函数：
```cpp
Base1 *pb1 = new MI;
Base2 *pb2 = new MI;
D1 *pd1 = new MI;
D2 *pd2 = new MI;
(a) pb1->print();
(b) pd1->print();
(c) pd2->print();
(d) delete pb2;
(e) delete pd1;
(f) delete pd2;
```

```cpp
struct Base1 {
	void print(int) const;
protected:
	int ival;
	double dval;
	char cval;
private:
	int *id;
};
struct Base2 {
	void print(double) const;
protected:
	double fval;
private:
	double dval;
};
struct Derived : public Base1 {
	void print(std::string) const;
protected:
	std::string sval;
	double dval;
};
struct MI : public Derived, public Base2 {
	void print(std::vector<double>);
protected:
	int *ival;
	std::vector<double> dvec;
};
```

## 练习18.26

> 已知如上所示的继承体系，下面对print的调用为什么是错误的？适当修改MI，令其对print的调用可以编译通过并正确执行。
```cpp
MI mi;
mi.print(42);
```

## 练习18.27

> 已知如上所示的继承体系，同时假定为MI添加了一个名为foo的函数：
```cpp
int ival;
double dval;
void MI::foo(double cval)
{
	int dval;
	//练习中的问题发生在此处
}
(a) 列出在MI::foo中可见的所有名字。
(b) 是否存在某个可见的名字是继承自多个基类的？
(c) 将Base1的dval成员与Derived 的dval 成员求和后赋给dval的局部实例。
(d) 将MI::dvec的最后一个元素的值赋给Base2::fval。
(e) 将从Base1继承的cval赋给从Derived继承的sval的第一个字符。
```

## 练习18.28

> 已知存在如下的继承体系，在 VMI 类的内部哪些继承而来的成员无须前缀限定符就能直接访问？哪些必须有限定符才能访问？说明你的原因。
```cpp
struct Base {
	void bar(int);
protected:
	int ival;
};
struct Derived1 : virtual public Base {
	void bar(char);
	void foo(char);
protected:
	char cval;
};
struct Derived2 : virtual public Base {
	void foo(int);
protected:
	int ival;
	char cval;
};
class VMI : public Derived1, public Derived2 { };
```

## 练习18.29

> 已知有如下所示的类继承关系：
```cpp
class Class { ... };
class Base : public Class { ... };
class D1 : virtual public Base { ... };
class D2 : virtual public Base { ... };
class MI : public D1, public D2 { ... };
class Final : public MI, public Class { ... };
(a) 当作用于一个Final对象时，构造函数和析构函数的执行次序分别是什么？
(b) 在一个Final对象中有几个Base部分？几个Class部分？
(c) 下面的哪些赋值运算符将造成编译错误？
Base *pb; Class *pc; MI *pmi; D2 *pd2;
(a) pb = new Class;
(b) pc = new Final;
(c) pmi = pb;
(d) pd2 = pmi;
```

## 练习18.30

> 在Base中定义一个默认构造函数、一个拷贝构造函数和一个接受int形参的构造函数。在每个派生类中分别定义这三种构造函数，每个构造函数应该使用它的形参初始化其Base部分。