**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created - process is created and awaits admission to ready
Ready - process is loaded into memory and awaits execution
Running - process is executed by on of CPUs cores
Blocked - process cannot carry on without external instruction
Terminated - process is deemed either completed or killed and waits in the process table as a zombie process until called to exit

**2. What is a zombie process?**
A zombie process is a process that has completed its execution or has been killed and is awaiting exit status within the process table.

**3. How does a zombie process get created? How does one get destroyed?**
A zombie process gets created when a process has completed execution but still has an entry in the process table. A zombie process gets destroyed when the parent process calls an exit status.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compliled languages are much faster than interpreted langauges due to the fact interpreted languages have to interpret then compile every step of the code while compiled languages are simply compiled then ran as an executable. Using a complied langauge allows the developer to experience a more personal understanding of how machines work.
