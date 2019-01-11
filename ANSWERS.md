**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Start - when a process is first started
Running - has been assigned to a processor and executes the process' instructions 
Stopped - received a signal, process has stopped. 
Waiting - waiting for a resource or event. 
Terminated - the process finished its execution or terminated by the os and is now waiting to be removed from the main memory. 


**2. What is a zombie process?**

A process has completed exeuction but still has an entry on the process table. 


**3. How does a zombie process get created? How does one get destroyed?**
When a process is created using fork. The parent must be terminated.



**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

A compiled language has faster execution and is optimised for the hadrware. A non-compiled language allows complex steps to completed in fewer steps and only requires minimum programming language to learn. 