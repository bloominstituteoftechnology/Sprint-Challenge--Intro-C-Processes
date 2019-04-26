**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

    A: Create, Ready, Running, Wating, and Terminated.
    
    Create: This state is when a process is about to be created.

    Ready: This state is when the process is waiting for assignment to a particular processor.

    Running: Currently running or ready to run and is being served by cpu or will be served as soon as cpu is free.

    Waiting: This is when the process is waiting for some particular event to occur before entering the Running state.

    Terminated: This meand that the process has completed execution and is not in any other states.

**2. What is a zombie process?**

    A: A zombie process is is when the OS thinks that a process that has finished executing is still running.

**3. How does a zombie process get created? How does one get destroyed?**

    A: They get created when its parent doesn't call wait(). When the parent obtains the exit status of the child from wait(), the OS will remove the zombies entry from the process table.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

    A: Faster performance because it gets compiled into machine code.

