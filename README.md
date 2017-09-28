# Cpp Primer 练习

## 环境
- system: ubuntu 16.04
- IDE: CLion
- compiler: g++

## 笔记

## 第一章 快速入门

### 熟悉编译器

**g++**：

- 编译：`g++ ch1.cpp -o main`
- 运行：`./prog1`
- 查看运行状态：`echo $?`
- 编译多个文件:`g++ ch2.cpp Sales_item.cc -o main`

```
Usage: g++ [options] file...
Options:
  -pass-exit-codes         Exit with highest error code from a phase
  --help                   Display this information
  --target-help            Display target specific command line options
  --help={common|optimizers|params|target|warnings|[^]{joined|separate|undocumented}}[,...]
                           Display specific types of command line options
  (Use '-v --help' to display command line options of sub-processes)
  --version                Display compiler version information
  -dumpspecs               Display all of the built in spec strings
  -dumpversion             Display the version of the compiler
  -dumpmachine             Display the compiler's target processor
  -print-search-dirs       Display the directories in the compiler's search path
  -print-libgcc-file-name  Display the name of the compiler's companion library
  -print-file-name=<lib>   Display the full path to library <lib>
  -print-prog-name=<prog>  Display the full path to compiler component <prog>
  -print-multiarch         Display the target's normalized GNU triplet, used as
                           a component in the library path
  -print-multi-directory   Display the root directory for versions of libgcc
  -print-multi-lib         Display the mapping between command line options and
                           multiple library search directories
  -print-multi-os-directory Display the relative path to OS libraries
  -print-sysroot           Display the target libraries directory
  -print-sysroot-headers-suffix Display the sysroot suffix used to find headers
  -Wa,<options>            Pass comma-separated <options> on to the assembler
  -Wp,<options>            Pass comma-separated <options> on to the preprocessor
  -Wl,<options>            Pass comma-separated <options> on to the linker
  -Xassembler <arg>        Pass <arg> on to the assembler
  -Xpreprocessor <arg>     Pass <arg> on to the preprocessor
  -Xlinker <arg>           Pass <arg> on to the linker
  -save-temps              Do not delete intermediate files
  -save-temps=<arg>        Do not delete intermediate files
  -no-canonical-prefixes   Do not canonicalize paths when building relative
                           prefixes to other gcc components
  -pipe                    Use pipes rather than intermediate files
  -time                    Time the execution of each subprocess
  -specs=<file>            Override built-in specs with the contents of <file>
  -std=<standard>          Assume that the input sources are for <standard>
  --sysroot=<directory>    Use <directory> as the root directory for headers
                           and libraries
  -B <directory>           Add <directory> to the compiler's search paths
  -v                       Display the programs invoked by the compiler
  -###                     Like -v but options quoted and commands not executed
  -E                       Preprocess only; do not compile, assemble or link
  -S                       Compile only; do not assemble or link
  -c                       Compile and assemble, but do not link
  -o <file>                Place the output into <file>
  -pie                     Create a position independent executable
  -shared                  Create a shared library
  -x <language>            Specify the language of the following input files
                           Permissible languages include: c c++ assembler none
                           'none' means revert to the default behavior of
                           guessing the language based on the file's extension

```

### io

- ```#include <iostream>```
- ```std::cout << "hello"```
- ```std::cin >> v1```

记住>>和<<返回的结果都是左操作数，也就是输入流和输出流本身。

ubuntu下键盘输入文件结束符：`ctrl+d`

### 类

**头文件**：类的类型一般存储在头文件中，标准库的头文件使用<>，非标准库的头文件使用""。申明写在.h文件，定义实现写在.cpp文件。

**避免多次包含同一头文件**：
```
#ifndef SALESITEM_H
#define SALESITEM_H
// Definition of Sales_itemclass and related functions goes here
#endif
```

**成员函数（类方法）**：使用'.'调用。

## 第二章 变量和基本类型

**基本算数类型**：
- `char`:8bits
- `short`:16bits
- `int`:16bits (在32位机器中是32bits)
- `long`:32bits
- `float`
- `double`
- `long double`

**左值和右值**：
- 左值（l-value）可以出现在赋值语句的左边或者右边，比如变量；
- 右值（r-value）只能出现在赋值语句的右边，比如常量。

**字符串字面值**：使用空格连接，继承自C。

**对象的初始化**：定义时指定了初始值的对象成为是已初始化的。

**初始化不是赋值！**：初始化是创建变量并给它赋予初始值；赋值是擦处对象的当前值并用新值代替。

**构造函数**：定义如何进行初始化的成员函数。

**变量的定义**：变量的定义用于分配存储空间，还可以指定初始值。

**变量的声明**：用于向程序表明变量的类型和名字。

**extern**：只是说明变量定义在其他地方。

**const限定符**：把一个对象转换成常量。const变量默认不能被其他文件访问，非要访问，必须在指定const前加extern。

**引用**：引用是一个对象的别名，如`int &refVal = val;`。

**const引用**：指向const对象的引用，如`const int ival=1; const int &refVal = ival;`，可以读取但不能修改refVal。

**typedef**：用来定义类型的同义词。

**枚举**：如`enum open_modes {input, output, append};`，枚举的成员必须是一个常量表达式（可以在编译时计算出来）。

**struct**：使用class定义类，那么定义在第一个访问标号前的任何成员都隐式地指定为private；如果使用struct，那么默认是public。

## 第三章 标准库类型

**string对象**：注意，不同于字符串字面值。
- `s.emtpy()`是否为空；
- `s.size()`尺寸；
- `string::size_type`定义了size的类型；
- `+`：字符串连接；
- `str[i]` 可以作为左值。

**ctype.h vs. cctype**：C++修改了c的标准库，名称为去掉“.h”，前面加“c”。

**vector**：
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

**bitset**：
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

## 第四章 数组和指针

**数组**：
- 相当于vector的低级版，长度固定；
- 初始化：`char input_buffer[buffer_size];`，长度必须是const表达式；
- 数组不允许直接赋值给另一个数组；
- 数组下标的类型：`size_t`

**指针**：
- 指针用于指向对象，指针保存的是另一个对象的地址；
- 指针定义：`int *ip1;` **从右向左读**，ip1是指向int类型的指针；
- 指针的可能取值：1.特定对象地址；2.某对象后一个对象地址；3.0值（代表不指向任何对象）；
- `void* `指针，可以保存任何类型对象的地址，但只支持指针比较/函数传值/赋值，不允许操纵所指对象；
- 利用解引用操作符`“*”`可以获取指针所指向的对象；
- 两个指针相减的类型是`ptrdiff_t`；


**指针vs引用**：
- 引用总是指向某个对象，定义引用时没有初始化是错的；
- 给引用赋值，修改的是该引用所关联的对象的值，而不是让引用和另一个对象相关联。

**指向指针的指针**：
- 定义： `int **ppi = &pi;`
- 解引用：`**ppi`

**指针访问数组**：在表达式中使用数组名时，名字会自动转换成指向数组的第一个元素的指针。

**指向const对象的指针**：
- `const double *cptr`；
- 不能通过解引用来修改指向的对象的值；
- 可以更换指向的对象；
- 不能使用`void*`来保存const对象的地址，必须使用`const void*`；

**const指针**：
- 指针本身的值不能修改；
- `int *const ccptr`；

**字符串字面值**：const char类型的数组，加“null”是c style，即`\0`。

**动态数组**：
- 使用 `new`和 `delete`表达和c中`malloc`和`free`类似的功能，即在堆（自由存储区）中分配存储空间。
- 定义： `int *pia = new int[10];`,10可以被一个变量替代；
- 释放： `delete [] pia;`，注意不要忘记`[]`；

**多维数组的初始化**： `int ia[3][4] = {{0,1,2,3}, ...}`；

## 第五章 表达式

`*iter++`等价于 `*(iter++)`

**箭头操作符`->`**：`(*p).foo`等价于`p->foo`。

**sizeof操作符**：返回某个对象或者类型的长度，返回值的类型size_t，长度的单位是字节。

**隐式类型转换**：
- 混合类型的表达式： `int i; double d; i >=d`
- 表达式的条件转换成bool类型： `int i; if i`
- 表达式初始化： `int i = 3.14`
- 数组指针转换： `int ia[10]; int *ip = ia;`
- 枚举类型的对象或者枚举成员转换为整型。
- 转换成const对象： `int i; const &j = i;`，i被转换成const。

**显式（强制）转换**：
- `static_cast`： `int c=static_cast<int>(7.987);`。
- `dynamic_cast`：支持运行时识别指针或引用所指向的对象。
- `const_cast`：去掉const性质。
- `reinterpret_cast`：通常为操作数的位模式提供较低层次的重新解释。
- 尽量避免使用强制类型转换。

## 第六章 语句

**异常处理**：
- `throw`表达式：遇到了不可处理的错误。
- `try`：和 `catch`配合，`try`中的代码出现异常交由`catch`解决。
- `catch`：如上。

## 第七章 函数

**形参和实参**：形参是在函数的形参表中定义的，并由调用函数时传递函数的实参初始化。

**非引用形参**：
- 普通的非引用类型的参数通过复制对应的实参实现初始化，因此函数执行完不会修改实参的值。
- `指针形参`，被复制的指针只影响对指针的赋值。
- `const形参`：既可以传递const实参，也可以传递非const实参，在函数中，不能改变实参的局部副本。

**引用形参**：
- 引用形参直接关联到绑定的对象，而非对象的副本；
- 使用引用形参可以用于返回额外的信息；
- 经常用const引用来避免不必要的复制。

**传递指向指针的引用**： `void func(int *&v1)`，从右向左理解，v1是一个引用，于指向int型对象的指针相关联。

**对于是容器类型的形参**：调用非引用的vector会复制vector的每一个元素，一般更倾向于通过船体指向容器中需要处理的元素的迭代器。

**对于数组的形参**： 
- 非引用：`void func(int*)`等价于 `void func(int[10])`，也就是说不会复制数组，而是转换为指向第一个元素的指针，且长度限制没有意义。
- 引用：传递数组的引用本身，会检查实参数组的数组大小， `void func(int (&arr)[10])`

**main函数接受命令行参数**：
- 命令行： `prog -d -o ofile`
- 代码： `int main(int argc, char *argv[])`，有 `argv[0] = "prog"; argv[1] = "-d";argv[2] = "-o";argv[3] = "ofile";`

**静态局部对象**：一个变量如果位于函数的作用域内，但生命期跨越了这个函数的多次调用，定义为static（静态的）。

**内联（inline）函数**：
- 普通函数的缺点：调用函数比求解等价表达式要慢得多。
- inline函数可以避免函数调用的开销，可以让编译器在编译时内联地展开该函数。
- inline函数应该在头文件中定义。

**类的成员函数**：
- 每个成员函数都有一个额外的，隐含的形参this。
- 形参表后面的const，改变了隐含的this形参的类型，如 `bool same_isbn(const Sales_item &rhs) const`，这种函数称为“常量成员函数”。

**类的构造函数**：
- 构造函数是特殊的成员函数。
- 构造函数放在类的`public`部分。
- 初始化列表：冒号和花括号之间的代码： `Sales_item(): units_sold(0), revenue(0.0) { }`

**重载函数**：
- 出现在相同作用域的两个函数，具有相同的名字而形参表不同，称为重载函数。
- 不能仅仅基于不同的返回类型而实现重载。
- 重载函数的三个步骤：1.候选函数；2.可行函数；3.寻找最佳匹配。
- 仅当形参是引用或指针时，形参是否为const才有影响。

**指向函数的指针**： `bool (*pf)(const string &, const string &);`

## 第八章 标准IO库

**IO对象不可复制或赋值**：两层含义，1.io对象不能存在容器里；2.形参和返回类型也不能是流类型。

**io操纵符**：
- `endl`：输出一个换行符并刷新缓冲区；
- `flush`：刷新流，单不添加任何字符；
- `ends`：在缓冲区插入空字符null，然后刷新。

**文件流**：需要读写文件时，必须定义自己的文件流对象，并绑定在需要的文件上。

**文件模式**：
- `in`
- `out`
- `app`：写之前找到文件尾。
- `ate`：打开文件后立即将文件定位在文件尾。
- `trunc`：打开文件时清空已经存在的文件流。
- `binary`：以二进制模式进行io操作。

**按行读取**：`getline(infile,line)`

## 第九章 顺序容器

**顺序容器**：
- 标准库定义了三种顺序容器：vector，list和deque。
- 顺序容器适配器（adapter）：stack，queue，priority_queue。
- 直接复制：将一个容器复制给另一个容器时，类型必须匹配：容器类型和元素类型都必须相同。
- 使用迭代器复制：不要求容器类型相同，容器内的元素类型也可以不同。
- 接受容器大小做形参的构造函数只适用于顺序容器，而关联容器不支持这种初始化。

**容器内元素的类型约束**：
- 元素类型必须支持赋值运算；
- 元素类型的对象必须可以复制。
- 除了输入输出标准库类型外，其他所有标准库类型都是有效的容器元素类型。

**begin和end**：
- `c.begin()`：返回一个迭代器，它指向容器 c 的第一个元素。
- `c.end()`：返回一个迭代器，它指向容器 c 的最后一个元素的下一位置。
- `c.rbegin()`：返回一个逆序迭代器，它指向容器 c 的最后一个元素。
- `c.rend()`：返回一个逆序迭代器，它指向容器 c 的第一个元素前面的位置。

**顺序容器中添加元素的操作**：
- `c.push_back(t)`：在容器尾部添加t，返回void。
- `c.push_front(t)`：在容器前端添加t，返回void，只适用于list和deque。
- `c.insert(p, t)`：在迭代器p所指向的元素**前**插入t，返回指向新元素的迭代器。
- `c,insert(p, n, t)`：在迭代器p所指向的元素**前**插入n个t的新元素，返回void。
- `c.insert(p, b, e)`：在迭代器p偶只想的元素**前**插入由迭代器b和e标记的范围内的元素，返回void。

**顺序容器的大小操作**：
- `c.size()`：返回容器中c的元素个数，类型：`c::size_type`。
- `c.max_size()`：返回容器c可容纳的最多元素个数。
- `c.empty()`：返回容器大小是否为0。
- `c.resize(n)`：调整c的长度大小为n，多删少增。
- `c.resize(n,t)`：调整长度为n，新增的元素值是t。

**顺序容器访问元素**：
- `c.back()`：返回最后一个元素的引用，前提是c非空。
- `c.front()`：返回第一个元素的引用，前提是c非空。
- `c[n]`：返回下标是n的引用，只适用于vector和deque。
- `c.at(n)`：返回下标是n的引用，只适用于vector和deque。

**顺序容器删除元素**：
- `c.erase(p)`：删除迭代器p所指的元素。
- `c.erase(b, e)`：删除迭代器b到e内的所有元素。
- `c.clear()`：删除c内所有元素。
- `c.pop_back()`：删除c的最后一个元素，返回void。
- `c.pop_front()`：删除c的第一个元素，返回void，只适用于list和deque。

**顺序容器的赋值操作**：
- `c1=c2`：删除c1所有元素，将c2的元素复制给c1。
- `c1.swap(c2)`：交换内容。
- `c.assign(b, e)`：先删除c所有元素，将迭代器b到e标记范围内所有元素复制到c中。
- `c.assign(n, t)`：先删除c所有元素，将c中心设置为存储n个值为t的元素。

**vector vs. list**：
- vector容器的元素是连续存放的；
- list容器的元素是非连续存放（链表）；
- vector和deque支持快速随机访问；
- list类型可以支持

**string**：
- `s.insert(p, t)`：在迭代器p指向的元素之前插入t，**返回指向t的迭代器**。
- `s.insert(p, n, t)`：在迭代器p指向的元素之前插入n个值为t的新元素，返回void。
- `s.insert(p, b, e)`：在迭代器p指向的元素之前插入迭代器b到e范围内所有元素，返回void。
- `s.assign(b, e)`：用b到e的元素替换s，返回s。
- `s.assign(n, t)`：用值为t的n个副本替换s，返回s。
- `s.erase(p)`：删除迭代器p指向的元素，返回下一个元素的迭代器。
- `s.erase(b, e)`：删除从b到e的所有元素，返回下一个元素的迭代器。
- 还可以用`pos` 和 `len`表示下标和长度，代替上面的b，e。
- `s.substr(pos, len)`：返回当前对象的子串。
- `s.append(args)`：将args串接在s后面，返回s引用。
- `s.replace(pos, len, args)`：删除s中从下标pos开始的len个字符，并用args替换。
- `s.find(args)`：args在s中的第一次出现。
- `s.rfind(args)`：最后一次出现。
- string采用字典顺序比较。

**适配器**：
- 适配器是使一事物的行为类似于另一事物的行为的一种机制，例如stack可以使任何一种顺序容器以栈的方式工作。
- 初始化 `deque<int> deq; stack<int> stk(deq);`
- 默认的`stack`和`queue`都是基于`deque`实现，`priority_queue`是基于`vector`实现。
- 创建适配器时，指定一个顺序容器，可以覆盖默认的基础容器： `stack<string, vector<string> > str_stk;`。

**stack**：
- `s.pop()`：删除栈顶元素，不返回。
- `s.top()`：返回栈顶元素，不删除。
- `s.push(item)`：雅俗新元素。

**queue和priority_queue**：
- `q.pop()`：删除队首元素，但不返回。
- `q.front()`：返回队首元素的值，不删除。
- `q.top()`：返回具有最高优先级的元素值，不删除。
- `q.push(item)`：在队尾压入一个新元素。

## 第十章 关联容器

**关联容器**：支持通过键来高效地查找和读取元素，基本的关联容器类型是 `map`和 `set`。
- `map`：key-->value
- `set`：大小可变的集合，支持通过键快速读取。
- `multimap`：支持同一个键多次出现的`map`。
- `multiset`：支持同一个键多次出现的`set`。
- 都是按顺序存储。

**pair**：
- 在`utility`头文件中定义。
- `p.first`/`p.second`，返回p的名为first和second的数据成员。
- `pair<string, string> author("James", "Joyce");`。
- `make_pair`

**map**：
- 在 `map`头文件中定义。
- 键的要求：有相关的比较函数（严格弱排序，小于）
- 初始化：`map<string, int> word_count;`
- 添加元素： `word_count["Anna"]=1;`或者 `word_count.insert(map<string, int>::value_type("Anna", 1));`
- 遍历：iterator指向一个pair，first指向key，second指向value。
- `m.count(k)`：返回m中k的出现次数，只能是0或1。
- `m.find(k)`：如果m中已经存在k索引的元素，返回迭代器，否则返回超出末端的迭代器。
- `m.erase(k)`：删除m中键为k的元素； `erase(p)`：删除p迭代器指向的元素。

**set**：
- 在 `set`头文件中定义。
- 初始化： `set<string> s;`
- 添加元素： `s.insert("the");`
- set不提供下标操作符。
- 获取元素： `s.find("the");`
- 更简单的判断某元素是否在集合中： `s.count(element) == 1`

**multimap和multiset**：
- 支持同一键值出现多次。
- 插入只能使用insert。
- `erase` 将删除某个键的所有元素，并返回删除的个数。
- `find` 操作则返回一个迭代器， 指向第一个拥有正在查找的键的实例。


****：

****：

****：

****：
