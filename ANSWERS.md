**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

New (Create) – In this step, process is about to be created but not yet created, it is the program which is present in secondary memory that will be picked up by OS to create the process.

Ready – New -> Ready to run. After creation of a process, the process enters the ready state i.e. the process is loaded into the main memory. The process here is ready to run and is waiting to get the CPU time for its execution. Processes that are ready for execution by the CPU are maintained in a queue for ready processes.

Run – The process is chosen by CPU for execution and the instructions within the process are executed by any one of the available CPU cores.

Blocked or wait – Whenever the process requests access to I/O or needs an input from user or needs access to a critical region(the lock for which is already acquired) it enters the blocked or wait state. The process continues to wait in the main memory and does not require CPU. Once the I/O operation is completed the process goes to ready state.

Terminated or completed – Process is killed as well as PCB is deleted.

Suspend ready – Process that were initially in ready state but were swapped out of main memory(refer Virtual Memory topic) and placed onto external storage by scheduler are said to be in suspend ready state. The process will transition back to ready state whenever the process is again brought onto the main memory.

Suspend wait or suspend blocked – Similar to suspend ready but uses the process which was performing I/O operation and lack of main memory caused them to move to secondary memory.
When work is finished it may go to suspend ready.


**2. What is a zombie process?**

Is a process that has completed execution but still has an entry in the process table: Which means a child process has not actually executed but the overall program was terminated.

**3. How does a zombie process get created? How does one get destroyed?**
It gets created by improper process execution order. They are destroyed via the waiting on the child process to terminated before processing the parent, this wait method reaps the child once the child is terminated. 

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Generally compiled code runs faster than interpreted code.
