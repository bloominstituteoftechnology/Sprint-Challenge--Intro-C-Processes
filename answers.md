List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.
1. Running Process is activly running or ready to start running
2. Waiting Process is in idle state waiting for an event or resource to trigger it.
3. Stopped Process has stopped running 
4. Zombie  Child was destroyed but not removed yet.
5. Orphan: Parent was destroyed before child

What is a zombie process? How does one get created? How does one get destroyed?
A zombie process gets created by not calling await at the right time or the right way. Once it gets destroyed it is considered to be reaped.

What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?

Optimization by translatting to the langauge that the hardware was created to run on. 
