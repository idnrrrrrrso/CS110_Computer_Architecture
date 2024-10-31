> All the vector-memcheck rule does is run the following valgrind command on our executable. Explain what each of the flags mean.
```c
$ valgrind --tool=memcheck --leak-check=full --track-origins=yes [OS SPECIFIC ARGS] ./<executable>
```

Valgrind 是一款用于检测内存错误的工具，其中 `memcheck` 是 Valgrind 的一个子工具，用于检查内存相关的问题。下面是 `valgrind` 命令中使用的每个选项的含义：

- `--tool=memcheck`：指定要使用的 Valgrind 工具。在这里，我们使用 `memcheck`，它是用于检测内存错误的默认工具。

- `--leak-check=full`：指定 Valgrind 在程序运行结束后检查内存泄漏的程度。`full` 表示 Valgrind 将报告所有未释放的内存块，包括在程序结束时仍然存在的内存泄漏。

- `--track-origins=yes`：指定 Valgrind 跟踪未初始化的内存使用的级别。在这里，我们设置为 `yes`，表示 Valgrind 将尽可能详细地跟踪未初始化的内存，并在检测到时提供相关信息。这对于查找程序中潜在的未初始化内存访问错误很有帮助。

- `[OS SPECIFIC ARGS]`：这个选项是根据操作系统的具体要求进行设置的参数。不同的操作系统可能需要不同的参数来正确地运行 Valgrind。例如，在 Linux 上可能需要添加 `--quiet` 参数来避免输出额外的警告信息。

- `./<executable>`：表示要运行 Valgrind 检查的可执行文件的路径。这是测试程序的可执行文件。

通过这些选项，Valgrind 将执行内存检查并报告程序中的内存错误，包括内存泄漏和未初始化的内存使用。