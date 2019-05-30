**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Running, uninterruptable, interruptable (waiting for something else to finish), zombie (terminated but not reaped by the parent process), stopped (a control signal has stopped it)


**2. What is a zombie process?**
A zombie process has been terminated, but the process entry is still needed so the parent can read the child's exit status.


**3. How does a zombie process get created? How does one get destroyed?**
A zombie process is made when the entry is needed to allow the parent process to read its exit status, and it is destroyed when its parent is killed or its exit status is read through the wait() call.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled code runs more quickly, this is one of the reasons C is usually faster than Python.
