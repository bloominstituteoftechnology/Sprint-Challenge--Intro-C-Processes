**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- Created(New): The initial state, process is created
- Ready: Process loaded into memory and awaiting execution on CPU
- Running: Process assigned to processor and code is ran
- Waiting: Waiting for an change to see if more code needs to be executed
- Terminated: Process has either finished running or explicitly killed.

**2. What is a zombie process?**

- A terminated process that didn't get cleaned up properly. It stays in the process table.

**3. How does a zombie process get created? How does one get destroyed?**

- A zombie process is created in the terminated state once a process has finished executing. Zombie processes can be destroyed with the kill command or upon reboot.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

- Benefit of using compiled language is that it has faster performance.
- Benefit of using non-compiled language is that is it eaiser to implement and can be convenient for dynamic languages.
