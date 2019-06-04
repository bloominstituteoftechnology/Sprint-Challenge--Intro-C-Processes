# Short Answer Questions

1.  List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

* The main process state are as followed:
  a) create which sets a new and ready state, b) ready which is waiting for the process to be loaded into memory, c) running which is the execution of the instructions given, d) blocked which is when the task cannot be carried out without an external change in state or event occuring, and e) terminate which is simply the running state has completed its execution or it was killed.

2.  What is a zombie process? How does one get created? How does one get destroyed?

* A zombie process is a process that has completed execution. The zombie process is created (not really created but exists) when a child processes that has been forked by a parent process. You can destroy a zombie process by either a reboot or writing a kill command.

3.  What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

* For me some of the benefits is that I don't have to write an explicit test to know whether my code will pass or not. The compiler immediately tells me if I am wrong or not and where to fix the error. This makes testing simple however it is not all encombersome. Like, if I want to specifically write a program and the code doesn't exist yet, the compiler will throw an error but if I was to write a test specifying my reasoning of this new code and how it works, it will pass.
