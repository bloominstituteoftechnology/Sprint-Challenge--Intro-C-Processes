**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- A process can either be running, stopped, asleep, orphaned, or in a zombie state. When a process starts running it's reading and executing the code. It goes to sleep if it's waiting for an outside event to occur and/or complete, and it can become a zombie when there's nothing more to execute but the parent doesn't clean it up. If a process continues running after its parent has finished executing, it's considered an orphan. Either init or a parent process will reap the finished process to stop it.

**2. What is a zombie process?**

- When there's nothing more for the process to execute but the parent doesn't clean it up / reap it, it is considered a zombie process.

**3. How does a zombie process get created? How does one get destroyed?**

- They get created when its parent doesn't call wait() and takes longer to execute than its child. They get destroyed by init which adopts the zombie process after its parent is reaped and periodically calls wait().

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

- Non-compiled languages get to skip a step and are more easily readable by computers. Thus, they can take a lot less time to start executing.