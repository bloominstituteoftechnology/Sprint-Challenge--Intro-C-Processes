**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
    New: initial state. Ready: on standby to be allocated to a processor.
    Waiting: waiting for resources to continue running. Running: being executed. Terminated: done executing.


**2. What is a zombie process?**
    A zombie process is one that is still running even though it has been told to terminate. 


**3. How does a zombie process get created? How does one get destroyed?**
    These are created whent he parent doesnt read the exit call from the child. but, the Parent process can end them.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
     You can create instructions that are easy for the machine to read.
     More perfromant.
     Programmer has more control over the CPU and memory.
