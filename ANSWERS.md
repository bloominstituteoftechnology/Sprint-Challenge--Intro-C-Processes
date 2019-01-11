**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
 Stopped - The process has been stopped.
 Running - The process is ready to run or is running already.
 Waiting - The process is waiting for an event to occur or for a resource
 Zombie - The process is dead, but has not been removed from the process table.
Uninterrupted sleep - Processes in a "D" or uninterruptible sleep state are usually waiting on I/O. The ps command shows a "D" on processes in an uninterruptible sleep state.
**2. What is a zombie process?**
A zombie process is a process in its terminated state. This usually happens in a program that has parent-child functions. After a child function has finished execution, it sends an exit status to its parent function. Until the parent function receives and acknowledges the message, the child function remains in a “zombie” state, meaning it has executed but not exited.


**3. How does a zombie process get created? How does one get destroyed?**
If the parent function does not receive and acknowledge the exit status message after finished execution.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

 Compiled languages are faster due to the compilation step before run time, also
compiled languages tend to be lower-level which are more difficult, generally speaking.