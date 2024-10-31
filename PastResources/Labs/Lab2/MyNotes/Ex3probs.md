# 在exercise3 里需要make的地方，报错

>make : 无法将“make”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。请检查名称的拼写，如果包括路径，请确保路径正确，然后再试一次。

可以把指令换成 `mingw32-make vector-test`
因为文件夹里那个不叫make, 叫mingw32-make
当然也可以直接将mingw32-make.exe程序重命名为“make”，再编译就可以啦

# valgrind : 无法将“valgrind”项识别为 cmdlet、函数、脚本文件或可运行程序的名称。、

看起来您在 Windows 环境下遇到了 `valgrind` 命令无法识别的问题。这是因为 Valgrind 是一个在 Linux/Unix 环境下常用的工具，而在 Windows 上并不直接支持。

如果您需要在 Windows 上进行类似 Valgrind 的内存检查，您可以尝试使用其他工具，例如 Microsoft 的 Debugging Tools for Windows（WinDbg）或者 Visual Studio 自带的内存检查工具。

另外，您也可以考虑在虚拟机或者双系统中运行 Linux 操作系统，这样就可以直接使用 Valgrind 工具来进行内存检查了。

**哈哈归根结底是因为我没有装Linux!**

装完一番调试 又装了几个package 见README
调试了一下
```c
make vector-memcheck
valgrind --tool=memcheck --leak-check=full --track-origins=yes ./vector-test
==3528== Memcheck, a memory error detector
==3528== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3528== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==3528== Command: ./vector-test
==3528==
Calling vector_new()
Calling vector_delete()
vector_new() again
These should all return 0 (vector_get()): 0 0 0
Doing a bunch of vector_set()s
These should be equal:
98 = 98
15 = 15
65 = 65
-123 = -123
21 = 21
43 = 43
0 = 0
0 = 0
0 = 0
3 = 3
Test complete.
==3528== 
==3528== HEAP SUMMARY:
==3528==     in use at exit: 0 bytes in 0 blocks
==3528==   total heap usage: 9 allocs, 9 frees, 3,280 bytes allocated
==3528==
==3528== All heap blocks were freed -- no leaks are possible
==3528==
==3528== For lists of detected and suppressed errors, rerun with: -s
==3528== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
应该是没问题了