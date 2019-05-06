**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created: Process is newly created by system call but is not ready to run
User Running: Process is running in user mode
Kernal Running: Process is a kernal process
Zombie: Process does not exist or is terminated
Preempted: Process runs from kernal to user mode
Ready to Run in Memory: Process has reached a state where it ready to run in memory and needs to wait for kernal to schedule it
Sleep Swapped: Process has been swapped to a secondary storage and is at a blocked state
Asleep in memory: Process is in memory but it in blocked state

**2. What is a zombie process?**
A zombie process is a process that has completed execution but still has an entry in the process table.

**3. How does a zombie process get created? How does one get destroyed?**
Zombie processes occur when a parent process needs to read it's child's exit status. Once the exit status is read with the wait system call, the zombie entry is removed from the process table.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled languages are self contained, and ready to be executed when we need. Compiled languages are also very efficient and faster once compiled compare to non compiled languages.
