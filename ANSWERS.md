**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
new - start
ready - process is loaded
running - process executed
blocked/waiting - standing by
terminated - process finished

**2. What is a zombie process?**

a process that has completed execution but still has an entry in the process table

**3. How does a zombie process get created? How does one get destroyed?**
created by never calling wait()
destroyed by sending SIGCHILD signial to the parent process

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

compiled code runs much faster
self-contained
no secondary resources needed to run / keep up to date
