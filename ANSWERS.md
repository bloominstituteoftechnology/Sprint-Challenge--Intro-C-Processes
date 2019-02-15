**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Process states:
New, process is being created
Ready, process is ready to be assigned a processor
Running, process is being executed
Waiting, process is waiting for some event to occur
Terminated, process has been killed

**2. What is a zombie process?**
A process that has finished execution yet its parent process has not properly called the wait commant to remove the process from the process table.

**3. How does a zombie process get created? How does one get destroyed?**
A zombie process gets created when it finishes execution but its parent process does not handle it properly. The process is no longer alive but its record has not been removed from the process table. The parent process needs to call the wait command to properly destroy it.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Some of the benefits of working in a compiled language are that compiled languages are faster to run and only compile if there are no syntax errors. This results in more efficient code that reduces any bugs introduced by syntax error because the code would not compile in the case that there were any bugs.
