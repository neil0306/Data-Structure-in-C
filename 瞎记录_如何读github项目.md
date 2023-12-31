记录一些网上看到的零散观点.

# 预备知识 (以后端为例)
1. Linux 系统使用
2. 熟悉 Linux syscall API 的使用
   1. 学习 Linux C 相关课程
   2. 学习 Linux C 的网络编程 (熟悉 socket API, 知道它在干嘛)
   3. 其他 Linux 系统编程相关书籍
3. 基于 Linux syscall 写项目
4. 熟悉C/C++/ASM(汇编)
   1. 内存与数据之间的关系, 在调试器打印信息时, 要能看懂数据与地址之间的联系
5. 具备调试能力: 程序调试能力 + 网络调试能力
   - GDB/PDB 调试器等

# 看到一个开源项目, 要做的事情
- git clone, 尽可能在linux上(如果项目支持)完整跑一把, 体验一下怎么用, 有什么效果.
  - 通过官方手册/readme, 了解项目的基本功能, 有什么用.

- 抽离/裁剪出核心代码  ==> 对整个项目有一个大概的了解, 知道它的实现框架.
  1. 将抽离出来的代码新建一个位置(项目)存放, 抽离出来的代码要求能够独立运行(能编译+能跑), 依赖尽量少.
        ```txt
        1. 根据**运行流程**来裁剪代码, 只保留核心部分
            可以先画思维导图, 或者 在文本文档中列出大纲
        2. 以方便阅读和理解为目的去 优化/简化 代码.
            比如一个结构体, 如果看上去觉得属于不太重要的成员(如 time 之类的), 就先去掉, 以减少阅读的负担.
            对于一些函数的重要性感知, 大部分是基于个人对项目的使用熟悉程度来决定的, 所以第一步, 熟悉使用方法也是很重要的一点.
        ```
  2. 走调试的方式阅读代码
      - 在核心代码打断点, 然后通过调试器指令查看代码
      - 看代码的时候可以不用 linux 看, 可以在 Win/macOS 上看, linux的阅读器对于阅读大量代码感觉不太友好 

- 模仿验证, 实现核心
