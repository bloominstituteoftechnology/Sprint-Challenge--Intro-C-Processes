**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Sleeping: Process is waiting for another event or it is blocked.

Ready to run: Process is awake and ready to be scheduled.

Running: Process is running on CPU

Zombie: Process that is ended and needs to reaped by it's parent.

**2. What is a zombie process?**

A zombie process is one which has finished, but is not yet cleaned up.

**3. How does a zombie process get created? How does one get destroyed?**

A zombie process is created when a child process is complete, but the parent is still running. It is also created if a parent runs before the child, in which case memory leaks are created.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

A compiled language, such as C, has a faster execution speed because it doesn't need to be interpreted and parsed during each program execution. We are also given more control over memory management.
