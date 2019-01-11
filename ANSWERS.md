**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

a. Start: This is the initial state when a procress is created.

b. Ready: The process is waiting to be assigned to a processor and allocate them by operating system so they can start running.

c. Running: The processor carry out its instructions.

d. Waiting: The process moves to waiting state if it needs to wait for user input or for a file to be available.

e. Terminated or Exit: When the process finishes its carry out or the operating system stopped it, the processor moved to the terminated state for it to be removed from main memory.

**2. What is a zombie process?**

Zombies processors are leftover bits of deaf processors that are not cleaned up properly.

**3. How does a zombie process get created? How does one get destroyed?**

When a procress dies on Linux and it not removed from memory immediately, the process' status becomes a zombie. The process' parent gets a notification that it's child's process has died with SIGCHLD signal. To destroy zombie process, is by sending the SIGCHLD signal to the parent's process. The parent will execute the wait() system call and clean up all zombie children. 

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Benefit of using compiled language is that it has faster performance.
Benefit of using non-compiled language is that is it eaiser to implement and can be convenient for dynamic languages.