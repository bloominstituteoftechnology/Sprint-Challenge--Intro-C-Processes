**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Running: currently running or ready to run (has resources and is being served by cpu or will be served as soon as cpu is free)
Sleeping: awaiting resources. this can be interruptible (waiting for a specific event or condition) or uninterruptible (waiting on a timeout to expire)
Stopped: having entered exit status, process gives up all its resources but still has an entry on the process table
Zombie: has sent exit signal to parent but has yet to be released from the process table

**2. What is a zombie process?**
A zombie process is a child process that has finished executing but has yet to be reaped by its parent.

**3. How does a zombie process get created? How does one get destroyed?**
It gets created when a process ends via an `exit` call. It gets destroyed when the parent executes the `wait` system call.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
