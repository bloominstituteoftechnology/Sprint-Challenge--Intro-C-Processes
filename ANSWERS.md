**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Running - when a process is currently running it is in this state.
Waiting - The process is waiting for something like an event to call it or for resource.
Stopped - The process has been stopped through an exit or killed
Zombie - The process has stopped but has not been removed as it still needs to pass on it's exit status.



**2. What is a zombie process?**
As mentioned above, a zombie process is a process that has exited or is dead but still has data that it needs to pass on. Basically if a process dies with the exit code of 2 but the parent does not recieve it, this process will hold on to that exit code until the parent can pick it up.


**3. How does a zombie process get created? How does one get destroyed?**
When the parent finally reads all of the exit statuses through a wait method, it will see what child processes have died and taker thier exit codes and remove them. you can also manually kill the zombies with the unix command kill -s SIGCHILD <pid> (replacing pid with the id of the parent process).


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
A compiled language can catch bugs long before reaching production as it will not allow bad behavior in the code. It will stop things like missing arguments, improper use of variables, data types, spelling, and pointers. This can be benificial as it will allow you to be more confident in the code you have written overall.
