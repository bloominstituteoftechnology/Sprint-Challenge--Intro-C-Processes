**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Running : The process is either running or it is ready to run .
Waiting : The process is waiting for an event or for a resource.
Stopped : The process has been stopped, usually by receiving a signal.
Zombie : The process is dead but has not been removed from the process table.


**2. What is a zombie process?**
Zombies are the leftover bits of dead processes that haven’t been cleaned up properly


**3. How does a zombie process get created? How does one get destroyed?**
 If the process parent fails to read the exit call from a child process, the child process which has already finished its execution and is now dead will not be removed from the processes table. To destroy a zombie, you notify the parent of the zombie process and it will execute wait() to clean up all zombie children.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

End performance because the code gets compiled into machine code which is more efficient.  
