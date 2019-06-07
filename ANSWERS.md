**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

	
* Start
This is the initial state when a process is first started/created.

* Ready
The process is waiting to be assigned to a processor. Ready processes are waiting to have the processor allocated to them by the operating system so that they can run. Process may come into this state after Start state or while running it by but interrupted by the scheduler to assign CPU to some other process.

* Running
Once the process has been assigned to a processor by the OS scheduler, the process state is set to running and the processor executes its instructions.

* Waiting
Process moves into the waiting state if it needs to wait for a resource, such as waiting for user input, or waiting for a file to become available.

* Terminated or Exit
Once the process finishes its execution, or it is terminated by the operating system, it is moved to the terminated state where it waits to be removed from main memory.

**2. What is a zombie process?**

A zombie process is a process whose execution is completed but it still has an entry in the process table. Zombie processes usually occur for child processes, as the parent process still needs to read its child’s exit status. Once this is done using the wait system call, the zombie process is eliminated from the process table. This is known as reaping the zombie process.

**3. How does a zombie process get created? How does one get destroyed?**


* All the memory and resources allocated to a process are deallocated when the process terminates using the exit() system call. But the process’s entry in the process table is still available. This process is now a zombie process.
* The exit status of the zombie process zombie process can be read by the parent process using the wait() system call. After that, the zombie process is removed from the system. Then the process ID and the process table entry of the zombie process can be reused.
* If the parent process does not use the wait() system call, the zombie process is left in the process table. This creates a resource leak.

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**


* Compiled language

+. Faster performance by directly using the native code of the target machine
+. Opportunity to apply quite powerful optimisations during the compile stage

-. Slow to develop (edit, compile, link and run. The compile/link steps could take serious time).

* Non-compiled language (Interpreted):

+. Easier to implement (writing good compilers is very hard!!)
+. No need to run a compilation stage: can execute code directly "on the fly"
+. Can be more convenient for dynamic languages

-. Slow to execute because each statement had to be interpreted into machine code every time it was executed