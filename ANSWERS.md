**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created
- The process is initialized and awaits admission to the ready state from the system scheduler.

Ready
- The process has been loaded into the main memory and is awaiting execution on a CPU. It may be kept in a "ready queue" until it can be executed by the CPU.

Running
- The process begins execution, and its instructions are processed by the CPU, either in kernel mode or user mode.

Blocked 
- A process may become blocked if it cannot carry on its instructions until an external event occurs. An example may be awaiting a user input such as Y or N.

Terminated
- A process is terminated by either completing its execution or being explicitly killed. It will remain in the terminated state until its parent process reads its exit status and removes it from the processes table.


**2. What is a zombie process?**
A zombie process is a process that has completed its execution (via exit()), but still has an entry in the process table. It remains in this terminated state until its parent process can check its wait() return value, see that is is terminated, and remove it from the process table (i.e. "reaping").


**3. How does a zombie process get created? How does one get destroyed?**
Zombie processes can occur when a process is terminated, but its parent process is delayed in assessing its exit status. The zombie must remain in the processes table until the parent process can read the exit status via the wait() system call. It is important that the zombie remains so that the parent process can determine its exit status and react accordingly before "reaping" the zombie and removing it from the process table.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled languages give us much greater specificity in terms of memory allocation and process scheduling. This is of great importance when dealing with embedded systems that may have minimal computational power and memory available. Additionally, compilation allows us to ensure that our programs are sound, and that they will be suited for the environment they will be run within.
