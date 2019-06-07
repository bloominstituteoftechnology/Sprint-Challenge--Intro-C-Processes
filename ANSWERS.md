**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- Running: Process is either running or ready to run
- Interruptible: a blocked state of a process and waiting for an event or signal from another process
- Zombie: Process terminated, but information is still there in the process table.
- Stopped: Process is stopped or halted and can be restarted by some other process
- Uninterruptible: A blocked state. Process waits for a hardware condition and cannot handle any signal

**2. What is a zombie process?**

A zombie process is one that has completed execution but still has an entry in the process table.


**3. How does a zombie process get created? How does one get destroyed?**

A zombie process is created when a progam has been forked and a child program has finished before the parent and then the parent will need to read that childs exit code. Because the parent needs access to this exit code the child programs info is still listed in the processes table. Once the parent reads the exit code after the wait call the process will be removed from the processes table.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Some of the benifits of compiled code are faster performance because we are directly using the native code of the target machine,and we have the ability to apply powerful optimisations during the compile stage. 

