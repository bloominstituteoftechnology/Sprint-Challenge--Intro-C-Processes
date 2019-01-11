**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
 1. Start: Initial state --> When a process is first created

 2. Ready: A process needs a processor to start running, thus if the program is `ready` it will wait, or a program could also be interrupted by the OS scheduler if it is assinging CPU for other processes going on, thus also being in the `ready` state again to start running

 3. Running: Once the process has been assigned to a processor it can then start running / execute instructions given

 4. Waiting: Process is in this state because it is waiting for a resource (ie. user input, file availability)

 5. Terminated / Exit: Once process is finished executing/ terminated by the OS, it is moved to the `terminated` state || waits to be removed from memory


**2. What is a zombie process?**
  - When a process is complete, but still has an entry inside the process table it is known as a `zombie process`. A `zombie process` would be found inside the terminated-state of a process.


**3. How does a zombie process get created? How does one get destroyed?**
  - Zombie processes can be made when we create a process via `fork()`. If the parent process were to call `wait()`, then the parent execution has to wait for the child process to be terminated: thus making it wait for the child process to be `terminated` from the memory and keeping an entry in the process table until removed from memory.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

  - A main benefit is: speed. Programs compiled in native code are usually faster at run time compared to something that has to be translated first at run time.
  - Makes it easier to control use of CPU and memory  