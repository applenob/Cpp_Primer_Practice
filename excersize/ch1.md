# 第一章 快速入门

## 练习1.1
查阅你使用的编译器的文档，确定它所使用的文件名约定。编译并运行第2页的main程序。

解：
- ``g++ ch1.cpp -o main``
- ``./main``

## 练习1.2
改写程序，让它返回-1。返回值-1通常被当做程序错误的标识。重新编译并运行你的程序，观察你的系统如何处理main返回的错误标识。

解：
- 在ubuntu下，使用g++，返回-1，``./main``没有发现任何异常。
- ``echo $?``，返回255。

## 练习1.3
编写程序，在标准输出上打印Hello, World。

解：
```cpp
#include <iostream>

int main()
{
	std::cout << "Hello, World" << std::endl;
	return 0;
}
```

## 练习1.4
我们的程序使用加法运算符`+`来将两个数相加。编写程序使用乘法运算符`*`，来打印两个数的积。

解：
```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2
              << " is " << v1 * v2 << std::endl;
}        
```

## 练习1.5
我们将所有的输出操作放在一条很长的语句中，重写程序，将每个运算对象的打印操作放在一条独立的语句中。

解：
```cpp
#include <iostream>

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
        int v1 = 0, v2 = 0;
        std::cin >> v1 >> v2;
        std::cout << "The product of ";
        std::cout << v1;
        std::cout << " and ";
        std::cout << v2;
        std::cout << " is ";
        std::cout << v1 * v2;
        std::cout << std::endl;
}    
```

## 练习1.6
解释下面程序片段是否合法。
```cpp
std::cout << "The sum of " << v1;
          << " and " << v2;
          << " is " << v1 + v2 << std::endl;
```
如果程序是合法的，它的输出是什么？如果程序不合法，原因何在？应该如何修正？

解：

程序不合法，有多余的分号，修改如下：
```cpp
std::cout << "The sum of " << v1
          << " and " << v2
          << " is " << v1 + v2 << std::endl;
```

## 练习1.7
编译一个包含不正确的嵌套注释的程序，观察编译器返回的错误信息。

解：
```cpp
/* 正常注释 /* 嵌套注释 */ 正常注释*/
```
错误信息：
```
  /* 正常注释 /* 嵌套注释 */ 正常注释*/
                                     ^
ch1.cpp:97:37: error: stray ‘\255’ in program
ch1.cpp:97:37: error: stray ‘\243’ in program
ch1.cpp:97:37: error: stray ‘\345’ in program
ch1.cpp:97:37: error: stray ‘\270’ in program
ch1.cpp:97:37: error: stray ‘\270’ in program
ch1.cpp:97:37: error: stray ‘\346’ in program
ch1.cpp:97:37: error: stray ‘\263’ in program
ch1.cpp:97:37: error: stray ‘\250’ in program
ch1.cpp:97:37: error: stray ‘\351’ in program
ch1.cpp:97:37: error: stray ‘\207’ in program
ch1.cpp:97:37: error: stray ‘\212’ in program
ch1.cpp: In function ‘int main()’:
ch1.cpp:97:50: error: expected primary-expression before ‘/’ token
  /* 正常注释 /* 嵌套注释 */ 正常注释*/
                                                  ^
ch1.cpp:98:5: error: expected primary-expression before ‘return’
     return 0;
     ^
```

## 练习1.8
指出下列哪些输出语句是合法的（如果有的话）：
```cpp
std::cout << "/*";
std::cout << "*/";
std::cout << /* "*/" */;
std::cout << /* "*/" /* "/*" */;
```
预测编译这些语句会产生什么样的结果，实际编译这些语句来验证你的答案(编写一个小程序，每次将上述一条语句作为其主体)，改正每个编译错误。

解：

只有第三句编译出错，改成如下即可：
```cpp
std::cout << /* "*/" */";
```
第四句等价于输出 `" /* "`。

## 练习1.9

编写程序，使用`while`循环将50到100整数相加。

