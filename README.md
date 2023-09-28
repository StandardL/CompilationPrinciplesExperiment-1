# 编译原理实验一：C++单词拼装器

## 实验要求：

1. 把 C++源代码中的各类单词（记号）进行拼装分类。
2.  要求应用程序应为 Windows 界面。 
3. 打开一个 C++源文件，列出所有可以拼装的单词（记号）。

## 💻程序

## 截图

![image-20230926213222160](https://github.com/StandardL/CompilationPrinciplesExperiment-1/raw/main/pictures/软件显示示例.png)

### 支持的处理的符号

常规符号：

| 类型       | 单词 | 类型       | 单词 | 类型       | 单词 | 类型       | 单词       |
| ---------- | ---- | ---------- | ---- | ---------- | ---- | ---------- | ---------- |
| 算数运算符 | +    | 关系运算符 | <    | 位运算符   | >>   | 赋值运算符 | <<=        |
| 算数运算符 | -    | 关系运算符 | >=   | 赋值运算符 | =    | 赋值运算符 | >>=        |
| 算数运算符 | *    | 关系运算符 | <=   | 赋值运算符 | +=   | 赋值运算符 | &=         |
| 算数运算符 | /    | 逻辑运算符 | !    | 赋值运算符 | -=   | 赋值运算符 | ^=         |
| 算数运算符 | %    | 逻辑运算符 | \|\| | 赋值运算符 | *=   | 赋值运算符 | \|=        |
| 算数运算符 | ++   | 逻辑运算符 | &&   | 赋值运算符 | /=   | 杂项运算符 | ?:         |
| 算数运算符 | --   | 位运算符   | &    | 赋值运算符 | -=   | 杂项运算符 | ->         |
| 关系运算符 | ==   | 位运算符   | ^    | 赋值运算符 | *=   | 杂项运算符 | *(Pointer) |
| 关系运算符 | !=   | 位运算符   | ~    | 赋值运算符 | /=   | 杂项运算符 | .          |
| 关系运算符 | >    | 位运算符   | <<   | 赋值运算符 | %=   | 杂项运算符 | ,          |

分割符：

| 类型   | 单词 | 类型   | 单词 | 类型   | 单词 | 类型   | 单词 |
| ------ | ---- | ------ | ---- | ------ | ---- | ------ | ---- |
| 分隔符 | {    | 分隔符 | (    | 分隔符 | [    | 分隔符 | :    |
| 分隔符 | }    | 分隔符 | )    | 分隔符 | ]    | 分隔符 | ;    |

字符串：

| 类型       | 单词 |
| ---------- | ---- |
| 字符串标志 | "    |

C++常用关键字：

| asm      | auto       | bool     | break     | case        | catch    | class            | char         |
| -------- | ---------- | -------- | --------- | ----------- | -------- | ---------------- | ------------ |
| const    | const_cast | continue | default   | delete      | do       | double           | dynamic_case |
| else     | enum       | explicit | export    | extern      | false    | float            | for          |
| friend   | goto       | if       | inline    | int         | long     | mutable          | namespace    |
| new      | operator   | private  | protected | public      | register | reinterpret_cast | return       |
| short    | signed     | sizeof   | static    | static_cast | struct   | switch           | template     |
| this     | throw      | true     | try       | typedef     | typeid   | typename         | union        |
| unsigned | using      | virtual  | void      | volatile    | wchar_t  | null             | nullptr      |
| while    | cin        | cout     | include   |             |          |                  |              |

## 🧭编译

### 环境要求

#### Qt 6.2.4

- Qt Design Studio 4.2.0
- Qt 6.2.4
  - MSVC 2019 64-bit
  - MinGW 11.2.0 64-bit
  - Qt 5 Compatibility Module
  - Qt Shader Tools
  - Additional Libraries
- Developer and Designer Tools
  - Qt Creator 11.0.2
  - Qt Creator 11.0.2 CDB Debugger Support
  - Debugging Tools for Windows
  - MinGW 11.2.0 64-bit
  - Qt Installer Framwork 4.6
  - CMake 3.24.2
  - Ninja 1.10.2

#### Visual Studio 2022

选择安装**使用C++的桌面开发**

<img src="https://github.com/StandardL/CompilationPrinciplesExperiment-1/raw/main/pictures/VS组件.png" alt="image-20230926211152531" style="zoom:67%;" />

进入到Visual Studio 2022，在**扩展**>**管理扩展**>**联机**（**Extensions** > **Manage Extensions** > **Online**）处搜索安装Qt Visual Studio Tools.

<img src="https://github.com/StandardL/CompilationPrinciplesExperiment-1/raw/main/pictures/VS插件.png" alt="image-20230926211819218" style="zoom:80%;" />

重启Visual Studio 2022。

点击**扩展**>**Qt VS Tools**>**Qt Versions**，确保已勾选MSVC编译器。若无可手动添加MSVC编译器路径：\\ ${Qt安装目录} \\ {Qt版本号} \ msvc2019_64 \ bin \ qmake.exe

## ☁未来展望

- [ ] QT界面美化
- [ ] UnitTest

## 🔗其他链接

- [Console(CLI)版本](https://github.com/StandardL/ComplieExp1-Console)
