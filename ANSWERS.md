**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
* Created - Initial state
* Ready - Process is loaded into memory, and in stanby to be executed.
* Running - Process is chosen and executed.
* Waiting - Waits if process needs to request access or input from user.
* Terminated - Process is killed and deleted.


**2. What is a zombie process?**
* Zombie process is where the child process is still running even though it has been told to terminate.


**3. How does a zombie process get created? How does one get destroyed?**
* Zombie process gets created when the parent process doesn't read the exit call from the child process. They can be destroyed by the parent process having wait().


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
* Benefits of a compiled language is that it has faster execution and has the opportunity for optimization because the machine understands it, while a non-compiled language needs to be translated to the machine.