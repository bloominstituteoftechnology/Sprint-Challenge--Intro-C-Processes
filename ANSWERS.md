**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Start is the intial state when the process is created. Ready is when the process is waiting to be assigned to a processor. Running is when the processor is executing its instructions.  Waiting is the state when a process must wait for user input or availability of a file.  Terminating is the conclusion of of its execution. 


**2. What is a zombie process?**
It is when a process has completed execution, but still has an entry in the process table. 


**3. How does a zombie process get created? How does one get destroyed?**
It is created when a process is forked and a copy of a parent process is created as a child process.  it gets destroyed when the parent process waits until the child process terminates and then the parent gets the child's exit status, thus removing it from the system.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled languages are generally faster.  Interpreted languages are generally easier to implement and understand, and since they dont need to be compiled can execute on the fly.  one of the main benefits of compiling will be finding bugs at compile time, whereas with interpreted languages bugs might be found at run time. 

