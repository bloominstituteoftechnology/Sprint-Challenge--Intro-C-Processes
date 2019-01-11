**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Created: initial state when a process is first created.
Ready: has been loaded into main memory and is waiting to be assigned to a processor.
Running: process has been assigned to a processor, process's instructions are executed by the processor.
Waiting: waiting for external change in state or event occurring to proceed.
Terminated: process finishes its execution or process terminated by the operating system,
it remains in the process table as a zombie process and waits to be removed from main memory.

**2. What is a zombie process?**

A zombie process is a process in its terminated state.
The process has completed execution but still has an entry in the process table.

**3. How does a zombie process get created? How does one get destroyed?**

When a process finishes execution, it will have an exit status to report to its parent process. Because of this last little bit of information, the process will remain in the operating system’s process table as a zombie process, indicating that it is not to be scheduled for further execution, but that it cannot be completely removed (and its process ID cannot be reused) until it has been determined that the exit status is no longer needed.

When a child exits, the parent process will receive a SIGCHLD signal to indicate that one of its children has finished executing; the parent process will typically call the wait() system call at this point. That call will provide the parent with the child’s exit status, and will cause the child to be reaped, or removed from the process table.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Faster performance by directly using the native code of the target machine.
Opportunity to apply optimisations during the compile stage.