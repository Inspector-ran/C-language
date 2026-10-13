# C-language 完整使用指南

这份指南面向使用 Windows 和 Visual Studio 自学 C 的初学者。从把项目拿到电脑上开始，带你完成“运行示例 → 修改代码 → 做题 → 测试 → 记录笔记 → 上传 GitHub”。

学校考 C++ 时，可以用本仓库巩固共同基础，但考试写法应以单独的 [C++ 项目](https://github.com/Inspector-ran/Cplus)和老师要求为准。两个语言项目各自维护自己的示例，不把同一文件在两个仓库来回复制。

[返回项目首页](README.md) · [直接查看练习题](06-exercises/README.md)

## 1. 第一次使用：先完成这五步

1. 下载或克隆仓库，打开包含 `01-basics`、`06-exercises` 和 `README.md` 的目录。
2. 打开 **Developer PowerShell for Visual Studio**，切换到这个目录。
3. 按第 4 节编译 `01-basics/variables_and_loops.c`，确认输出为 `15`。
4. 在编辑器里把 `limit = 5` 改成 `limit = 10`，保存并重新编译，确认输出变成 `55`。
5. 恢复示例或记录本次实验，再阅读基础语法说明，开始第 01 道配套练习。

先成功跑通一个文件，再学习提交代码。今天不需要配置复杂工程或一次做完全部题目。

## 2. 这个项目包含什么

```text
C-language/
├── README.md                     项目入口与快速运行
├── USAGE.md                      本使用指南
├── .gitignore                    Git 忽略规则
├── 01-basics/                    基础语法与循环求和
├── 02-arrays/                    数组与遍历求和
├── 03-functions/                 函数与两数最大值
├── 04-pointers/                  指针与交换变量
├── 05-structs/                   结构体与学生信息
├── 06-exercises/README.md        五道配套练习题
└── build/                       你编译时生成，不存入仓库
```

每个主题目录都有一份 README 和一个独立的 `.c` 文件。README 是 Markdown 文档，GitHub 会直接排版显示；`.c` 是源代码，需要编译才能运行。

本项目由多个独立小程序组成，没有统一启动按钮，也没有需要整体打开的 `.sln`。五个文件各有一个 `main`，一次只编译其中一个。配套题目前只有题目，解答文件需要你自己创建。

## 3. 怎样拿到电脑上

### 方式 A：下载 ZIP，最快开始

1. 打开 [C-language 仓库](https://github.com/Inspector-ran/C-language)。
2. 在仓库的 Code 页面点击绿色 **Code** 按钮，再选择 **Download ZIP**。
3. 将压缩包完整解压到你习惯的学习目录；不要直接在压缩包窗口内编译。
4. 找到真正包含 `README.md` 和 `01-basics` 的那一层。GitHub 下载的文件夹通常叫 `C-language-main`，不影响使用。

后续网页更新不会自动同步到这个解压目录。重新下载时保留自己的练习文件，逐个核对差异，不要直接覆盖尚未上传的作业。

### 方式 B：Git 克隆，方便长期同步

已经安装 Git 的情况下，在你想存放学习项目的父目录打开终端：

```powershell
git clone https://github.com/Inspector-ran/C-language.git
Set-Location C-language
```

克隆只需要做一次。以后打开已有目录，按第 9 节更新即可。若目标目录已经存在，不要反复克隆到同一个位置。

### 确认自己进入了正确目录

从资源管理器地址栏复制实际路径，然后在开发者终端执行：

```powershell
Set-Location -LiteralPath "替换为你电脑上的仓库文件夹完整路径"
Get-Location
Get-ChildItem
```

第一行必须先替换引号内的文字。成功后应看到 `01-basics`、`02-arrays`、`README.md` 等。后文命令均假定你保持在仓库根目录。

## 4. 用 Visual Studio 运行第一个 C 程序

### 4.1 准备编译环境

电脑上已有 Visual Studio 和可用的 C/C++ 编译器时，不必另装 GCC。若缺少组件，在 Visual Studio Installer 中检查“使用 C++ 的桌面开发”工作负载及 Windows SDK。

启动 Visual Studio，在菜单中打开 **工具 → 命令行 → Developer PowerShell**。也可在 Windows 开始菜单搜索 Developer PowerShell。它会为编译器设置环境；普通 PowerShell 不一定能找到 `cl`。[微软开发者终端说明](https://learn.microsoft.com/en-us/visualstudio/ide/reference/command-prompt-powershell?view=visualstudio)

Visual Studio 与 Visual Studio Code 是不同软件；本节指 Visual Studio。

### 4.2 输入编译命令

进入仓库根目录后，依次执行：

```powershell
New-Item -ItemType Directory -Force build | Out-Null
cl /nologo /TC /std:c11 /W4 /utf-8 01-basics/variables_and_loops.c /Fobuild/variables_and_loops.obj /Febuild/variables_and_loops.exe
```

接着单独执行：

```powershell
$LASTEXITCODE
```

输出 `0` 表示上一条编译命令成功。确认没有编译错误后再运行：

```powershell
.\build\variables_and_loops.exe
```

应显示：

```text
15
```

如果编译失败，先处理错误，不要继续运行残留的旧 `.exe`。

### 4.3 编译命令各部分是什么意思

| 部分 | 作用 |
| --- | --- |
| cl | Visual Studio 的 C/C++ 编译器 |
| /TC | 明确按 C 编译 |
| /std:c11 | 使用 C11 标准模式 |
| /W4 | 显示较详细的编译警告 |
| /utf-8 | 按 UTF-8 处理源码与执行字符集 |
| 01-basics/variables_and_loops.c | 本次要编译的源码 |
| /Fobuild/...obj | 中间目标文件写到 build |
| /Febuild/...exe | 生成的可执行文件写到 build |
| .\build\...exe | 在 PowerShell 中运行该文件 |

源码使用 `.c` 后缀；Visual Studio 的 C11 设置及 `/TC` 选项可参阅 [微软 C11 支持说明](https://learn.microsoft.com/en-us/cpp/overview/install-c17-support?view=msvc-170)。

### 4.4 修改一次，确认真的掌握运行流程

用 Visual Studio 的“文件 → 打开 → 文件”或其他文本编辑器打开源码，找到：

```c
const int limit = 5;
```

将 5 改成 10，Ctrl+S 保存，再运行上面的编译和执行命令。现在应输出 `55`。

这说明你运行的是修改后的程序。接着可以把上限恢复为 5，使示例继续与 README 的输出一致；也可以保留自己的实验并在复盘中说明变化。

### 4.5 如果更喜欢 Visual Studio 项目界面

可以另外创建一个 C++ 类型的“空项目”，只添加当前这一个已有 `.c` 文件。在项目属性中选择按 C 编译（`/TC`）及 C11 标准；相关设置见上面的微软说明。

设置运行项目后生成并启动即可。添加“现有项”时核对它引用的是仓库内的原文件；不要编辑一份副本却提交另一份。切换示例时，移除或排除上一个带 `main` 的源码，避免多个入口参与生成。刚开始用前面的单文件命令更容易确认自己在编译哪份文件。

## 5. 其余四个示例怎样运行

每次选择下面的一组，先编译，成功后再执行。先确保已经创建 `build`。

### 数组

```powershell
cl /nologo /TC /std:c11 /W4 /utf-8 02-arrays/array_sum.c /Fobuild/array_sum.obj /Febuild/array_sum.exe
.\build\array_sum.exe
```

预期：`15`。把数组改成 `{-2, 0, 5}`，重新编译后应得到 `3`。

### 函数

```powershell
cl /nologo /TC /std:c11 /W4 /utf-8 03-functions/max_of_two.c /Fobuild/max_of_two.obj /Febuild/max_of_two.exe
.\build\max_of_two.exe
```

预期：`7`。尝试传入 `(-3, -7)` 和 `(5, 5)`，结果分别为 -3 和 5。解释函数为何要返回一个值。

### 指针

```powershell
cl /nologo /TC /std:c11 /W4 /utf-8 04-pointers/swap.c /Fobuild/swap.obj /Febuild/swap.exe
.\build\swap.exe
```

预期：

```text
Before: 3, 7
After: 7, 3
```

重点解释 `&first`、`int *first`、`*first` 的区别，以及为什么必须临时保存原值。

### 结构体

```powershell
cl /nologo /TC /std:c11 /W4 /utf-8 05-structs/student.c /Fobuild/student.obj /Febuild/student.exe
.\build\student.exe
```

预期：

```text
Name: Lin
Age: 18
Score: 92.5
```

尝试更换姓名、年龄和成绩。注意本例对象带 `const`，可以修改源码中的初始化值，但不能在运行过程中给它的成员重新赋值。

## 6. 五道练习怎样做

先打开[完整题目](06-exercises/README.md)。下面是导航，不替代题目中的输入范围与格式要求。

| 题号 | 要创建的文件 | 目标 | 至少验证 |
| --- | --- | --- | --- |
| 01 | 01-sum-even.c | 1 到 n 的偶数和 | 0、1、2、10、100 |
| 02 | 02-array-sum.c | 先存入数组，再遍历求和 | 单元素、负数、20 个元素 |
| 03 | 03-max-of-three.c | 自定义函数求三个数最大值 | 全负数、三数相同、最大值位置变化 |
| 04 | 04-reverse-array.c | 用指针原地逆序 | 单元素、奇数长度、偶数长度、重复值 |
| 05 | 05-student-scores.c | 结构体数组求平均与最高分 | 一名学生、同分、0 分、100 分 |

这些文件保存到 `06-exercises`。写第一题时，可从下面的入口框架开始；它还没有实现题目，不能直接作为答案提交：

```c
#include <stdio.h>

int main(void)
{
    /* TODO: read input, validate it, compute, then print. */
    return 0;
}
```

### 从“题目”走到“可运行答案”

1. 用自己的话写清输入、输出及合法范围。
2. 在纸上算一个小例子。
3. 分别写输入读取、范围检查、计算和输出。
4. 保存为指定的 `.c` 文件。
5. 编译成功后，运行并输入数据。
6. 测试普通情况、边界情况及题目要求处理的非法输入。
7. 记录通过的测试，再提交代码。

题目要求检查读取结果。例如 `scanf` 读取一个整数时，返回值应为 1；不能在读取失败后继续使用变量。

Visual Studio 可能对标准 `scanf` 提示 C4996。本项目保留标准 C 写法，可在编译练习时局部使用 `/D_CRT_SECURE_NO_WARNINGS`。它只关闭相应的微软 CRT 弃用提示，不会替你检查输入，也不能修复越界。[微软 CRT 说明](https://learn.microsoft.com/en-us/cpp/c-runtime-library/security-features-in-the-crt?view=msvc-170)

第一题写完后编译：

```powershell
cl /nologo /TC /std:c11 /W4 /utf-8 /D_CRT_SECURE_NO_WARNINGS 06-exercises/01-sum-even.c /Fobuild/01-sum-even.obj /Febuild/01-sum-even.exe
```

成功后运行，输入 `10` 并回车，预期输出为 `30`：

```powershell
.\build\01-sum-even.exe
```

也可以通过管道提供输入：

```powershell
"10" | .\build\01-sum-even.exe
```

多项数字输入可以用空格分隔。第二题完成后，可用：

```powershell
"5 1 2 3 4 5" | .\build\02-array-sum.exe
```

第二题必须先自行创建源码并编译为这个文件名；预期输出为 15。其他题目同理，不要在尚未生成程序时直接复制运行命令。

### 怎样判断一道题完成了

编译成功只是第一步。还应满足：输出格式与题目一致，范围内的边界数据正确，读取失败或越界输入按题意处理，能够解释算法及用到的语法。题面未要求的额外提示语不要输出。

## 7. 如果以后使用 GCC 或 Clang

你目前使用 Visual Studio，可跳过本节。下面只是已经配置好相应编译器时的替代命令。

Windows PowerShell：

```powershell
New-Item -ItemType Directory -Force build | Out-Null
gcc -std=c11 -Wall -Wextra -Wpedantic 01-basics/variables_and_loops.c -o build/variables_and_loops.exe
.\build\variables_and_loops.exe
```

Clang 将 `gcc` 换成 `clang`。Linux/macOS 使用：

```sh
mkdir -p build
cc -std=c11 -Wall -Wextra -Wpedantic 01-basics/variables_and_loops.c -o build/variables_and_loops
./build/variables_and_loops
```

以上 `cc` 应为 GCC 或 Clang。只替换源码与输出文件名即可编译其他示例，不需要新增构建系统。

## 8. 每天怎样用这个仓库

一次学习可以控制在 40～60 分钟，不必一天学完一个主题。

| 环节 | 建议时间 | 具体做什么 |
| --- | --- | --- |
| 回顾 | 5 分钟 | 不看答案，解释上次错在哪里 |
| 阅读 | 10 分钟 | 读主题 README 和最小示例，先写下预测输出 |
| 实验 | 10 分钟 | 运行示例，只修改一个条件或一组数据，再解释变化 |
| 做题 | 15～25 分钟 | 独立实现一道配套题，测普通值和边界值 |
| 复盘 | 5 分钟 | 保存代码，记录错因，提交今天的进展 |

“看懂”之后，还要能不看示例重新写出关键部分。遇到编译错误时，优先处理第一条错误，后面的错误可能只是连带结果。

### 复盘模板

把下面内容复制到对应主题 README 的“我的复盘”下面，再填写：

```markdown
### YYYY-MM-DD：本次练习

- 主题 / 题号：
- 我原本以为：
- 实际发生：
- 原因：
- 修改方法：
- 测试输入 → 预期输出 → 实际输出：
- 下次复习时要能回答的问题：
```

一条有用的记录可以是：“循环条件写成 i <= count，访问了数组末尾之后的位置；改成 i < count，并用单元素数组重新验证。”不要只写“数组越界，下次注意”。

## 9. 怎样保存到 GitHub

**本地保存文件、Git 提交、上传 GitHub 是三个不同动作。** 按下 Ctrl+S 只更新电脑上的文件；完成 commit 才形成版本记录；push 后网页才会显示新版本。

### 方法 A：暂时不用 Git 命令

适合通过 ZIP 下载、还没学 Git 的阶段。

1. 先在电脑上编译运行，确认文件已经保存。
2. 打开自己的仓库，进入目标目录，例如 `06-exercises`。
3. 选择 **Add file → Upload files**，上传这次写好的源码文件。
4. 检查文件名、目录及差异，填写说明，例如“完成练习 01，补充边界测试”，再提交。
5. 改笔记可在对应 README 页面使用编辑按钮；保存前同样检查内容。
6. 上传后刷新页面，确认新文件确实出现在目标目录。

只上传本次修改的源码和笔记，不要上传整个下载包或编译生成的文件。网页上传不会自动应用你电脑上的 `.gitignore`，需要自己选对文件。网页文件上传流程可参阅 [GitHub 官方说明](https://docs.github.com/en/repositories/working-with-files/managing-files/adding-a-file-to-a-repository)。

ZIP 解压目录通常没有 Git 历史，不能直接在那里执行 `git pull` 或 `git push`。以后改用 Git 时，在新的空位置克隆仓库，再将自己尚未上传的源码逐个核对并放进去。

### 方法 B：使用 Git 持续练习

只适用于通过 `git clone` 获取的工作副本。下面命令在仓库根目录执行，且默认你在 `main` 分支。

学习开始前：

```powershell
git status
git branch --show-current
git pull --ff-only
```

先看 `git status`：有尚未保存到版本记录的修改时，应先整理并提交，不要直接覆盖文件。第三条命令在本地可以直接跟上远程进度时更新；双方都有独立提交时会停止。[Git 官方文档](https://git-scm.com/docs/git-pull)说明了这一行为。

完成一道题后，按实际文件名执行，例如：

```powershell
git status
git diff
git add 06-exercises/01-sum-even.c
git diff --cached
git commit -m "practice: complete exercise 01 with boundary checks"
git push origin main
```

这里以第 01 题为例；提交其他题目时，换成实际文件名。新文件在暂存前不一定出现在 `git diff` 中，`git status` 和 `git diff --cached` 可以帮助检查。笔记改了，也要按实际路径添加。

每条命令执行成功后再继续。上传后打开 GitHub 核对最新提交；`git push` 才把本地提交送到远程仓库。[Git 官方说明](https://git-scm.com/docs/git-push)

第一次提交若提示缺少姓名或邮箱，在当前仓库内设置：

```powershell
git config user.name "Inspector-ran"
git config user.email "替换为你的GitHub提交邮箱"
```

第二条需替换为真实提交邮箱，也可使用 GitHub 邮箱设置中提供的 noreply 地址。这是提交署名配置，不是登录操作。

如果 push 要求登录，使用安装的 Git 凭据管理器提供的 GitHub 登录流程。若提示远程有新提交，先查看状态；不要使用强制推送来掩盖差异。无法快进或出现冲突时，保留当前文件和完整报错，再核对本地、远程各改了什么。

## 10. 常见问题排查

| 现象 | 常见原因 | 下一步 |
| --- | --- | --- |
| 找不到 cl | 打开的是普通终端，或没有安装编译工具 | 从 Visual Studio 的“工具 → 命令行”打开 Developer PowerShell；必要时在安装器检查桌面 C++ 工作负载 |
| 找不到源文件 / C1083 | 当前目录不对、文件名拼错、源码尚未创建 | 用 Get-Location 和 Get-ChildItem 检查位置、路径和扩展名 |
| 找不到 stdio.h 或 iostream | 开发环境未初始化，或组件安装不完整 | 重新打开开发者终端；再检查编译器与 Windows SDK 组件 |
| LNK2005 / main 已定义 | 一次链接了多个带 main 的源码文件 | 每次只编译一个示例；IDE 项目中只保留一个入口 |
| 编译后找不到 exe | 编译失败，或输出路径和运行路径不一致 | 先看编译错误和退出码，再核对 build 下的文件名 |
| 改了代码但输出没变 | 忘记保存、忘记重新编译，或运行了旧程序 | Ctrl+S → 重新编译 → 确认成功 → 运行对应 exe |
| 窗口一闪而过 | 直接双击了程序 | 从终端运行；无需为了停住窗口加入 system("pause") |
| 运行后没反应 | 程序正在等待输入，或循环未结束 | 按题目输入数据并回车；本仓库五个示例不需要输入，练习需要 |
| 数组结果混乱 / 程序崩溃 | 越界、未初始化、无效指针等 | 检查下标范围、初始值、指针指向和循环边界 |
| 中文显示异常 | 源码保存编码与终端显示设置不一致 | 使用 UTF-8 保存源码；先用项目中的英文输出验证程序逻辑 |
| 文件其实叫 xxx.c.txt 或 xxx.cpp.txt | 编辑器追加了文本扩展名 | 在资源管理器显示文件扩展名，保存时选择所有文件并核对后缀 |
| GitHub 看不到修改 | 只在本地保存，或只 commit 没有 push | 查看 git status、push 结果及网页当前分支 |
| not a git repository | 在 ZIP 解压目录或错误目录执行 Git | 换到克隆的仓库；ZIP 用户可先使用网页上传 |
| push 被拒绝 | 登录、写权限、分支规则或远程更新问题 | 阅读具体错误，保留本地修改后处理对应原因 |

要定位问题，可以准备：编译器名称、完整命令、完整报错、相关源码、输入数据、预期输出和实际输出。比“运行不了”的信息更有用。

## 11. 考前怎样复习

按学校题型调整下面的方法，不把运行通过当成唯一目标。

- **程序阅读题**：先手算变量变化和输出，再编译验证；能解释每轮循环及函数调用。
- **程序填空题**：重点检查循环边界、返回值、数组下标、指针访问和成员访问。
- **程序改错题**：区分编译错误、运行时错误与逻辑错误；写出触发错误的最小输入。
- **编程题**：先写输入输出要求，再写步骤，最后写代码；至少验证一个普通情况和两个边界情况。

每个主题能做到“讲清概念、手算输出、独立实现、测试边界”，再进入下一主题。遇到学校试卷中特有的输入输出格式，以试卷要求为准。

## 12. 文件归档与后续扩展

本仓库的主题说明、示例和配套题保留在这里。教材题、平台刷题、课程大作业以及完整小游戏继续放入 [C-practise](https://github.com/Inspector-ran/C-practise)。

判断一个新文件放哪里：

| 新内容 | 放置位置 |
| --- | --- |
| 对某个知识点的总结 | 对应主题 README 的复盘部分 |
| 一个概念的短小示例 | 对应主题目录，使用有意义的英文文件名 |
| 本仓库指定的练习答案 | 06-exercises，按题号命名 |
| 学校教材原题或完整作业 | C-practise，可在这里建立链接 |
| 编译生成的 exe、obj 或缓存 | build 或 IDE 输出目录，不作为学习源码上传 |

旧项目的 `.cpp` 后缀不代表它已经覆盖了 C++ 的全部知识，也不保证使用标准 C++ 写法。先阅读依赖与语法，不要仅靠改扩展名迁移代码。

以后增加主题时，一次增加一个目录，配套写清学习目标、最小示例、预期输出和练习入口。避免预先创建大量没有内容的文件夹。
