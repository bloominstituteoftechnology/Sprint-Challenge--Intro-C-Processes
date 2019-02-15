**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
1. started/created = The initial state of a process where it has been created but isn't ready to run

2. ready - the process has reached a point where it is ready to run and is waiting to be assigned  aprocessor by the operating system
3. running - the processor is executing the process' instructions
4. waiting - the process waits for user input or a resource to continue
5. terminated - the process ends, it either finished its instructions or the operating system terminated it.
6. zombie - when the process gets terminated but hasn't been removed from the process table


**2. What is a zombie process?**
a process that has been terminated but still has an entry in the process table.


**3. How does a zombie process get created? How does one get destroyed?**
a zombie process is creted when its parents fail to call the wait system call to read its exit status. It gets destroyed when its parent process does call wait to read its exit status and removes its entry from the process table.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

compiled langauge programs get compiled into machine code directly from execution. This allows for efficient code and memory management.  Interpreted languages need to be parsed, interpreted, and executed every time they run aa program. Compiled languages is only translated into machine language one time when the program is compiled. After that, it only needs to be loaded and executed.