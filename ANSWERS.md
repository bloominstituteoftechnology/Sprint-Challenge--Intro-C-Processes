**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- Running: A process is currently running or is about to run.
- Waiting: A process is waiting for resources to be run on the system.
- Stopped: A process has been stopped.
- Zombie: A process that is dead but still has an entry in the process table.

**2. What is a zombie process?**

Happens when a program has been forked and the child finished before the parent gets a chance to read the child's exit status. As a result the kernel will keep information about that child in its process table and it thus exists as a zombie. 

**3. How does a zombie process get created? How does one get destroyed?**

See above. When the exit status is read via the wait system call then the zombie will get removed.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Performance: compiled languages tend to compile programs into native code faster since the translation process of non-compiled languages incurs overhead.

More granular control: Low-level languages allow programmers more fine-grained control over the CPU and memory. This allows to gear resources towards a specific use case (e.g. graphics rendering)


