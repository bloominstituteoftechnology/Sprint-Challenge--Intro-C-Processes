**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
All processes start out in the created state, which is just the state of being created. Then the process is moved to a ready state and is waiting execution via the cpu along with any other processes in the queue. Then the process’s state becomes a running state and the process is currently being executed.  


**2. What is a zombie process?**
A zombie process is simply just a process that continues to exist despite having already finished its execution.


**3. How does a zombie process get created? How does one get destroyed?**
A zombie process is created when the parent process doesn’t know to clean up it’s child process. This can be resolved by using the wait() system call


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

The benefit is that processes in a compiled language are generally going to executing faster.