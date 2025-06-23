# GDB Debugging Basics: 

This guide will walk you through compiling a C program with debug information and using GDB to debug it interactively.



## Sample C Program (`ex1.c`)

```c
#include <stdio.h>

void greet() {
    int a = 5;
    printf("Hello Vishnew! a = %d\n", a);
}

int main() {
    greet();
    printf("Back in main.\n");
    return 0;
}
```


## ⚙️ Step 1: Compile the Code with Debug Symbols

Use the `-g` option to include debug information in the executable:

```bash
gcc -g ex1.c -o output
```

This creates an executable named `output` with debug information that GDB can read.


## Step 2: Start GDB

Launch GDB with the compiled binary:

```bash
gdb ./output
```

You’ll now be inside the GDB shell, shown as `(gdb)`.


## Step 3: Set Breakpoints

Breakpoints pause execution at specific lines or functions.

```gdb
break main        # Pause at the beginning of main()
break greet       # Pause at the beginning of greet()
```


## Step 4: Run the Program

To start the program inside GDB:

```gdb
run
```

If breakpoints are set, execution will stop at the first one hit.



## Step 5: Step Through Code

Control execution line by line:

```gdb
next              # Execute the current line and move to the next (skip into functions)
step              # Step into function calls (e.g., go inside greet())
finish            # Run until the current function ends and return to caller
```



## Step 6: View Source Code

Show the source code in chunks:

```gdb
list              # Display source code around the current line
```

Run `list` again to see more lines below.

---

## Step 7: Inspect Variables

You can print variable values while debugging:

```gdb
print a           # Shows value of variable a
print result      # Shows value of variable result
```


## Step 8: Quit GDB

Exit the debugger:

```gdb
quit
```

If GDB asks:

```
A debugging session is active. Quit anyway? (y or n)
```

Type:

```
y
```

## Full Command Reference

```bash
gcc -g ex1.c -o output   # Step 1: Compile with debug symbols
gdb ./output             # Step 2: Launch GDB
(gdb) break main         # Step 3: Breakpoint at main
(gdb) break greet        # Step 3: Breakpoint at greet
(gdb) run                # Step 4: Run the program
(gdb) next               # Step 5: Step over a line
(gdb) step               # Step 5: Step into a function
(gdb) finish             # Step 5: Finish the current function
(gdb) list               # Step 6: Show source code
(gdb) print a            # Step 7: Inspect variable value
(gdb) quit               # Step 8: Exit GDB
```


