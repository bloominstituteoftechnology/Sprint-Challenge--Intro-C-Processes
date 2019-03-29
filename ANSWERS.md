**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Running- Process is about to run or is running
Waiting- Process is waiting for resources to run
Stopped- Process has been stopped
Zombie- Process has an entry in the process table but is dead




**2. What is a zombie process?**
When a process that has completed execution but still has an entry in the process table which it is in the terminated state. This occurs for child processes because the parent has not read the exit status of child. 



**3. How does a zombie process get created? How does one get destroyed?**
Once the parent is able to read the exit status of the child through the wait system call then the zombie is destroyed. 



**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Using compiled languages has increased performance because the compiler translates the code to machine code which is read much faster. 

Low level languages gives programmers more control over the cpu and memory. This allows to direct resources towards a specific case. 

