**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
created: in this state, the process awaits admission to the ready state
ready: loaded into memory and wait for execution
running: instructions are executed 
blocked: process can't not advance without further input
terminated: done running or kill


**2. What is a zombie process?**
process that that has already finished execution but still not terminated


**3. How does a zombie process get created? How does one get destroyed?**

A zombie process occurs when a process has completed execution but still has an entry in the process table. A zombie process gets destroyed when the parent process calls an exit statu

**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled languages are faster to execute than interpreted langauges because interpreted languages have to interpret and compile after every step of the code. Compiled languages are compiled then ran as an executable. Compiled code runs without further preparation and processing because the code is the native code for the CPU on the target machine.

