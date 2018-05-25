1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.
New- the process is being created
Ready- the process has all the resources but the CPU is not working on the process
Running- The CPU is working on the process
Waiting- The process can't run because it is waiting  for a resource to become availiable or an event to occur.
Terminated- The process has completed

2. What is a zombie process? How does one get created? How does one get destroyed?
Zombie process is when the process has completed but still has an entry in the process table. The parent still needs to read the exit status of the child. Using the wait system call, the child's exit code is read. Then the zombie's entry is removed or reaped from the process table.  The child process always first becomes a zombie before being removed from the process table. Under regular operations the zombies are immediately waited on by the parent then reaped.

3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

Compiled languages are more efficent, translation occurs just once and afterwards it only needs to be loaded and executed.

