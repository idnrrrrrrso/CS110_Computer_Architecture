Lab1文档里说建议安装linux的虚拟机或者双系统Ubuntu，但是我安装的是WSL.
WSL（Windows Subsystem for Linux）不属于虚拟机或双系统的范畴，而是一种在 Windows 操作系统上运行 Linux 应用程序和命令行工具的技术。
有些指令和功能确实只能在linux上有，所以现在先下载一个wsl试试看

通过在windows powershell 终端键入 wsl 打开linux 终端，exit 退出


好吧最终还是单独为它装了一个gcc

win里可以用gdb, 但还是给wsl装了一个cgdb

安装了 valgrind

2.16 完成lab3