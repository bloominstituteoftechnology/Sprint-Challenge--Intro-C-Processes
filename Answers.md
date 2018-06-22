### Short Answer Questions

Add your answers inline, below, with your pull request.

1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.

idle - started and is waiting in the queue for chance to start up
ready - program has been loaded into memory and is read to take input
running - program is currently exicuting
waiting - program recived an interrupt and is waiting for the intrupt task to compleate before running again
zombie - program has compleated but still has its process listed

           |  <------ waiting
idle -> ready -> running ^-> zombie

2. What is a zombie process? How does one get created? How does one get destroyed?

a zombie process is a process that has compleated and exited but still has its 
process listed and running, one gets created by the parrent not calling wait before the child fork finishes, you kill them by rebooting your system

3. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

compiled langs vs interpted langs
with compiling down to machein code your going to be a lot faster then having to use another program interptit your code and feed it back to the cpu, the extrea benifets inclued greater speed, less overhang, less likely to run broken code as the compiler wont work if its horribly broken where an interpted lang may exacute the broken code only to find that is causes problems and crashes 