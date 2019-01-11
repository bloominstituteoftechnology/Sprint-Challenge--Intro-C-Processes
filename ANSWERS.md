**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
    1.) Created--> When a process is first created it is in a created state.  The process is waiting admission to the ready state.

    2.) Ready--> A ready process has been loaded into main memory and is waiting to be executed on a CPU.

    3.) Running--> A process moves into a running state when it is chosen for execution.

    4.) Blocked--> A process is blocked when it cannot continue execution without an external change in state occuring.

    5.) Terminated--> A process is terminated when its execution is complete or it is manually terminated by a user.  



**2. What is a zombie process?**
    A terminated process that still has bits of data that have not been cleaned up and are still being stored in memory.  



**3. How does a zombie process get created? How does one get destroyed?**
    A zombie process is created when a child process is terminated.  It is destroyed when the parent process runs wait() to get the exit status and other info. After Wait is called the zombie process is removed from memory



**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
    Compiled language programs are executed more quickly because they are translated before the program runs as opposed to interpreted languages that are translated when the program runs.   
