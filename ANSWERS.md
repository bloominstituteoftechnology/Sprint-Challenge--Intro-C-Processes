**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created - Process is created by system call.
User running - Process is running in user mode.
Kernel running - process is running in kernel mode.
Zombie - Process does not exist or is terminated.
Preempted - When process runs from kernel to user mode.
Ready to run in memory - Process has reached a state where it is ready to run in memory and is waiting for kernel to schedule it.
Redy to run, swapped - Process is ready to run but not empty main memory is present.
Sleep, swapped - Process has been swapped to secondary storage and is at a clocked state.
Asleep in memory - Process is in memory (not swapped to secondary storage) but is in a blocked state.


**2. What is a zombie process?**
A process that has ended, and it's process descriptor stays in memory. The parent process can then execute the wait() system call in order to read the ended process' exit status.


**3. How does a zombie process get created? How does one get destroyed?**
It is created when a child process is ended within a program. A SIGCHLD signal is sent to the zombie's process' parent so that wait() can be called in ordder to destroy the zombie process.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
First benefit is speed. Compiled languanges are fsater than those translated at run time, due to the overhead of the translation.
Another is that programmers have an easier time controlling the use of the CPU and memory in more detail.

