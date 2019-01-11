**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Running : ready to run or currently running;
Waiting : in a wait status until queued by a specific event or for a resource;
Stopped : no longer running after receiving signal;
Zombie : Dead process but not removed from the process table;


**2. What is a zombie process?**
A process which is killed but still shows its entry in the process status or the process table.


**3. How does a zombie process get created? How does one get destroyed?**
You must either kill the parent or restart the system.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled languages gives you a compiled binary which is executed faster and ae optimized for specific hardware. Since compile code does not have to be interpreted at the time at runtime and so run faster.

However, non-compiled languages are generally easier to lean and can perform complex operations in only a few steps.
