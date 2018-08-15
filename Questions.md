Max Washington
Lambda School
Fri 10th Aug 2018

# Sprint-Challenge: Intro to C and Processes

### Short Answer Questions

1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

  1. -  R  running or runnable (on run queue)
  2. -  D  uninterruptible sleep (usually IO)
  3. -  S  interruptible sleep (waiting for an event to complete)
  4. -  Z  defunct/zombie, terminated but not reaped by its parent
  5. -  T  stopped, either by a job control signal or because it is being traced

2. What is a zombie process? How does one get created? How does one get destroyed?

A zombie process is created when a child process terminates when its parent process hasn't used wait.  Because it is still occupying space in the process table, which is a finite resource, this is considered a resource leak.
Operating systems generally have a method to contain such resource leaks, by having a reaper process that retrieves the exit status of zombie processes, allowing the operating system to dallocate resources.

3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

- Benefits: 

    Faster Excution - Programs written in compiled languages are typically faster because there's less abstraction between the language being written and the langauge that the computer runs (machine code/assembly) natively.

    Effiecency - Compiled languages are more efficient 

    Resource Control 


