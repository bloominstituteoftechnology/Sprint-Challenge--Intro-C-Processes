1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means. 
[**</br>
Running  </br>
Waiting : waiting for an event or for a resource </br>
Stopped </br>
Zombie : dead but not removed from the process table.
 </br>**]()

2. What is a zombie process? How does one get created? How does one get destroyed?
[**</br>
Process that has completed but is still in the process table </br>
create when a child process ends but doesn't terminate until the parent reads the child's exit code  </br>
destroyed when the parent finishes reading the exit code
 </br>**]()


3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?
[**</br>
Compiled code is faster because the developer has more control over the code and can write a more effecient code 
</br>**]()

