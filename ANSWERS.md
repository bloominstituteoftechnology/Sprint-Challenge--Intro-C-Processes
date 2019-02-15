**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
The main states are running, asleep, zombie or stopped. A process starts running, goes to sleep waiting for an event to complete, becomes a zombie process then becomes reaped by it's parent which stops it. 


**2. What is a zombie process?**
It is a process that has completed execution but is still in the process table.


**3. How does a zombie process get created? How does one get destroyed?**
A zombie process gets created when a parent doesn't wait on its child. It can be destroyed by calling wait() so the parent can read the child's exit status which then destroys the process.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled language programs get compiled into machone code which allows for more efficient code and memory management. Compiled languages are only translated to machine language one time which is when they are compiled. After it is compiled it just needs to be loaded and executed. Non-compiled languages need to be parsed, interpreted, and executed every time they run a program. 
