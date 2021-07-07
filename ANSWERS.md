**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Running - The process is either running or it is ready to run
Waiting - The process is waiting for an eevnt or for a resource
Stopped - The process has been stopped, usually by receiving a signal
Zombie - The process is dead but have not been removed from the process table



**2. What is a zombie process?**
In the case that the child finishes its process first and the parent may need information about the childs exit status, the parent calls wait() which places the child in a Zombie state.


**3. How does a zombie process get created? How does one get destroyed?**
A zombie state is created when the process creates a fork system call. The way a zombie process gets destroyed is when the parent process terminates. 



**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

The benefit of running a Compiled language is the lower overhead of execution cost. Users only need to compile code once and thereafter the code only needs to be loaded and executed. In other words, we only need to compile the code once, while other types of languages like interpreted languages must interpret the program each time it is executed, therefore requiring a higher overhead cost.