Here are the answers to your questions:

1. **Passing Command Line Arguments to a Program in GDB**:
   You can pass command line arguments to your program in GDB by using the `--args` option followed by the program name and its arguments. For example:
   ```
   gdb --args ./program arg1 arg2
   ```

2. **Setting a Breakpoint with Conditions**:
   You can set a breakpoint with conditions using the `break` command followed by the function name or line number and the condition enclosed in curly braces `{}`. For example:
   ```
   break function if variable == value
   ```

3. **Executing the Next Line of Code**:
   You can execute the next line of C code in the program after stopping at a breakpoint using the `next` command, abbreviated as `n`.

4. **Debugging Inside a Function**:
   To debug inside a function call, you can use the `step` command, abbreviated as `s`. This will step into the function and allow you to debug the code inside it.

5. **Resuming the Program**:
   To resume the program after stopping at a breakpoint, you can use the `continue` command, abbreviated as `c`.

6. **Viewing Variable Values**:
   You can see the value of a variable or expression in GDB using the `print` command, abbreviated as `p`. For example:
   ```
   print variable
   print 1+2
   ```

7. **Configuring GDB to Print Variable Values After Every Step**:
   You can configure GDB to print variable values after every step using the `display` command followed by the variable name. For example:
   ```
   display variable
   ```

8. **Printing a List of All Variables and Their Values in the Current Function**:
   You can print a list of all variables and their values in the current function using the `info locals` command.

9. **Exiting GDB**:
   To exit GDB, you can use the `quit` command, abbreviated as `q`. If you have unsaved changes in your program, GDB will prompt you to confirm before exiting.