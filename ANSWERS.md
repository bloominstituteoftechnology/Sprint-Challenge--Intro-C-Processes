**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Created - The process is just created and is waiting to be approved.
Ready - The process has been loaded onto  memory.
Running - The process is being executed.
Blocked - The process has been stopped and is waiting for change of status.
Terminated - The process has finished or has been killed.


**2. What is a zombie process?**
A process that completed execution but is still in the process table.


**3. How does a zombie process get created? How does one get destroyed?**
When a child process needs to allow the parent process to read it's exit status. It is destroyed once it's read. 


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
The benifit is that you get a deeper understanding of what's being done for us when you have to complie your own code. With that being said though I can't wait to go back to using javascript. The ease of having it done for you is great. Maybe my mind will change as we dive deeper into C.
