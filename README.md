# C-language：C 语言学习入口

按主题学习、运行最小示例、完成练习，并记录易错点。适合从基础语法逐步学到结构体。

## 两个仓库如何分工

| 仓库 | 保存内容 | 新内容放哪里 |
| --- | --- | --- |
| [C-language](https://github.com/Inspector-ran/C-language) | 主题笔记、最小示例、本仓库配套练习 | 知识总结和下面五道练习的解答 |
| [C-practise](https://github.com/Inspector-ran/C-practise) | 教材章节作业、日常刷题、实战项目 | 教材题、平台题、2048 等完整项目 |

同一道已有题目只保留一份代码：在这里添加原文件链接和复习心得，不复制到两个仓库。现有作业与项目保留在 C-practise。

## 学习顺序与导航

| 顺序 | 主题 | 示例 | 学习重点 |
| --- | --- | --- | --- |
| 1 | [基础语法](01-basics/README.md) | [变量与循环](01-basics/variables_and_loops.c) | 类型、运算、输入输出、分支、循环 |
| 2 | [数组](02-arrays/README.md) | [数组求和](02-arrays/array_sum.c) | 下标、长度、遍历 |
| 3 | [函数](03-functions/README.md) | [两数最大值](03-functions/max_of_two.c) | 声明、参数、返回值、作用域 |
| 4 | [指针](04-pointers/README.md) | [交换变量](04-pointers/swap.c) | 地址、解引用、通过指针修改数据 |
| 5 | [结构体](05-structs/README.md) | [学生信息](05-structs/student.c) | 自定义类型、成员访问 |
| 6 | [练习题](06-exercises/README.md) | 五道主题练习与旧仓库索引 | 独立实现、边界检查、复盘 |

每学完一个主题就完成对应练习，不必等五个主题全部学完。

## 获取与运行

在 GitHub 点击 **Code → Download ZIP** 并解压，或运行：

```text
git clone https://github.com/Inspector-ran/C-language.git
cd C-language
```

需要支持 C11 的 C 编译器。所有示例都是独立程序、没有第三方依赖，也不读取键盘输入。下面命令均在仓库根目录执行。

### Windows PowerShell：GCC 或 Clang

先确认所选编译器已安装并可在终端中使用：

```powershell
New-Item -ItemType Directory -Force build | Out-Null
gcc -std=c11 -Wall -Wextra -Wpedantic 01-basics/variables_and_loops.c -o build/variables_and_loops.exe
.\build\variables_and_loops.exe
```

使用 Clang 时，将命令中的 `gcc` 替换为 `clang`。编译成功后再运行；换主题时，同时替换源文件路径和输出文件名。

### Linux / macOS：GCC 或 Clang

```sh
mkdir -p build
cc -std=c11 -Wall -Wextra -Wpedantic 01-basics/variables_and_loops.c -o build/variables_and_loops
./build/variables_and_loops
```

此处 `cc` 应为 GCC 或 Clang，也可以直接使用 `gcc` 或 `clang`。

### Windows：Visual Studio

安装“使用 C++ 的桌面开发”工作负载，在 **Developer PowerShell for VS** 中进入仓库根目录后运行：

```powershell
New-Item -ItemType Directory -Force build | Out-Null
cl /nologo /TC /std:c11 /W4 /utf-8 01-basics/variables_and_loops.c /Fobuild/variables_and_loops.obj /Febuild/variables_and_loops.exe
.\build\variables_and_loops.exe
```

使用支持 C11 的较新版本 Visual Studio。`/TC` 明确按 C 编译；源码保留 `.c` 后缀。在 IDE 中，每个示例使用单独项目，或每次只将一个示例加入生成。

**每次只编译一个示例。** 每个文件都有自己的 `main`，把全部源文件链接到同一个程序会产生重复入口错误。

## 每次学习的流程

1. 阅读主题说明，先猜测示例输出。
2. 编译运行，与文档的预期输出比较。
3. 修改数据或条件，解释输出为什么变化。
4. 独立完成[配套练习](06-exercises/README.md)，验证普通情况与边界情况。
5. 在对应主题 README 末尾记录“现象 → 原因 → 修正方法”。

示例输出汇总：

| 文件 | 预期输出 |
| --- | --- |
| variables_and_loops.c | `15` |
| array_sum.c | `15` |
| max_of_two.c | `7` |
| swap.c | 两行：`Before: 3, 7`、`After: 7, 3` |
| student.c | 三行：`Name: Lin`、`Age: 18`、`Score: 92.5` |

## 持续扩展约定

- 文档和笔记使用中文；目录和源码名使用有意义的英文；源码使用标准 C11。
- 示例一次突出一个概念。配套练习使用题号和主题命名，例如 `06-exercises/01-sum-even.c`。
- 教材作业、刷题和完整项目继续提交到 C-practise；这里只增加链接和知识总结。
- 后续按需新增 `07-strings/`、`08-file-io/` 等主题，不预先建立大量空目录。
- 编译产物放入 `build/`，不提交可执行文件或 IDE 缓存。
