**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

1. New state: When a process is first created and waiting 'permission' to move on to the next state.
2. Ready state: When a process has been loaded into memory and is waiting for executin.
3. Running state: When the process is running.
4. Waiting/Blocked state:  When the process is waiting for a resource.
5. Stopped state: When the process has been stopped by a command.


**2. What is a zombie process?**
1. A zombie process is a completed process that hasn't been removed from the process table.


**3. How does a zombie process get created? How does one get destroyed?**
1. To create one, execute a process, use the `exit` system call but dont remove it from the process table.
2. To remove the zombie process use the `wait` system call.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Programs written in a compiled language are more reliable and often faster as there is no runtime translation.