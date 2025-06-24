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
# GDB Debugging – Inspecting & Watching Variables

This guide focuses on **pausing program execution**, **inspecting variable values**, **watching them live**, and even **modifying them at runtime** using GDB.

---

## Sample C Program (`ch4.c`)

```c
#include <stdio.h>

int main() {
    int i;
    for (i = 0; i < 3; i++) {
        printf("%d\n", i);
    }
    return 0;
}
```

---

## Step 1: Set a Breakpoint

Tell GDB to pause at the beginning of `main()`:

```gdb
break main
```

---

## Step 2: Run the Program

Start executing the program under GDB:

```gdb
run
```

GDB will pause at the breakpoint set on `main()`.

---

## Step 3: Step Through Code

Step through each line in the program to watch the flow:

```gdb
next              # Execute the current line and move to the next
list              # Display source code around current location
```

Use `next` repeatedly to go through the loop line by line.

---

## Step 4: Inspect & Modify Variables

### Print Variable Value

```gdb
print i           # Shows the current value of i
```

### Watch a Variable Live

```gdb
display i         # Automatically print i every time GDB stops
```

### Stop Watching

```gdb
undisplay 1       # Removes the first display (use `info display` to list IDs)
```

### Modify Variable Value

```gdb
set var i = 100   # Changes the value of i to 100 during execution
```

---

## Step 5: Exit GDB

Quit the GDB session:

```gdb
quit
```

If prompted:

```
A debugging session is active. Quit anyway? (y or n)
```

Type:

```gdb
y
```

---

## Summary

| Feature              | Command                        | Description                                    |
|----------------------|--------------------------------|------------------------------------------------|
| Breakpoint at main   | `break main`                   | Stop execution at the beginning of `main()`   |
| Run program          | `run`                          | Starts the program inside GDB                 |
| Step line by line    | `next`                         | Execute one line at a time                    |
| View code            | `list`                         | Shows nearby lines of code                    |
| Print variable       | `print i`                      | Prints value of `i`                           |
| Live watch variable  | `display i`                    | Shows value of `i` automatically              |
| Stop live watch      | `undisplay 1`                  | Stops displaying watched variable             |
| Modify variable      | `set var i = 100`              | Changes variable `i` to 100 on-the-fly        |
| Exit GDB             | `quit`                         | Quit the debugger                             |

---

# GDB Debugging – Function Breakpoints

This chapter teaches how to set, manage, and conditionally trigger breakpoints, especially inside functions like `check()`.

---

## Sample C Program (`chapter5.c`)

```c
#include <stdio.h>

void check(int x) {
    if (x > 10)
        printf("Large: %d\n", x);
    else
        printf("Small: %d\n", x);
}

int main() {
    for (int i = 0; i < 5; i++) {
        check(i * 5);  // Values: 0, 5, 10, 15, 20
    }
    return 0;
}
```

---

## Step 3: Set a Function Breakpoint

```gdb
break check         # Stops at the beginning of check()
```

---

## Step 4: Run the Program

```gdb
run
```

When `check()` is called during execution, GDB will pause at the function entry.

---

## Step 5: Manage Breakpoints

View all breakpoints:

```gdb
info breakpoints
```

Delete a breakpoint:

```gdb
delete 1
```

Temporarily disable a breakpoint:

```gdb
disable 2
```

Re-enable a disabled breakpoint:

```gdb
enable 2
```

---

## Step 6: Conditional Breakpoints

Break only when a condition is true:

```gdb
break check if x == 15
```

Break at a specific line in the file:

```gdb
break chapter5.c:10
```

---

## Step 7: Exit GDB

```gdb
quit
```

---

## Summary Table

| Action                      | Command                         |
|-----------------------------|----------------------------------|
| Break at function           | `break check`                   |
| Run program                 | `run`                           |
| View breakpoints            | `info breakpoints`              |
| Delete breakpoint           | `delete 1`                      |
| Disable breakpoint          | `disable 2`                     |
| Enable breakpoint           | `enable 2`                      |
| Conditional breakpoint      | `break check if x == 15`        |
| Break at specific line      | `break chapter5.c:10`           |
| Exit GDB                    | `quit`                          |

---

# GDB Debugging – Conditional Breakpoints

This chapter shows how to stop program execution only when specific conditions are met during runtime.

---

## Sample C Program (`chapter6.c`)

```c
#include <stdio.h>

void check(int x) {
    if (x > 10)
        printf("Large: %d\n", x);
    else
        printf("Small: %d\n", x);
}

int main() {
    for (int i = 0; i < 5; i++) {
        check(i * 5);  // Values: 0, 5, 10, 15, 20
    }
    return 0;
}
```

---

## Step 3: Set an Initial Breakpoint

Start by breaking on the function:

```gdb
break check
```

---

## Step 4: Run the Program

```gdb
run
```

GDB stops at the first call to `check()`.

---

## Step 5: Delete and Replace Breakpoint

Delete the old unconditional one:

```gdb
delete 1
```

Set a conditional breakpoint:

```gdb
break check if x == 15
```

This will stop only when `x` is exactly 15.

---

## Step 6: Run Again

```gdb
run
```

GDB restarts the program and stops at the new conditional breakpoint when the condition is true.

---

## Step 7: Inspect the Variable

```gdb
print x
```

You can verify that `x == 15` at this point.

---

## Step 8: Exit GDB

```gdb
quit
```

---

## Summary Table

| Action                      | Command                         |
|-----------------------------|----------------------------------|
| Break at function           | `break check`                   |
| Run program                 | `run`                           |
| Delete a breakpoint         | `delete 1`                      |
| Conditional breakpoint      | `break check if x == 15`        |
| Print variable              | `print x`                       |
| Exit GDB                    | `quit`                          |

---

# GDB Debugging – Chapter 7 & 8: Restarting & Breakpoint Automation

This section covers two advanced but essential features of GDB:

- Restarting a program from the beginning
- Automatically running custom commands when a breakpoint is hit

---

## Sample C Program (`chapter8.c`)

```c
#include <stdio.h>

void check(int x) {
    if (x > 10)
        printf("Large: %d\n", x);
    else
        printf("Small: %d\n", x);
}

int main() {
    for (int i = 0; i < 5; i++) {
        check(i * 5);  // Values: 0, 5, 10, 15, 20
    }
    return 0;
}
```

---

## Step 3: Set a Function Breakpoint

```gdb
break check
```

---

## Step 4: Run the Program

```gdb
run
```

GDB will stop at the first call to `check()`.

---

## Step 5: Restart the Program

If you try to run again:

```gdb
run
```

GDB will respond with:

```
The program being debugged has been started already.
Start it from the beginning? (y or n)
```

Type:

```gdb
y
```

This restarts the entire program from the beginning.

---

## Step 6: Automate Commands at Breakpoint

You can tell GDB to automatically perform actions (like printing variables) every time a breakpoint is hit.

```gdb
commands 1
print x
continue
end
```

This setup does the following when breakpoint 1 is hit:
- Prints the value of `x`
- Continues execution automatically

---

## Step 7: Run Again to See Automation

```gdb
run
```

You will now see GDB automatically stop at every `check()` call, print `x`, and continue until the program finishes.

---

## Step 8: Exit GDB

```gdb
quit
```

---

## Sample Output

```
Breakpoint 1, check (x=0)
$1 = 0
Breakpoint 1, check (x=5)
$2 = 5
Breakpoint 1, check (x=10)
$3 = 10
Breakpoint 1, check (x=15)
$4 = 15
Breakpoint 1, check (x=20)
$5 = 20
[Inferior 1 (process) exited normally]
```

---

## Summary Table

| Action                                | Command                      |
|---------------------------------------|-------------------------------|
| Break at function                     | `break check`                |
| Run program                           | `run`                        |
| Restart program (when prompted)       | Type `y`                     |
| Add commands to breakpoint            | `commands <num>`             |
| Print variable inside commands        | `print x`                    |
| Auto-continue after command           | `continue`                   |
| End commands block                    | `end`                        |
| Exit GDB                              | `quit`                       |

---
# Chapter 9: Call Stack and Backtrace

This chapter explains how to trace the chain of function calls that led to a specific point in execution using the GDB call stack. It helps you understand the path taken through your code and the values passed between functions.

---

## Sample Program: 

```c
#include <stdio.h>

void third(int z) {
    printf("Inside third. z = %d\n", z);
}

void second(int y) {
    third(y + 5);
}

void first(int x) {
    second(x + 10);
}

int main() {
    first(3);
    return 0;
}
```

---

## Step-by-Step GDB Commands

### Compile with Debug Info

```bash
gcc -g chapter9.c -o ch9
```

### Launch GDB

```bash
gdb ./ch9
```

### Set a Breakpoint at the Deepest Function

```gdb
break third
```

### Run the Program

```gdb
run
```

Execution stops at the start of the `third()` function.

---

## Inspect the Call Stack

### View the Stack Trace

```gdb
backtrace
```

Shows how the current function was reached. Example output:

```
#0  third (z=18) at chapter9.c:4
#1  second (y=13) at chapter9.c:8
#2  first (x=3) at chapter9.c:12
#3  main () at chapter9.c:16
```

### View Function Arguments

```gdb
info args
```

Displays arguments of the current function (e.g., `z = 18`).

### View Local Variables

```gdb
info locals
```

Shows all local variables in the current stack frame.

---

## Navigating the Stack Frames

### Move Up to Caller Frame

```gdb
up
```

Moves one frame up (to caller function). You can then inspect its arguments:

```gdb
info args
```

### Move Down to Callee Frame

```gdb
down
```

Moves back down into the function that was being executed.

### Jump Directly to a Specific Frame

```gdb
frame 2
```

Moves to frame index 2.

---

## Summary of Commands

| Command           | Description                                  |
|-------------------|----------------------------------------------|
| `backtrace`       | Show all functions in the current call stack |
| `info args`       | Show function arguments in current frame     |
| `info locals`     | Show local variables in current frame        |
| `up`              | Move to the calling function’s frame         |
| `down`            | Move to the called function’s frame          |
| `frame <n>`       | Jump directly to frame number `n`            |

---
# GDB Debugging – Chapter 10: Inspecting Memory

This chapter covers how to examine raw memory in GDB using the `x` command. You’ll be able to inspect arrays, pointers, strings, and bytes directly using addresses.

---

## Sample Program: `chapter10.c`

```c
#include <stdio.h>

int main() {
    int nums[5] = {10, 20, 30, 40, 50};
    char *msg = "Hello Vishnew!";
    return 0;
}
```

---

## Step-by-Step Instructions

### Compile with Debug Info

```bash
gcc -g chapter10.c -o ch10
```

### Start GDB and Set Breakpoint

```bash
gdb ./ch10
(gdb) break main
(gdb) run
```

---

## Printing Addresses of Variables

```gdb
print nums
print &nums[0]
print msg
```

Expected output:

```
$1 = (int *) 0x7fffffffe4d0
$2 = (char *) 0x555555554008 "Hello Vishnew!"
```

---

## Using `x` to Examine Memory

**Syntax:**

```gdb
x/NFMT ADDRESS
```

- **N** = number of items
- **F** = format (`x`, `d`, `u`, `s`, `c`, etc.)
- **M** = size (`b`, `h`, `w`, `g`) → byte, halfword, word, giant

---

### Inspect Integer Array

```gdb
x/5d nums       # View 5 integers in decimal
x/5x nums       # View 5 integers in hexadecimal
```

### Inspect String

```gdb
x/s msg         # View string pointed to by msg
x/16xb msg      # View 16 bytes at msg in hex format
```

---

## Pointer Arithmetic Examples

```gdb
print *(nums + 3)    # nums[3] → 40
x/d nums+3           # Alternative: view one int
```

---

## Summary Table

| Command             | Description                                         |
|---------------------|-----------------------------------------------------|
| `print nums`        | Show base address of the array                      |
| `x/5d nums`         | Show 5 integers in decimal                          |
| `x/5x nums`         | Show 5 integers in hexadecimal                      |
| `print msg`         | Show address and value of string                    |
| `x/s msg`           | Display string at the address                       |
| `x/16xb msg`        | Display 16 bytes at the address in hex              |
| `print *(nums + 3)` | Show value at index 3 (i.e., nums[3])               |
| `x/d nums+3`        | Alternate way to view a single int at offset 3      |

---

This chapter helps you explore raw memory deeply, even when variables are not directly visible or in scope.

