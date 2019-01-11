**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
a NEW process has just been created and is in its initial state. A READY process is one that is waiting to be allocated to a processor by the OS. A process can be in the WAITING state, where the process needs something like an I/O to keep it running. A RUNNING process is currently being executed by the OS. A TERMINATED process is one that is finished executing or stopped by the OS.


**2. What is a zombie process?**
A zombie process is one that has been terminated but remains active.


**3. How does a zombie process get created? How does one get destroyed?**
Child processes are the most common zombie processes. After a child has finished executing and sends an exit status to its parent, it remains in zombie state until the parent receives the exit.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled code has already been checked for errors and usually executes faster than interpreted code. 
