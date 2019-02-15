**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

A process can be running, waiting, stopped, or zombie 🧟‍♂️. Running means the process is running. Waiting means it's waiting for something to happen like a child to stop running before it runs. Stopped means stopped.

**2. What is a zombie process?**

A zombie process is a process that has finished executing, but the OS thinks is still running.

**3. How does a zombie process get created? How does one get destroyed?**

A zombie process gets created when a parent process doesn't communicate with the OS that the child has stopped running. To get destroyed there is a reaper process that runs every so often that will kill the process.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

Compiled code compiles down to machine code, making it very fast and efficient to run.
