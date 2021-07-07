**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

(start/created). When a process is first created, it occupies the "created" or "new" state. In this state, the process awaits admission to the "ready" state.

(ready/). A "ready" state is when process has been loaded into main memory and is awaiting execution on a CPU (to be context switched onto the CPU by the dispatcher, or short-term scheduler).  

(running). A process moves into the running state when it is chosen for execution. The process's instructions are executed by one of the CPUs (or cores) of the system.

(waiting). Waiting is when a process goes into a waiting or standby state.

(terminating). OS terminates the process once it completes its instructions, once in terminating or Exit state the process waits to be removed from memory, as it no longer needs to be taking up computer resources.

**2. What is a zombie process?**

a (zombie process) or (defunct process) is a process that has completed execution (via the exit system call) but still has an entry in the process table: it is a process in the "Terminated state".

**3. How does a zombie process get created? How does one get destroyed?**

This occurs for (child processes), where the entry is still needed to allow the (parent process) to read its child's (exit status): once the exit status is read via the (wait system call), the zombie's entry is removed from the process table and it is said to be "reaped". A child process always first becomes a zombie before being removed from the resource table. In most cases, under normal system operation zombies are immediately waited on by their parent and then reaped by the system – processes that stay zombies for a long time are generally an error and cause a (resource leak).

To remove zombies from a system, the (SIGCHLD signal) can be sent to the parent manually, using the (kill) command. If the parent process still refuses to reap the zombie, and if it would be fine to terminate the parent process, the next step can be to remove the parent process. When a process loses its parent, (init) becomes its new parent. (init) periodically executes the (wait) system call to reap any zombies with (init) as parent.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled languages usaully run faster and are more efficient then non-compiled languages. this is because once compiled, a program can be run any number of times without have to re-compiling the language unless changes are made.

A non-compiled languages relies on an interpreter to run the program, and each time it is exectued the program must be parsed, interpreted, and then executed.

Since a program cannot be compiled until errors are resolved, this way you will never be able to run a compiled language program until errors are resolved allowing the compiler to compile.