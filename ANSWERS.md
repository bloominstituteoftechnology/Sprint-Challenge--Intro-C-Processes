[Tutorial's Point on Processes](https://www.tutorialspoint.com/operating_system/os_processes.htm 'OS-Processes')

# Answers

## 1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

### Start

This is the initial state when a process is first created.

### Ready

These are processes that have started but are awaiting the processor to get them going. That or they were started but the CPU was scheduled to run another process first.

### Running

The process has been assigned and its intructions are being read.

### Waiting

The process is waiting for certain input, another file to run, or another resource.

### Exit

The process has completed or been terminated by the OS and is ready to be removed from the memory.

## 2. What is a zombie process? How does one get created? How does one get destroyed?

A zombie process is a child that completed its execution after calling fork() but without calling wait() on the parent and is merely residing in the memory since its exit process cannot be read.

It can be destroyed by calling wait() on the parent which kills the parent and the child process inherits it through _init_ and goes peacefully.

## 3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

I find that the most obvious benefit for me is that by compiling the code, I get to see how it runs and whether there are any glaring errors that I may have missed. By compiling, the code can be converted to machine code which allows it to run faster, but by compiling I don't have to really understand and definitely not write the machine code.
