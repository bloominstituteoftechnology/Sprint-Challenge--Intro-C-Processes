#Short Answer Questions
##Add your answers inline, below, with your pull request.

1.) List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

* Start - When a state initializes, there is a starting point. I.E. turn vending machine power on, the state is at $0.00, and at this point it is in state "Waiting".

* Waiting - After the state started, it is now waiting for an input, after an input is given it will then go into a process/ running state.

* Run - This determines whether the input is enough to change the current state and elevate it to another level, or reverts back to waiting until the requirements are met to move onto a next state.

* End - This is when the state ran it's course (or not), and needs to terminate the current state to either run a clean/ new state with new/ relocatted memory, or just power down for the day.

--------------------------------------------------------------------------------

2.) What is a zombie process? How does one get created? How does one get destroyed?

* Zombie processes are processes in which the forked child process has completed it's task, but has not been cleaned up by the parent. It just sits there potentially hogging resources, with it's own PID on redundant/ already completed task.

* Zombie processes are created when programmers forget to put a ```wait()``` system call on the parent, to wait for the child to resolve itself, then the parent knows that it needs to clean up that used memory from the child and "garbage collect" it. Or, child goes off on a tangent and parent is stuck "waiting" for the child process to finish, but it has.

---------------------------------------------------------------------------------------

3.) What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

* it's just more efficient. The code will have to compile into something the machine knows, which saves time at the end. In a non- compiled language the machine will have to translate the written code into something it understands. Which is something compiled languages don't have to worry about, because if you code doesn't compile, that is your machine telling you it literally doesn't understand what you wrote on a native level.
