**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

Created/New - the process is created and is waiting for the go ahead
Ready/Waiting - the process is ready and waiting for execution
Running - the process is currenyly running or is ready to run
Blocked/Stopped - the process has been stopped by a signal
Terminated/Zombie - the process (child) is finished running and waiting for parent to read its exit status

**2. What is a zombie process?**

When the child is finished running, but the parent hasn't finished reading the child's exit status via the wait command.

**3. How does a zombie process get created? How does one get destroyed?**

When the child is finished running, but the parent is still alive. Calling wait in the parent will remove the child zombie.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

The benefits of working in a compiled language includes separating the run step from the interpretation step, and therefore a faster runtime. By spending more time compiling code when it's being written allows certain bugs to be caught ahead of time no matter where they are in the file (i.e. a specific region of code does not need to run in order to know that a function was used incorrectly). Because the compiler can take more time figuring out the best way to transform the code we wrote into a form that is optimal for a computer, it can run much faster.