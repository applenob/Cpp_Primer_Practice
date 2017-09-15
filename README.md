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
- char:8bits
- short:16bits
- int:16bits (在32位机器中是32bits)
- long:32bits
- float
- double
- long double

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

****：

****：

****：

****：
