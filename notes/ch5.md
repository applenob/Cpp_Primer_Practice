# 第五章 表达式

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

