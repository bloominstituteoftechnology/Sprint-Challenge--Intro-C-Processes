**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- Start - Initial state.
- Ready - Process waiting to be assigned to a processor.
- Running - Executes instructions.
- Waiting - Wait for a resource (input, process, file).
- Exit - Once finished it's terminated.

**2. What is a zombie process?**

An executed child process, but the entry is still needed for the parent process.

**3. How does a zombie process get created? How does one get destroyed?**

It's a child process that has an entry that is needed for the parent process to run. Parent can read the child's exit status by executing the `wait()` system call then the zombie process is reaped.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

A compiled language is generally faster due to it compiling before run time.
Compiled languages tend to be lower level which is closer to machine code increasing efficiency and allow more control over processes and memory.
