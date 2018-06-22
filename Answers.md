1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.
There are 5 system states in unix (or linux) systems:
#1 Running (R) #2 Interruptible sleep (S), which is in a waiting state to complete #3 Uninterruptible sleep (D), which is a process that cannot be killed, #4 Zombie (Z), they're terminated processes that are not properly cleaned up (memory), #5 Stopped (T), a process that has been suspended (stopped).


2. What is a zombie process? How does one get created? How does one get destroyed?
The init (root process that starts all other processeses) cleans up after zombie processes. If the zombie process is a child of a parent process, the parent process that holds that zombie process must be killed. So, if the zombie is a child process, then killing the parent will eliminate the zombie child process. If the init is not cleaning up properly, then it's a bug with the init process.

3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

Compiled languages take less time to program with(less time to develop), as it's ready to run when the program is written, no need to compile. The downside to compiled languages is that the execution takes longer, because the program is translated into machine code for every execution. So, on the long run, compiled languages are more efficient programs, but they take much longer development time. So, there are benefits to compiled languages as it allows advanced features to be added very quickly in comparison to compiled languages (development time is much faster), although the execution will be less efficient.

