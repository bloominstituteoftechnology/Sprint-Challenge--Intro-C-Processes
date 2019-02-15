**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
New - When the process is being created
Ready - The process is waiting to be used
Running - The process is being executed
Waiting - The process is waiting for something else to occur
Terminated - The process is finished running

**2. What is a zombie process?**
Its a process that still exists after it has finished running

**3. How does a zombie process get created? How does one get destroyed?**
If the parent process doesnt read the exit code of the child process it will exist as a zombie process, because it hasnt been removed from the process table, best way to destroy (reap) a zombie process, is to call wait() on the parent function.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Working in a non-compiled language like C, gives us the ultimate say in how our code is executed, mainly in how memory is allocated and used.
