**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
    Zombie - executed, but not removed from the process table.
    Running/Runnable - A process that is running or is in queue to be run.
    Sleeping - This is an interruptable sleep that is waiting for an even to complete.
    Uninterruptable sleep - A process that can't be terminated.


**2. What is a zombie process?**

It's when a process is finished executing but is still in the process table.

**3. How does a zombie process get created? How does one get destroyed?**
A zombie process gets created when a child finishes it's process but hasn't been waited for. You can destroy them with
wait or by killing the parent so init can inherit the children and delete them.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Benefits of compiled:
- Runs faster (doesn't have to be translated)
- Already check for errors (don't need fully functional program)

Benefits of non-compiled:
- Readability
- Easier to write
- Doesn't need specific OS
- Doesn't require compiler