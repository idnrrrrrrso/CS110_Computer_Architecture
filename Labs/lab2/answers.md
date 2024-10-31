Here are the answers to your questions:

1. **Passing command line arguments to a program when using gdb**:
   You can pass command line arguments to a program being debugged by simply appending them after the `run` command. For example:
   ```bash
   gdb ./program
   (gdb) run arg1 arg2
   ```

2. **Setting a breakpoint with conditions**:
   You can set a breakpoint with conditions using the `break` command with the `-if` option. For example:
   ```bash
   (gdb) break filename.c:line_number if condition
   ```

3. **Executing the next line of code**:
   To execute the next line of code after stopping at a breakpoint, you can use the `next` command. For example:
   ```bash
   (gdb) next
   ```

4. **Debugging code inside a function call**:
   To debug the code inside a function call instead of executing it all at once, you can use the `step` command. For example:
   ```bash
   (gdb) step
   ```

5. **Resuming the program after stopping at a breakpoint**:
   You can resume the program after stopping at a breakpoint using the `continue` command. For example:
   ```bash
   (gdb) continue
   ```

6. **Seeing the value of a variable or expression**:
   To see the value of a variable or an expression, you can use the `print` command or its shorthand `p`. For example:
   ```bash
   (gdb) print variable_name
   (gdb) p 1 + 2
   ```

7. **Configuring gdb to print the value of a variable after every step**:
   You can use the `display` command to configure gdb to print the value of a variable after every step. For example:
   ```bash
   (gdb) display variable_name
   ```

8. **Printing a list of all variables and their values in the current function**:
   You can use the `info locals` command to print a list of all variables and their values in the current function. For example:
   ```bash
   (gdb) info locals
   ```

9. **Exiting out of gdb**:
   To exit out of gdb, you can use the `quit` command. For example:
   ```bash
   (gdb) quit
   ```

These are the basic gdb commands to perform various debugging tasks.