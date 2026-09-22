# cpp-text-query

一个基于 C++ 的简单文本查询程序。程序读取文本文件，建立单词到行号的索引，并输出指定单词出现的次数和所在行内容。

## 功能

- 按行读取文本文件
- 建立单词索引
- 查询单词出现次数
- 显示单词出现的行号和完整内容
- 支持连续查询，输入 `q` 退出

## 编译

使用支持 C++11 或更高版本的编译器：

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic `
    "文本查询程序/main.cpp" `
    "文本查询程序/textquery.cpp" `
    -o textquery.exe
```

也可以使用 Visual Studio 打开根目录下的 `文本查询程序.sln` 编译项目。

## 运行

运行时传入待查询的文本文件路径：

```powershell
.\textquery.exe .\sample.txt
```

程序启动后输入单词，例如：

```text
请输入要查询的单词（输入 q 退出）：
hello
hello occurs 2 times
    (line 1) hello world
    (line 3) hello again
```

输入 `q` 退出查询。

## 项目结构

| 文件 | 说明 |
| --- | --- |
| `文本查询程序/main.cpp` | 程序入口和交互查询逻辑 |
| `文本查询程序/textquery.h` | `TextQuery` 类声明 |
| `文本查询程序/textquery.cpp` | 文本读取和索引构建实现 |
| `文本查询程序/queryresult.h` | 查询结果和输出函数 |

## 许可证

本项目仅用于学习 C++ 文件处理、容器和智能指针的使用。
