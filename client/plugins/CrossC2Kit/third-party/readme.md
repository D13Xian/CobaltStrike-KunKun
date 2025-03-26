# 插件提交方式


1. git clone https://github.com/CrossC2/CrossC2Kit.git
2. cd CrossC2Kit && mkdir third-party
3. 将插件置入该目录后进行 pull request
4. pull request 项目将在自动编译通过后进行合并


```c
├── third-party
│   ├── test.cna
│   └── util
│       ├── lpe  // 插件分类
│       │   ├── cve-2021-1102       // 插件名称
│       │   │   ├── load.cna        // 插件启动入口 *
│       │   │   ├── readme.md       // 插件文档
│       │   │   ├── src             // 插件包含的二进制组件源码目录
│       │   │   │   ├── exp.c       // 待编译的源码 *
│       │   │   │   └── makefile    // 自动编译的工程配置文件 *
│       │   │   └── testa.cna       // 插件内部用到的cna脚本
│       │   └── cve-2022-2202
│       │       ├── load.cna
│       │       ├── readme.md
│       │       └── src
│       │           ├── exp.c
│       │           └── makefile
│       └── pass
│           ├── linux-login
│           │   ├── load.cna
│           │   └── src
│           │       ├── exp.c
│           │       └── makefile
│           └── readme.md
```

5. 编译结果将在 **summary** 中显示，包含`系统架构信息`、`编译过程`、`编译结果符号信息`、`Linux包含GLIBC版本信息`、`编译整体结果` 
