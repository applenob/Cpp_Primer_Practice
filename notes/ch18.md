# 第十八章 用于大型程序的工具

大规模应用程序的特殊要求包括：

- 在独立开发的子系统之间协同处理错误的能力。
- 使用各种库进行协同开发的能力。
- 对比较复杂的应用概念建模的能力。

## 异常处理

**异常处理**（exception handling）机制允许程序中独立开发的部分能够在运行时就出现的问题进行通信并作出相应的处理。

### 抛出异常

在C++语言中，我们通过**抛出**（throwing）一条表达式来**引发**（raised）一个异常。异常类型和当前的调用链决定了哪段**处理代码**（handler）将用来处理该异常。

程序的控制权从`throw`转移到`catch`模块。

**栈展开**：当`throw`出现在一个`try语句块`时，检查该`try语句块`相关的`catch`字句，若有匹配则处理；若无匹配，则继续检查外层的`try`匹配的`catch`。

若一个异常没有被捕获，则它将终止当前的程序。

对象销毁：

- 块退出后，它的局部对象将被销毁。
- 若异常发生在构造函数中，即使某个对象只构造了一部分，也要确保已构造的成员正确地被销毁。
- 将资源释放放在类的析构函数中，以保证资源能被正确释放。析构函数本身不会引发异常。

### 捕获异常

若无需访问抛出的异常对象，则可以忽略捕获形参的名字。

通常，若`catch`接受的异常与某个继承体系有关，则最好将该`catch`的参数定义成引用类型。

搜索`catch`未必是最佳匹配，而是第一个匹配，因此，越细化的`catch`越应该放在`catch`列表前段。

重新抛出：`catch`代码执行一条`throw;`将异常传递给另一个`catch`语句。

捕获所有异常：`catch(...)`

### 构造函数

处理构造函数初始值异常的唯一方法是将构造函数协程函数`try`语句块。

示例：

```cpp
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) try: 
    data(std::make_shared<std::vector<T> >(il){
        /*函数体*/
    } catch(const std::bad_alloc &e){ handle_out_of_memory(e); }
```

### noexcept异常说明

使用`noexcept`说明指定某个函数不会抛出异常。

示例：

```cpp
void recoup(int) noexcept; //C++11
coid recoup(int) throw(); //老版本
```

### 异常类层次

标准exception层次：

- exception
  - bad_cast
  - bad_alloc
  - runtime_error
    - overflow_error
    - underflow_error
    - range_error
  - logic_error
    - domain_error
    - invalid_argument
    - out_of_range
    - length_error

自定义异常类：

示例：

```cpp
class out_of_stock: public std::runtime_error {
    explicit out_of_stock(const std::string &s):
    std::runtime_error(s){ }
};
```

## 命名空间

多个库将名字放置在全局命名空间中将引发**命名空间污染**（namespace pollution）。**命名空间**（namespace）分割了全局命名空间，其中每个命名空间是一个作用域。

### 命名空间定义

命名空间的定义包含两部分：1.关键字`namespace`；2.命名空间名称。后面是一系列由花括号括起来的声明和定义。命名空间作用域后面无需分号。

示例：

```cpp
namespace cplusplus_primer{
    
}
```

每个命名空间都是一个**作用域**。定义在某个命名空间内的名字可以被该命名空间内的其他成员直接访问，也可以被这些成员内嵌套作用域中的任何单位访问。位于该命名空间之外的代码必须明确指出所用的名字是属于哪个命名空间的。

命名空间可以是**不连续**的。这点不同于其他作用域，意味着同一命名空间可以在多处出现。

**内联命名空间**（C++11）：

无需使用该命名空间的前缀，通过外层命名空间就可以直接访问。

示例：

```cpp
namespace cplusplus_primer{
    inline namespace FifthEd{
        // 表示本书第5版代码
        class Query_base {};
    }
}

cplusplus_primer::Query_base qb;
```

**未命名的命名空间**：

指关键字`namespace`后面紧跟花括号的用法。未命名的命名空间中定义的变量拥有静态的声明周期：在第一次使用前创建，直到程序结束才销毁。不能跨越多个文件。

### 使用命名空间成员

像`namespace_name::member_name`这样使用命名空间的成员非常繁琐。

**命名空间的别名**：

```cpp
namespace primer = cplusplus_primer;
```

**using声明**（using declaration）：

一条`using`声明语句一次只引入命名空间的一个成员。

```cpp
using std::string;

string s = "hello";
```

**using指示**（using directive）：

使得某个特定的命名空间中所有的名字都可见。

```cpp
using namespace std;

string s = "hello";
```

### 类、命名空间与作用域

```cpp
namespace A{
    class C1{
        public:
            int f3();
    }
}

A::C1::f3
```

### 重载与命名空间

`using`声明语句声明的是一个名字，而非特定的函数，也就是包括该函数的所有版本，都被引入到当前作用域中。

## 多重继承与虚继承

### 多重继承

### 类型转换与多个基类

### 多重继承下的类作用域

* 当一个类拥有多个基类时，有可能出现派生类从两个或更多基类中继承了同名成员的情况。此时，不加前缀限定符直接使用该名字将引发二义性。

### 虚继承

* 虚继承的目的是令某个类做出声明，承诺愿意共享它的基类。其中，共享的基类子对象成为**虚基类**。在这种机制下，不论虚基类在继承体系中出现了多少次，在派生类中都只包含唯一一个共享的虚基类子对象。
* 虚派生只影响从指定了虚基类的派生类中进一步派生出的类，它不会影响派生类本身。

### 构造函数与虚继承

* h含有虚基类的对象的构造顺序与一般的顺序稍有**区别**：首先使用提供给最底层派生类构造函数的初始值初始化该对象的虚基类子部分，接下来按照直接基类在派生列表中出现的次序对其进行初始化。
* 虚基类总是先于非虚基类构造，与它们在继承体系中的次序和位置无关。