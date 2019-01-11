**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
- prioritize execution of processes on CPU
- assign amount of execution time on CPU for each process
- storing metadata about each executing process in Process Control Block
- allocates some memory in the RAM in order to keep track of that program’s state


**2. What is a zombie process?**
- a zombie process a process that has completed execution but still has an entry in the process table.  


**3. How does a zombie process get created? How does one get destroyed?**
- Zombie process typically happens when a child process is completed but the parent process has not read the child process' exit status via wait system call.  Once parent process calls a wait, child process then is removed from process table and gets destroyed.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled language requires translation of source code into machine code by a compiler, whereas a non-compiled language requires no pre-run time translation.  Compiled languages need not worry about machine code and therefore are more readable and user-friendly, whereas non-compiled languages are more performant due to lack of need for translating source code.