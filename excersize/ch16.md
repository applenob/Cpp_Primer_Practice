## 练习16.1

> 给出实例化的定义。

当编译器实例化一个模版时，它使用实际的模版参数代替对应的模版参数来创建出模版的一个新“实例”。

## 练习16.2

> 编写并测试你自己版本的 compare 函数。

```cpp
template<typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs) return -1;
	if (rhs < lhs) return 1;
	return 0;
}
```

## 练习16.3

> 对两个 Sales_data 对象调用你的 compare 函数，观察编译器在实例化过程中如何处理错误。

`error: no match for 'operator<' `

## 练习16.4

> 编写行为类似标准库 find 算法的模版。函数需要两个模版类型参数，一个表示函数的迭代器参数，另一个表示值的类型。使用你的函数在一个 vector<int> 和一个list<string>中查找给定值。

```cpp
template<typename Iterator, typename Value>
Iterator find(Iterator first, Iterator last, const Value& v)
{
	for ( ; first != last && *first != value; ++first);
	return first;
}
```

## 练习16.5

> 为6.2.4节中的print函数编写模版版本，它接受一个数组的引用，能处理任意大小、任意元素类型的数组。

```cpp
template<typename Array>
void print(const Array& arr)
{
	for (const auto& elem : arr)
		std::cout << elem << std::endl;
}
```

## 练习16.6

> 你认为接受一个数组实参的标准库函数 begin 和 end 是如何工作的？定义你自己版本的 begin 和 end。

```cpp
template<typename T, unsigned N>
T* begin(const T (&arr)[N])
{
	return arr;
}

template<typename T, unsigned N>
T* end(const T (&arr)[N])
{
	return arr + N;
}
```

## 练习16.7

> 编写一个 constexpr 模版，返回给定数组的大小。

```cpp
template<typename T, typename N> constexpr
unsigned size(const T (&arr)[N])
{
	return N;
}
```

## 练习16.8

> 在第97页的“关键概念”中，我们注意到，C++程序员喜欢使用 != 而不喜欢 < 。解释这个习惯的原因。

因为大多数类只定义了 != 操作而没有定义 < 操作，使用 != 可以降低对要处理的类型的要求。

## 练习16.9

> 什么是函数模版，什么是类模版？

一个函数模版就是一个公式，可用来生成针对特定类型的函数版本。类模版是用来生成类的蓝图的，与函数模版的不同之处是，编译器不能为类模版推断模版参数类型。如果我们已经多次看到，为了使用类模版，我们必须在模版名后的尖括号中提供额外信息。

## 练习16.10

> 当一个类模版被实例化时，会发生什么？

一个类模版的每个实例都形成一个独立的类。

## 练习16.11

> 下面 List 的定义是错误的。应如何修改它？
```cpp
template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType> &);
	List<elemType>& operator=(const List<elemType> &);
	~List();
	void insert(ListItem *ptr, elemType value);
private:
	ListItem *front, *end;
};
```

模版需要模版参数，应该修改为如下：
```cpp
template <typename elemType> class ListItem;  
template <typename elemType> class List{  
public:  
  	List<elemType>();  
  	List<elemType>(const List<elemType> &);  
  	List<elemType>& operator=(const List<elemType> &);  
  	~List();  
  	void insert(ListItem<elemType> *ptr, elemType value);  
private:  
  	ListItem<elemType> *front, *end;  
};
```	

## 练习16.12

> 编写你自己版本的 Blob 和 BlobPtr 模版，包含书中未定义的多个const成员。

[Blob](blob.h) | [BlobPtr](blobptr.h)

## 练习16.13

> 解释你为 BlobPtr 的相等和关系运算符选择哪种类型的友好关系？

这里需要与类型一一对应，所以就选择一对一友好关系。

## 练习16.14

> 编写 Screen 类模版，用非类型参数定义 Screen 的高和宽。

[Screen](screen.h)

## 练习16.15

> 为你的 Screen 模版实现输入和输出运算符。Screen 类需要哪些友元（如果需要的话）来令输入和输出运算符正确工作？解释每个友元声明（如果有的话）为什么是必要的。

类的 operator<< 和 operator>> 应该是类的友元。

## 练习16.16

> 将 StrVec 类重写为模版，命名为 Vec。

[Vec](vec.h)

## 练习16.17

> 声明为 typename 的类型参数和声明为 class 的类型参数有什么不同（如果有的话）？什么时候必须使用typename？

没有什么不同。当我们希望通知编译器一个名字表示类型时，必须使用关键字 typename，而不能使用 class。

## 练习16.18

> 解释下面每个函数模版声明并指出它们是否非法。更正你发现的每个错误。
```cpp
(a) template <typename T, U, typename V> void f1(T, U, V);
(b) template <typename T> T f2(int &T);
(c) inline template <typename T> T foo(T, unsigned int *);
(d) template <typename T> f4(T, T);
(e) typedef char Ctype;
	template <typename Ctype> Ctype f5(Ctype a);
```

* (a) 非法。应该为 `template <typename T, typename U, typename V> void f1(T, U, V);`。
* (b) 非法。应该为 `template <typename T> T f2(int &t);`
* (c) 非法。应该为 `template <typename T> inline T foo(T, unsigned int*);`
* (d) 非法。应该为 `template <typename T> T f4(T, T);`
* (e) 非法。Ctype 被隐藏了。

## 练习16.19

> 编写函数，接受一个容器的引用，打印容器中的元素。使用容器的 size_type 和 size成员来控制打印元素的循环。

```cpp
template<typename Container>
void print(const Container& c)
{
	for (typename Container::size_type i = 0; i != c.size(); ++i)
		std::cout << c[i] << " ";
}
```

## 练习16.20

> 重写上一题的函数，使用begin 和 end 返回的迭代器来控制循环。

```cpp
template<typename Container>
void print(const Container& c)
{
	for (auto it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
}
```

## 练习16.21

> 编写你自己的 DebugDelete 版本。

[DebugDelete](debugDelete.h)

## 练习16.22

> 修改12.3节中你的 TextQuery 程序，令 shared_ptr 成员使用 DebugDelete 作为它们的删除器。

## 练习16.23

> 预测在你的查询主程序中何时会执行调用运算符。如果你的预测和实际不符，确认你理解了原因。

## 练习16.24

> 为你的 Blob 模版添加一个构造函数，它接受两个迭代器。

```cpp
template<typename T>    //for class
template<typename It>   //for this member
Blob<T>::Blob(It b, It e) :
    data(std::make_shared<std::vector<T>>(b, e))
{ }
```

## 练习16.25

> 解释下面这些声明的含义。
```cpp
extern template class vector<string>;
template class vector<Sales_data>;
```

前者是模版声明，后者是实例化定义。

## 练习16.26

> 假设 NoDefault 是一个没有默认构造函数的类，我们可以显式实例化 vector<NoDefualt>吗？如果不可以，解释为什么。

不可以。如
```cpp
std::vector<NoDefault> vec(10);
```
会使用 NoDefault 的默认构造函数，而 NoDefault 没有默认构造函数，因此是不可以的。

## 练习16.27

> 对下面每条带标签的语句，解释发生了什么样的实例化（如果有的话）。如果一个模版被实例化，解释为什么;如果未实例化，解释为什么没有。
```cpp
template <typename T> class Stack {	};
void f1(Stack<char>); 		//(a)
class Exercise {
	Stack<double> &rds;		//(b)
	Stack<int> si;			//(c)
};
int main() {
	Stack<char> *sc;		//(d)
	f1(*sc);				//(e)
	int iObj = sizeof(Stack<string>);	//(f)
}
```

(a)、(b)、(c)、(f) 都发生了实例化，(d)、(e) 没有实例化。

## 练习16.28

> 编写你自己版本的 shared_ptr 和 unique_ptr。

[shared_ptr](shared_ptr.h) | [unique_ptr](unique_ptr.h)

## 练习16.29

> 修改你的 Blob 类，用你自己的 shared_ptr 代替标准库中的版本。

## 练习16.30

> 重新运行你的一些程序，验证你的 shared_ptr 类和修改后的 Blob 类。（注意：实现 weak_ptr 类型超出了本书范围，因此你不能将BlobPtr类与你修改后的Blob一起使用。）

## 练习16.31

> 如果我们将 DebugDelete 与 unique_ptr 一起使用，解释编译器将删除器处理为内联形式的可能方式。

## 练习16.32

> 在模版实参推断过程中发生了什么？

在模版实参推断过程中，编译器使用函数调用中的实参类型来寻找模版实参，用这些模版实参生成的函数版本与给定的函数调用最为匹配。

## 练习16.33

> 指出在模版实参推断过程中允许对函数实参进行的两种类型转换。

* const 转换：可以将一个非 const 对象的引用（或指针）传递给一个 const 的引用（或指针）形参。
* 数组或函数指针转换：如果函数形参不是引用类型，则可以对数组或函数类型的实参应用正常的指针转换。一个数组实参可以转换为一个指向其首元素的指针。类似的，一个函数实参可以转换为一个该函数类型的指针。

## 练习16.34

> 对下面的代码解释每个调用是否合法。如果合法，T 的类型是什么？如果不合法，为什么？
```cpp
template <class T> int compare(const T&, const T&);
(a) compare("hi", "world");
(b) compare("bye", "dad");
```

* (a) 不合法。`compare(const char [3], const char [6])`, 两个实参类型不一致。
* (b) 合法。`compare(const char [4], const char [4])`.

## 练习16.35

> 下面调用中哪些是错误的（如果有的话）？如果调用合法，T 的类型是什么？如果调用不合法，问题何在？
```cpp
template <typename T> T calc(T, int);
tempalte <typename T> T fcn(T, T);
double d; float f; char c;
(a) calc(c, 'c'); 
(b) calc(d, f);
(c) fcn(c, 'c');
(d) fcn(d, f);
```

* (a) 合法，类型为char
* (b) 合法，类型为double
* (c) 合法，类型为char
* (d) 不合法，这里无法确定T的类型是float还是double

## 练习16.36

> 进行下面的调用会发生什么：
```cpp
template <typename T> f1(T, T);
template <typename T1, typename T2) f2(T1, T2);
int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;
(a) f1(p1, p2);
(b) f2(p1, p2);
(c) f1(cp1, cp2);
(d) f2(cp1, cp2);
(e) f1(p1, cp1);
(f) f2(p1, cp1);
```

* (a) f1(int*, int*);
* (b) f2(int*, int*);
* (c) f1(const int*, const int*);
* (d) f2(const int*, const int*);
* (e) f1(int*, const int*); 这个使用就不合法
* (f) f2(int*, const int*);

## 练习16.37

> 标准库 max 函数有两个参数，它返回实参中的较大者。此函数有一个模版类型参数。你能在调用 max 时传递给它一个 int 和一个 double 吗？如果可以，如何做？如果不可以，为什么？

可以。提供显式的模版实参：
```cpp
int a = 1;
double b = 2;
std::max<double>(a, b);
```

## 练习16.38

> 当我们调用 make_shared 时，必须提供一个显示模版实参。解释为什么需要显式模版实参以及它是如果使用的。

如果不显示提供模版实参，那么 make_shared 无法推断要分配多大内存空间。

## 练习16.39

> 对16.1.1节 中的原始版本的 compare 函数，使用一个显式模版实参，使得可以向函数传递两个字符串字面量。

```cpp
compare<std::string>("hello", "world")  
```

## 练习16.40

> 下面的函数是否合法？如果不合法，为什么？如果合法，对可以传递的实参类型有什么限制（如果有的话）？返回类型是什么？
```cpp
template <typename It>
auto fcn3(It beg, It end) -> decltype(*beg + 0)
{
	//处理序列
	return *beg;
}
```

合法。该类型需要支持 + 操作。

## 练习16.41

> 编写一个新的 sum 版本，它返回类型保证足够大，足以容纳加法结果。

```cpp
template<typename T>
auto sum(T lhs, T rhs) -> decltype( lhs + rhs)
{
    return lhs + rhs;
}

```

## 练习16.42

> 对下面每个调用，确定 T 和 val 的类型：
```cpp
template <typename T> void g(T&& val);
int i = 0; const int ci = i;
(a) g(i);
(b) g(ci);
(c) g(i * ci);
```

* (a) int&
* (b) const int&
* (c) int&&

## 练习16.43

> 使用上一题定义的函数，如果我们调用g(i = ci),g 的模版参数将是什么？

i = ci 返回的是左值，因此 g 的模版参数是 int&

## 练习16.44

> 使用与第一题中相同的三个调用，如果 g 的函数参数声明为 T（而不是T&&），确定T的类型。如果g的函数参数是 const T&呢？

当声明为T的时候，T的类型为int&。
当声明为const T&的时候，T的类型为int&。

## 练习16.45

> 如果下面的模版，如果我们对一个像42这样的字面常量调用g，解释会发生什么？如果我们对一个int 类型的变量调用g 呢？
```cpp
template <typename T> void g(T&& val) { vector<T> v; }
```

当使用字面常量，T将为int。
当使用int变量，T将为int&。编译的时候将会报错，因为没有办法对这种类型进行内存分配，无法创建vector<int&>.

## 练习16.46

> 解释下面的循环，它来自13.5节中的 StrVec::reallocate:
```cpp
for (size_t i = 0; i != size(); ++i)
	alloc.construct(dest++, std::move(*elem++));
```

在每个循环中，对 elem 的解引用操作 * 当中，会返回一个左值，`std::move` 函数将该左值转换为右值，提供给 `construct` 函数。

## 练习16.47

> 编写你自己版本的翻转函数，通过调用接受左值和右值引用参数的函数来测试它。

```cpp
template<typename F, typename T1, typename T2>
void flip(F f, T1&& t1, T2&& t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}
```

## 练习16.48

> 编写你自己版本的 debug_rep 函数。

```cpp
template<typename T> std::string debug_rep(const T& t)
{
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template<typename T> std::string debug_rep(T* p)
{
    std::ostringstream ret;
    ret << "pointer: " << p;

    if(p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";

    return ret.str();
}
```

## 练习16.49

> 解释下面每个调用会发生什么：
```cpp
template <typename T> void f(T);
tempalte <typename T> void f(const T*);
tempalte <typename T> void g(T);
tempalte <typename T> void g(T*);
int i = 42, *p = &i;
const int ci = 0, *p2 = &ci;
g(42); g(p); g(ci); g(p2);
f(42); f(p); f(ci); f(p2);
```

```cpp
    g(42);    	//g(T )
    g(p);     	//g(T*)
    g(ci);      //g(T)   
    g(p2);      //g(T*)    
    f(42);    	//f(T)
    f(p);     	//f(T)
    f(ci);    	//f(T)
    f(p2);      //f(const T*)
```

## 练习16.50

> 定义上一个练习中的函数，令它们打印一条身份信息。运行该练习中的代码。如果函数调用的行为与你预期不符，确定你理解了原因。

## 练习16.51

> 调用本节中的每个 foo，确定 sizeof...(Args) 和 sizeof...(rest)分别返回什么。

## 练习16.52

> 编写一个程序验证上一题的答案。

## 练习16.53

> 编写你自己版本的 print 函数，并打印一个、两个及五个实参来测试它，要打印的每个实参都应有不同的类型。 

```cpp
template<typename Printable>
std::ostream& print(std::ostream& os, Printable const& printable)
{
    return os << printable;
}
// recursion
template<typename Printable, typename... Args>
std::ostream& print(std::ostream& os, Printable const& printable, Args const&... rest)
{
    return print(os << printable << ", ", rest...);
}
```

## 练习16.54

> 如果我们对一个没 << 运算符的类型调用 print，会发生什么？

无法通过编译。

## 练习16.55

> 如果我们的可变参数版本 print 的定义之后声明非可变参数版本，解释可变参数的版本会如何执行。

`error: no matching function for call to 'print(std::ostream&)'`

## 练习16.56

> 编写并测试可变参数版本的 errorMsg。

```cpp
template<typename... Args>
std::ostream& errorMsg(std::ostream& os, const Args... rest)
{
    return print(os, debug_rep(rest)...);
}
```

## 练习16.57

> 比较你的可变参数版本的 errorMsg 和6.2.6节中的 error_msg函数。两种方法的优点和缺点各是什么？

可变参数版本有更好的灵活性。

## 练习16.58

> 为你的 StrVec 类及你为16.1.2节练习中编写的 Vec 类添加 emplace_back 函数。

```cpp
template<typename T>        //for the class  template
template<typename... Args>  //for the member template
inline void
Vec<T>::emplace_back(Args&&...args)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::forward<Args>(args)...);
}
```

## 练习16.59

> 假定 s 是一个 string，解释调用 svec.emplace_back(s)会发生什么。

会在 construst 函数中转发扩展包。

## 练习16.60

> 解释 make_shared 是如何工作的。

make_shared 是一个可变模版函数，它将参数包转发然后构造一个对象，再然后一个指向该对象的智能指针。

## 练习16.61

> 定义你自己版本的 make_shared。

```cpp
   	template <typename T, typename ... Args>
    auto make_shared(Args&&... args) -> std::shared_ptr<T>
    {
        return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
    }
```

## 练习16.62

> 定义你自己版本的 hash<Sales_data>, 并定义一个 Sales_data 对象的 unorder_multise。将多条交易记录保存到容器中，并打印其内容。

## 练习16.63

> 定义一个函数模版，统计一个给定值在一个vecor中出现的次数。测试你的函数，分别传递给它一个double的vector，一个int的vector以及一个string的vector。

## 练习16.64

> 为上一题的模版编写特例化版本来处理vector<const char*>。编写程序使用这个特例化版本。

## 练习16.65

> 在16.3节中我们定义了两个重载的 debug_rep 版本，一个接受 const char* 参数，另一个接受 char * 参数。将这两个函数重写为特例化版本。

## 练习16.66

> 重载debug_rep 函数与特例化它相比，有何优点和缺点？

## 练习16.67

> 定义特例化版本会影响 debug_rep 的函数匹配吗？如果不影响，为什么？