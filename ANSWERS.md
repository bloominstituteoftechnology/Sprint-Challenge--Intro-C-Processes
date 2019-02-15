**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Created = When a process if first created, it waits to get into the ready state. 

Ready = The process has been loaded into memory and is awaiting execution on a CPU

Running = A process is in the running state when it gets chosen for execution. It's instructions are executed by the CPU

Terminated = A process is terminated when it is completed its execution or is explicity being killed.


**2. What is a zombie process?**
A process that has completed execution via the exit system call, it is in the Terminated state but it still has entry to the process table. This happens for child processes where the entry is still needed to allow the parent process to read its exit code.


**3. How does a zombie process get created? How does one get destroyed?**
A zombie process gets created when there is a child process that completes execution via the exit system call, it gets destroyed once the parent process reads its exit code via the wait system call and it is removed from the process table.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**


Errors can be caught at compile time, it takes less memory and thhey are faster than those that need to be translated into machince code at run time. 