**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Start - Process is first started
Ready - Process is waiting to be assigned to a processor
Running - Process has been assigned to a processor and the processor is executing the instructions
Waiting - Process is waiting for some form of data
Terminated - Process is finished executing or is terminated by the OS, it waits to be removed from memory.

**2. What is a zombie process?**

A process that is finished executing, but still has an entry in the process table.

**3. How does a zombie process get created? How does one get destroyed?**

If the parent process doesn't wait for the child's termination and instead executes its next task, the child's exit status won't be read by the parent. This results in the creation of a zombie process.

Terminating the parent process should destroy the zombie process.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled languages compile into machine code, while non-compiled languages are usually executed by a program which eventually compiles into machine code down the line. Compiled languages generally have faster performance due to translating to machine code more quickly.

Compilers also catch bugs by printing errors and warnings, allowing them to be fixed prior to runtime.