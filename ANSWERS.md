**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

- Running - the process is active, or ready
- Waiting - the process is waiting on a resource
- Stopped - the process has been stopped
- Zombie - the process has stopped but has not been removed from the process list

**2. What is a zombie process?**

- A zombie process is a child process that has not been removed from the process list. This can be avoided by making sure the parent process calls `wait()` at some point in it's execution.

**3. How does a zombie process get created? How does one get destroyed?**

- A zombie process is created when the parent process fails to clean it up. It gets destroyed by the Reaper Process.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

- Some of the benifits of compiling our code are catching errors, and ensuring all our variables have the appropriate types before a program is executed. Compiled code also runs faster because it is translated to binary. Because of this it is ready to be run natively on the processor.
