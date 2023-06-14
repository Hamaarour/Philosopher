# Philosopher

the basics of threading a process. You will see how to create threads and you will discover mutexes

## What are the differences between process and thread?

Threads are not independent from each other unlike processes. As a result, threads shares with other threads their code section, data section and OS resources like open files and signals. But, like processes, a thread has its own program counter (PC), a register set, and a stack space.

### Why Multithreading?

 Threads are popular way to improve application through parallelism. For example, in a browser, multiple tabs can be different threads. MS word uses multiple threads, one thread to format the text, other thread to process inputs, etc.

==>Threads operate faster than processes due tofollowing reasons: 
Thread creation is much faster.
Context switching between threads is much faster.
Threads can be terminated easily.
Communication between threads is faster.

<https://www.personal.kent.edu/~rmuhamma/OpSystems/Myos/threads.htm>
