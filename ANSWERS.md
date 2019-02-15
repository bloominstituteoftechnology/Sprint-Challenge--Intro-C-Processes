**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
-->   There are three main states of a process.
      1.  running  : which means it is currently running on the CPU.
      2.  ready and waiting :  which menas that it is ready to run immediately if selected.
      3.  blocked and waiting :  which means that it is not ready to run because some other 
                                 information is needed by the process before it can proceed. 

**2. What is a zombie process?**
-->  Once the process has ended, it has to be removed from the processes table.But, sometimes some of these processes stay      in the processes table even after they have completed execution.
​     So these processes that have completed their life of execution but still exist in the processes table are called          ‘Zombie Processes’. 

**3. How does a zombie process get created? How does one get destroyed?**
-->  If the parent fails to read the exit call(..using wait command) from the child process, the child process which has 
     already finished its execution.. thats how zombie process get created.
     As zombie are already killed processes .. you can not destroy them. So... by using 
            `kill -s SIGCHLD pid`
     command and passing the pid with the id of the parent process which  will remove all the child processes that are dead and completed.
         
**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
-->  Compiled language programs generally run faster than interpreted ones because interpreted language programs must be        reduced to machine instructions at runtime. However, with an interpreted language you can do things that cannot be         done in a compiled language. For example, interpreted programs can modify themselves by adding or changing functions       gat runtime

