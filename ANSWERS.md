**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
ready - a process waiting to be assigned
waiting - used when waiting for a resource, like user input
terminated - once completed, or if terminated by the os terminated state waits to be removed from memory



**2. What is a zombie process?**
a process that is finished with exit call but still has an entry in the process table.


**3. How does a zombie process get created? How does one get destroyed?**
a child that has completed its task but is in terminated state while parent continues to run waiting for child status to exit.  a zombie process needs to be destroyed by killing the parent


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
some benefits to working with compiled code is that bugs can show themselves as you are compiling to the code causing errors prior to execution.  Helping to set your mind at ease that the code is bug free, however there could still be plenty of issues that still need to be worked out in a compiled code base.  Compiling your code will also help the speed of your program due to the fact that everything has been worked out and tasks do not need to be completed 'on the fly'

