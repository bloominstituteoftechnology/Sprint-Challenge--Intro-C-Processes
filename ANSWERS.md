**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
<br> The main states of a process include Start > Ready > Running > Waiting > Exit <br>
<br> Start: initial state when a process is first created
<br> Ready: The process is waiting for resources to run, aka: waiting to be assigned to a processor
<br> Running: The process is running 
<br> Waiting: The process switches to this state when it needs a resource to continue it's process
<br> Exit: After the process completes itself, the OS terminates the process

**2. What is a zombie process?**
<br> A process which has finished but still exists on the OS process table

**3. How does a zombie process get created? How does one get destroyed?**
<br> If the parent decides not to wait for the child’s termination to complete and it continues with it's next task, once the termination of the child does happen, the exit status fails to be read and this leaves the child on the process table. 
<br> To destroy a zombie process, simply terminate the parent process that it was created in and this will also clean up the child process. 

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
<br> Compiled languages can result in very efficient programs because the code is translated into machine code before it runs. An interpreted language/non-compiled language is doing all of this process in real time as the program is being used, which can result in a slower program. 
