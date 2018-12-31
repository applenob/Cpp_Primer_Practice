# 第一章 开始

## 练习1.1
查阅你使用的编译器的文档，确定它所使用的文件名约定。编译并运行第2页的main程序。

解：
- ``g++ --std=c++11 ch1.cpp -o main``
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

解：
```cpp
#include <iostream>

int main()
{
    int sum = 0, val = 50;
    while (val <= 100){
        sum += val;
        val += 1;
    }
    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;
}    
```

## 练习1.10
除了`++`运算符将运算对象的值增加1之外，还有一个递减运算符`--`实现将值减少1.编写程序与，使用递减运算符在循环中按递减顺序打印出10到0之间的整数。

解：
```cpp
#include <iostream>

int main()
{
    int val = 10;
    while (val >= 0){
        std::cout << val << " ";
        val -= 1;
    }
    std::cout << std::endl;
}  
```

## 练习1.11
编写程序，提示用户输入两个整数，打印出这两个整数所指定的范围内的所有整数。

解：
```cpp
#include <iostream>

int main()
{
    int start = 0, end = 0;
    std::cout << "Please input two num: ";
    std::cin >> start >> end;
    if (start <= end) {
        while (start <= end){
            std::cout << start << " ";
            ++start;
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "start should be smaller than end !!!";
    }
}  
```

## 练习1.12

下面的for循环完成了什么功能？sum的终值是多少？
```cpp
int sum = 0;
for (int i = -100; i <= 100; ++i)
	sum += i;
```

解：

从-100加到100，sum的终值是0。

## 练习1.13
使用for循环重做1.4.1节中的所有练习（练习1.9到1.11）。

解：

### 练习1.9

```cpp
#include <iostream>

int main()
{
    int sum = 0;
    for (int val = 50; val <= 100; ++val){
        sum += val;
    }
    std::cout << "Sum of 50 to 100 inclusive is "
              << sum << std::endl;
}    
```

### 练习1.10

```cpp
#include <iostream>

int main()
{
    for (int val = 10; val >=0; --val){
        std::cout << val << " ";
    }
    std::cout << std::endl;
}  
```

### 练习1.11

```cpp
#include <iostream>

int main()
{
    int start = 0, end = 0;
    std::cout << "Please input two num: ";
    std::cin >> start >> end;
    if (start <= end) {
        for (; start <= end; ++start){
            std::cout << start << " ";
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "start should be smaller than end !!!";
    }
}  
```

## 练习1.14
对比for循环和while循环，两种形式的优缺点各是什么？

解：
```
The main difference between the `for`'s and the `while`'s is a matter of pragmatics: 
we usually use `for` when there is a known number of iterations, 
and use `while` constructs when the number of iterations in not known in advance. 
The `while` vs `do ... while` issue is also of pragmatics, 
the second executes the instructions once at start, 
and afterwards it behaves just like the simple `while`.
```

## 练习1.15
编写程序，包含第14页“再探编译”中讨论的常见错误。熟悉编译器生成的错误信息。
   
解：

编译器可以检查出的错误有：
- 语法错误
- 类型错误 
- 声明错误

## 练习1.16
编写程序，从cin读取一组数，输出其和。

解：

```cpp
#include <iostream>

int main()
{
    int sum = 0;
    for (int value = 0; std::cin >> value; )
        sum += value;
    std::cout << sum << std::endl;
    return 0;
}
```

## 练习1.17
如果输入的所有值都是相等的，本节的程序会输出什么？如果没有重复值，输出又会是怎样的？

## 练习1.18
编译并运行本节的程序，给它输入全都相等的值。再次运行程序，输入没有重复的值。

解：

全部重复：
```
1 1 1 1 1 
1 occurs 5 times 
```

没有重复：
```
1 2 3 4 5
1 occurs 1 times 
2 occurs 1 times 
3 occurs 1 times 
4 occurs 1 times 
5 occurs 1 times 
```

## 练习1.19
修改你为1.4.1节练习1.11（第11页）所编写的程序（打印一个范围内的数），使其能处理用户输入的第一个数比第二个数小的情况。

解：

```cpp
#include <iostream>

int main()
{
    int start = 0, end = 0;
    std::cout << "Please input two num: ";
    std::cin >> start >> end;
    if (start <= end) {
        while (start <= end){
            std::cout << start << " ";
            ++start;
        }
        std::cout << std::endl;
    }
    else{
        std::cout << "start should be smaller than end !!!";
    }
}  
```

## 练习1.20
在网站http://www.informit.com/title/032174113 上，第1章的代码目录包含了头文件 Sales_item.h。将它拷贝到你自己的工作目录中。用它编写一个程序，读取一组书籍销售记录，将每条记录打印到标准输出上。

解：

```cpp
#include <iostream>
#include "Sales_item.h"

int main()
{
	for (Sales_item item; std::cin >> item; std::cout << item << std::endl);
	return 0;
}
```

命令：
```
./main < data/add_item
```

输出：
```
0-201-78345-X 3 60 20
0-201-78345-X 2 50 25
```

## 练习1.21
编写程序，读取两个 ISBN 相同的 Sales_item 对象，输出他们的和。

解：

```cpp
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item item_1;
    Sales_item item_2;
    std::cin >> item_1;
    std::cout << item_1 << std::endl;
    std::cin >> item_2;
    std::cout << item_2 << std::endl;
    std::cout << "sum of sale items: " << item_1 + item_2 << std::endl;
	return 0;
}
```

命令：
```
./main < data/add_item
```

输出：
```
0-201-78345-X 3 60 20
0-201-78345-X 2 50 25
sum of sale items: 0-201-78345-X 5 110 22
```

## 练习1.22
编写程序，读取多个具有相同 ISBN 的销售记录，输出所有记录的和。

解：

```cpp
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item sum_item;
    std::cin >> sum_item;
    std::cout << sum_item << std::endl;
    for (Sales_item item; std::cin >> item; std::cout << item << std::endl){
        sum_item += item;
    }
    std::cout << "sum of sale items: " << sum_item << std::endl;
	return 0;
}
```

命令：
```
./main < data/add_item
```

输出：
```
0-201-78345-X 3 60 20
0-201-78345-X 2 50 25
sum of sale items: 0-201-78345-X 5 110 22
```

## 练习1.23
编写程序，读取多条销售记录，并统计每个 ISBN（每本书）有几条销售记录。

## 练习1.24
输入表示多个 ISBN 的多条销售记录来测试上一个程序，每个 ISBN 的记录应该聚在一起。

解：

```cpp
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;
    if (std::cin >> total){
        Sales_item trans;
        while (std::cin >> trans){
            if (total.isbn() == trans.isbn()) {
                total += trans;
            }
            else {
                std::cout << total << std::endl;
                total = trans;
            }
        }
        std::cout << total << std::endl;
    }
    else {
        std::cerr << "No data?!" << std::endl;
        return -1;
    }
    return 0;
}
```

命令：
```
./main < data/book_sales
```

输出：
```
0-201-70353-X 4 99.96 24.99
0-201-82470-1 4 181.56 45.39
0-201-88954-4 16 198 12.375
0-399-82477-1 5 226.95 45.39
0-201-78345-X 5 110 22
```
## 练习1.25
借助网站上的`Sales_item.h`头文件，编译并运行本节给出的书店程序。
