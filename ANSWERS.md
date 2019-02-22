**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Running: the process is active and has the resources it needs to perform operations.

Interruptible sleep: the process is waiting for a cue from another process or for a specific time to start running.

Uninterruptible sleep: the process is busy performing a system call and needs to complete that first before it can handle subsequent requests.

Stopped: the process has halted operations and freed resources it was using previously.

Zombie



**2. What is a zombie process?**
Zombie process is a child that is leftover from a dead parent process and hasn't been cleaned up correctly/persists in memory after the parent process has been removed. 


**3. How does a zombie process get created? How does one get destroyed?**
A zombie process is created when a parent process doesn't execute the 
wait() call in order to get information back from the child process to remove it from memory. Zombie processes can't be killed directly, but can be killed by sending the SIGCHILD command to the parent process manually. 


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compilers make an effort to optimize code where they can which can result in faster performance.
Compiler can catch more bugs before the code needs to be executed at run-time. 

