# 第十九章 特殊工具与技术

## 控制内存分配

### 重载new和delete

* **`new`表达式的工作机理**：

```c++
string *sp = new string("a value"); //分配并初始化一个string对象
string *arr = new string[10];   // 分配10个默认初始化的string对象
```

* 上述代码实际执行了**三步操作**：
  * `new`表达式调用一个名为`operator new`(或`operator new []`)的标准库函数，它分配一块**足够大的**、**原始的**、**未命名的**内存空间以便存储特定类型的对象(或对象的数组)。
  * 编译器运行相应的构造函数以构造这些对象，并为其传入初始值。
  * 对象被分配了空间并构造完成，返回一个指向该对象的指针。

* **`delete`表达式的工作机理**：

```c++
delete sp;  // 销毁*sp，然后释放sp指向的内存空间
delete [] arr;  // 销毁数组中的元素，然后释放对应的内存空间
```

* 上述代码实际执行了**两步操作**：
  * 对`sp`所指向的对象或者`arr`所指的数组中的元素执行对应的析构函数。
  * 编译器调用名为`operator delete`(或`operator delete[]`)的标准库函数释放内存空间。
* 当自定义了全局的`operator new`函数和`operator delete`函数后，我们就担负起了控制动态内存分配的职责。这两个函数**必须是正确的**。因为它们是程序整个处理过程中至关重要的一部分。
* 标准库定义了`operator new`函数和`operator delete`函数的8个重载版本：

```c++
// 这些版本可能抛出异常
void *operator new(size_t); // 分配一个对象
void *operator new[](size_t);   // 分配一个数组
void *operator delete(void*) noexcept;  // 释放一个对象
void *operator delete[](void*) noexcept;    // 释放一个数组

// 这些版本承诺不会抛出异常
void *operator new(size_t, nothrow_t&) noexcept;
void *operator new[](size_t, nothrow_t&) noexcept;
void *operator delete(void*, nothrow_t&) noexcept;
void *operator delete[](void*, nothrow_t&) noexcept;
```

* 应用程序可以自定义上面函数版本中的任意一个，前提是自定义的版本必须位于**全局作用域**或者**类作用域**中。
* **注意：** 提供新的`operator new`函数和`operator delete`函数的目的在于改变内存分配的方式，但是不管怎样，都不能改变`new`运算符和`delete`运算符的基本含义。
* 使用从C语言继承的函数`malloc`和`free`函数能实现以某种方式执行分配内存和释放内存的操作：

```c++
#include <cstdlib>

void *operator new(size_t size) {
    if(void *mem = malloc(size))
        return mme;
    else
        throw bad_alloc();
}

void operator delete(void *mem) noexcept {
    free(mem);
}
```

### 定位new表达式

* 应该使用new的定位`new(placement new)`形式传递一个地址，定位`new`的形式如下：

```c++
new (place_address) type
new (place_address) type (initializers)
new (place_address) type [size]
new (place_address) type [size] {braced initializer list}
// place_address必须是一个指针，同时在initializers中提供一个(可能为空的)以逗号分隔的初始值列表，该初始值列表将用于构造新分配的对象。
```

* 当只传入一个指针类型的实参时，定位`new`表达式构造对象但是不分配内存。
* 调用析构函数会销毁对象，但是不会释放内存。

```c++
string *sp = new string("a value"); // 分配并初始化一个string对象
sp->~string();
```

## 运行时类型识别

* 运行时类型识别`(run-time type identification, RTTI)`的功能由两个运算符实现：
  * `typeid`运算符， 用于返回表达式的类型。
  * `dynamic_cast`运算符，用于将基类的指针或引用安全地转换曾派生类的指针或引用。
* 使用`RTTI`必须要加倍小心。在可能的情况下，最好定义虚函数而非直接接管类型管理的重任。

### dynamic_cast运算符

* dynamic_cast运算符的使用形式如下：

```c++
dynamic_cast<type*>(e)  // e必须是一个有效的指针
dynamic_cast<type&>(e)  // e必须是一个左值
dynamic_cast<type&&>(e) // e不能是左值
// 以上，type类型必须时一个类类型，并且通常情况下该类型应该含有虚函数。
// e的类型必须符合三个条件中的任意一个，它们是：
// 1. e的类型是目标type的公有派生类；
// 2. e的类型是目标type的共有基类；
// 3. e的类型就是目标type的类型；

// 指针类型的dynamic_cast
// 假设Base类至少含有一个虚函数，Derived是Base的共有派生类。
if (Derived *dp = dynamic_cast<Derived*>(bp)) {
    // 使用dp指向的Derived对象
} else {    // bp指向一个Base对象
    // 使用dp指向的Base对象
}

// 引用类型的dynamic_cast
void f(const Base &b) {
    try {
        const Derived &d = dynamic_cast<const Derived&>(b);
        // 使用b引用的Derived对象
    } catch (bad_cast) {
        // 处理类型转换失败的情况
    }
}
```

* 可以对一个空指针执行`dynamic_cast`，结果是所需类型的空指针。

### typeid运算符

* `typeid运算符(typeid operator)`，它允许程序向表达式提问：**你的对象是什么类型？**
* `typeid`表达式的形式是`typeid(e)`，其中`e`可以是任意表达式或类型的名字，它操作的结果是一个常量对象的引用。它可以作用于任意类型的表达式。
* 通常情况下，使用typeid比较两条表达式的类型是否相同，或者比较一条表达式的类型是否与指定类型相同：

```c++
Derived *dp = new Derived;
Base *bp = dp;

if (typeid(*bp) == typeid(*dp)) {
    // bp和dp指向同一类型的对象
}

if (typeid(*bp) == typeid(Derived)) {
    // bp实际指向Derived对象
}
```

* 当typeid作用于指针时(而非指针所指向的对象)，返回的结果是该指针的静态编译时类型。

```c++
// 下面的检查永远是失败的：bp的类型是指向Base的指针
if (typeid(bp) == typeid(Derived)) {
    // 永远不会执行
}
```

### 使用RTTI

* 用途：为具有继承关系的类实现相等运算符时。对于两个对象来说，如果它们的类型相同并且对应的数据成员取值相同，则说这两个对象是相等的。

```c++
// 类的层次关系
class Base {
    friend bool operator==(const Base&, const Base&);
public:
    // Base的接口成员
protected:
    virtual bool equal(const Base&) const;
    // Base的数据成员和其他用于实现的成员
};

class Derived: public Base {
public:
    // Derived的其他接口成员
protected:
    bool equal(const Base&) const;
    // Derived的数据成员和其他用于实现的成员
};

// 类型敏感的相等运算符
bool operator==(const Base &lhs, const Base &rhs) {
    // 如果typeid不相同，返回false；否则虚调用equal
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

// 虚equal函数
bool Derived::equal(const Base &rhs) const {
    auto r = dynamic_cast<const Derived&>(rhs);
    // 执行比较两个Derived对象的操作并返回结果
}

// 基类equal函数
bool Base::equal(const Base &rhs) const {
    // 执行比较Base对象的操作
}
```

### type_info类

## 枚举类型

* 枚举类型`(enumeration)`使我们可以将一组整型常量组织在一起。枚举属于字面值常量类型。
* **限定作用域的枚举类型(scoped enumeration)**：首先是关键字`enum class(或enum struct)`，随后是枚举类型名字以及用花括号括起来的以逗号分隔的枚举成员列表，最后是一个分号。

```c++
enum class open_modes {input, output, append};
```

* 不限定作用域的枚举类型`(unscoped enumeration)`：省略关键字`class(或struct)`，枚举类型的名字是可选的。

```c++
enum color {red, yellow, green};

enum {floatPrec = 6, doublePrec = 10, double_doublePrec = 10};

```

## 类成员指针

**成员指针**：指可以指向类的非静态成员的指针。

### 数据成员指针

* 和其他指针一样，在声明成员指针时也使用*来表示当前声明的名字是一个指针。与普通指针不同的时，成员指针还必须包含成员所属的类。

```c++
// pdata可以指向一个常量(非常量)Screen对象的string成员
const string Screen::*pdata;

// C++11
auto pdata = &Screen::contents;
```

* 当我们初始化一个成员指针或为成员指针赋值时，该指针没有指向任何数据。成员指针指定了成员而非该成员所属的对象，只有当解引用成员指针时才提供对象的信息。

```c++
Screen myScreen, *pScreen = &myScreen;

auto s = myScreen.*pdata;

s = pScreen->*pdata;
```

### 成员函数指针

* 因为函数调用运算符的优先级较高，所以在声明指向成员函数的指针并使用这些的指针进行函数调用时，括号必不可少：`(C::*p)(parms)`和`(obj.*p)(args)`。

### 将成员函数用作可调用对象

## 嵌套类

* 一个类可以定义在另一个类的内部，前者称为嵌套类(nested class)或嵌套类型(nested type)。**嵌套类常用于定义作为实现部分的类**。
* 嵌套类是一个独立的类，与外层类基本没有什么关系。特别是，外层类的对象和嵌套类的对象是相互独立的。
* 嵌套类的名字在外层类作用域中是可见的，在外层类作用域之外不可见。

## union：一种节省空间的类

* `联合(union)`是一种特殊的类。一个`union`可以有多个数据成员，但是在任意时刻只有一个数据成员可以有值。**它不能含有引用类型的成员和虚函数**。

```c++
// Token类型的对象只有一个成员，该成员的类型可能是下列类型中的任意一种
union Token {
    // 默认情况下成员是共有的
    char cval;
    int ival;
    double dval;
}；

```

* `匿名union(anonymous union)`是一个未命名的`union`，并且在右花括号和分号之间没有任何声明。

```c++
union {
    char cval;
    int ival;
    double dval;
};

// 可以直接访问它的成员
cal = 'c';
ival = 42;
```

* **注意：** `匿名union`不能包含受保护的成员或私有成员，也不能定义成员函数。

## 局部类

* `局部类(local class)`：可以定义在某个函数的内部的类。它的类型只在定义它的作用域内可见。和嵌套类不同，局部类的成员受到严格限制。
* 局部类的所有成员(包括函数在内)都必须完整定义在类的内部。因此，局部类的作用与嵌套类相比相差很远。
* **局部类不能使用函数作用域中的变量。**

```c++
int a, val;
void foo(int val) {
    static inti si;
    enum loc { a = 1024, b};

    // Bar是foo的局部类
    struct Bar {
        Loc locVal; // 正确：使用一个局部类型名
        int barVal;

        void fooBar(Loc l = a) {    // 正确：默认实参是Loc::a
            barVal = val;   // 错误：val是foo的局部变量
            barVal == ::val;    // 正确：使用一个全局对象
            barVal = si;    // 正确：使用一个静态局部对象
            locVal = b; // 正确：使用一个枚举成员
        }
    }；
}

```

## 固有的不可移植的特性

所谓不可移植的特性是指**因机器而异的特性**，当将含有不可移植特性的程序从一台机器转移到另一台机器上时，通常需要重新编写该程序。

### 位域

* 类可以将其(非静态)数据成员定义成**位域(bit-field)**，在一个位域中含有一定数量的二进制位。当一个程序需要向其他程序或硬件设备传递二进制数据时，通常会用到位域。
* 位域在内存中的布局是与机器相关的。
* 位域的类型必须是整型或枚举类型。因为带符号位域的行为是由具体实现确定的，通常情况下我们使用无符号类型保存一个位域。

```c++
typedef unsigned int Bit;
class File {
    Bit mode: 2;
    Bit modified: 1;
    Bit prot_owner: 3;
    Bit prot_group: 3;
    Bit prot_world: 3;
public:
    enum modes {READ = 01, WRITE = 02, EXECUTE = 03};
    File &open(modes);
    void close();
    void write();
    bool isRead() const;
    void setWrite();
}

// 使用位域
void File::write() {
    modified = 1;
    // ...
}

void File::close() {
    if( modified)
        // ...保存内容
}

File &File::open(File::modes m) {
    mode |= READ;   // 按默认方式设置READ
    // 其他处理
    if(m & WRITE)   // 如果打开了READ和WRITE
        // 按照读/写方式打开文件
    return *this;
}
```

### volatile限定符

* 当对象的值可能在程序的控制或检测之外被改变时，应该将该对象声明为`volatile`。关键字`volatile`告诉编译器不应对这样的对象进行优化。
* `const`和`volatile`的一个重要区别是不能使用合成的拷贝/移动构造函数及赋值运算符初始化`volatile`对象或者从`volatile`对象赋值。

### 链接指示：extern "C"

* `C++`使用`链接指示(linkage directive)`指出任意非`C++`函数所用的语言。
* 要想把`C++`代码和其他语言(包括`C`语言)编写的代码放在一起使用，要求我们必须有权访问该语言的编译器，并且这个编译器与当前的`C++`编译器是兼容的。
* `C++`从C语言继承的标准库函数可以定义为`C`函数，但并非必须：决定使用`C`还是`C++`实现的`C`标准库，是每个`C++`实现的事情。
* 有时需要在C和C++中编译同一个源文件，为了实现这一目的，在编译C++版本的程序时预处理器定义`__cplusplus`。

```c++
#ifdef __cplusplus
extern "C"
#endif
int strcmp(const char*, const char*);
```
