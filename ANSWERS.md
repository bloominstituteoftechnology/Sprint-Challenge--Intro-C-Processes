**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

    a. Running - The process is ready to run or is running already.
    b. Waiting - The process is waiting for an event to occur or for a resource
    c. Stopped - The process has been stopped.
    d. Zombie - The process is dead, but has not been removed from the process table.



**2. What is a zombie process?**

    a. A process that has completed execution, but still has an entry in the process table. They occur for child processes where the entry is still needed to allow the parent process to read its child's exit status via a wait() call and then the process can be reaped.



**3. How does a zombie process get created? How does one get destroyed?**

    a. They occur for child processes where the entry is still needed to allow the parent process to read its child's exit status via a wait() call and then the process can be reaped.



**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

    a. Compiled languages are must faster due to the compilation step before run time.
    b. Compiled languages tend to be lower-level which are more difficult, generally speaking.