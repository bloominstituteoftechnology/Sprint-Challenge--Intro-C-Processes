# 1.

Main states of a process in a Unix system:

* Running: The process is either running or is ready to run

* Waiting: The process is waiting for an event or for a resource

* Stopped: The process has been stopped, usually by a signal

* Zombie: The process is dead but has not been removed from the process table

# 2.

A zombie process gets created as a parent process forks a child process that is not completely removed. As a parent process calls wait() the child process may be running before terminating and can thus exist as a zombie process between it terminating and the parent calling wait().

# 3.

Compiled languages are reduced to machine code once during compilation while intepreter languages are reduced to machine code every time they're run.
