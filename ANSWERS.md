**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
- New, the beginning of creation for the process.
- Ready, the process is loaded in the main memory and "ready" to run.
- Running, the process is executed.
- Blocked or Waiting, process is standing by for input/event.
- Terminated, the process is killed/completed.


**2. What is a zombie process?**
It is a process that has completed execution (via the exit system call), but still has an entry in the process table: it is a process in the "Terminated state".


**3. How does a zombie process get created? How does one get destroyed?**
A zombie process is created if the parent isn't programmed properly and never calls wait().
To destroy a zombie process, send the SIGCHILD signal to the parent process.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
- Self-contained units that are ready for execution.
- No secondary application that the user has to keep up-to-date.
- Precompiled package can run faster than an interpreter compiling source code.
