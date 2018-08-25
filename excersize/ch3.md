# 第三章 字符串、向量和数组

## 练习3.1

使用恰当的using 声明重做 1.4.1节和2.6.2节的练习。

解：

1.4.1

```cpp
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int sum = 0;
	for (int val = 1; val <= 10; ++val) sum += val;

	cout << "Sum of 1 to 10 inclusive is " << sum << endl;
	
	return 0;
}
```

2.6.2 类似

## 练习3.2
编写一段程序从标准输入中一次读入一行，然后修改该程序使其一次读入一个词。

解：

一次读入一行：

```cpp
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main()
{
	string s;
	while (getline(cin,s))
	{
		cout << s << endl;
	}
	return 0;
}
```

一次读入一个词

```cpp
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::getline;

int main()
{
	string s;
	while (cin >> s)
	{
		cout << s << endl;
	}
	return 0;
}
```


## 练习3.3
请说明string类的输入运算符和getline函数分别是如何处理空白字符的。

解：

- 类似`is >> s`的读取：string对象会忽略开头的空白并从第一个真正的字符开始，直到遇见下一空白为止。
- 类似`getline(is, s)`的读取：string对象会从输入流中读取字符，直到遇见换行符为止。


## 练习3.4
编写一段程序读取两个字符串，比较其是否相等并输出结果。如果不相等，输出比较大的那个字符串。改写上述程序，比较输入的两个字符串是否等长，如果不等长，输出长度较大的那个字符串。

解：

比较大的

```cpp
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1 == str2)
			cout << "The two strings are equal." << endl;
		else
			cout << "The larger string is " << ((str1 > str2) ? str1 : str2);
	}

	return 0;
}
```

长度大的

```cpp
#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		if (str1.size() == str2.size())
			cout << "The two strings have the same length." << endl;
		else
			cout << "The longer string is " << ((str1.size() > str2.size()) ? str1 : str2) << endl;
	}

	return 0;
}
```

## 练习3.5
编写一段程序从标准输入中读入多个字符串并将他们连接起来，输出连接成的大字符串。然后修改上述程序，用空格把输入的多个字符串分割开来。

解：

未隔开的：
```cpp
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string result, s;
	while (cin >> s)
	{
		result += s;
	}
	cout << result << endl;

	return 0;
}
```

隔开的：
```cpp
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
	string result, s;
	while (cin >> s)
	{
		result += s + " ";
	}
	cout << result << endl;

	return 0;
}
```


