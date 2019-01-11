**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

    ready - the process exists but is waiting for a processor 
    running - process has its instructions executed by processor
    waiting - process is stopped to wait for a resource

**2. What is a zombie process?**

    A process that was not closed and left open even though it's not being processed/used anymore.

**3. How does a zombie process get created? How does one get destroyed?**

    A zombie process is created when a child is created and fully executed but it hasn't been removed off the process table.
    It can be destroyed by the parent process calling the wait function.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

    One benefit of working in a compiled language is that errors and warnings can be given when compiled so that there is a step between compiling and running where the developer can fix the code.
    Also, once compiled, programs written in a compiled language run faster than comparable ones written in a non-compiled language.
    