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

### Race Conditions

 a race condition is a type of bug that occurs when multiple threads or processes access shared resources concurrently, leading to unpredictable and incorrect behavior. It arises when the outcome of the program depends on the relative timing of events, and the order of execution is not properly controlled or synchronized.

Here's an example to illustrate a race condition in C:

```
#include <stdio.h>
#include <pthread.h>

int counter = 0;

void *increment(void *arg) {
    int i;
    for (i = 0; i < 10000; i++) {
        counter++;  // Critical section
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment, NULL);
    pthread_create(&thread2, NULL, increment, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Counter value: %d\n", counter);

    return 0;
}
```

In this example, two threads are created, and each thread increments a shared variable counter by 10,000. However, due to the concurrent execution of threads, a race condition occurs. The order of execution is not guaranteed, and the threads may overlap in their access to the counter variable.

The race condition can result in incorrect output. For example, if both threads read the value of counter as 0 simultaneously, they will both increment it to 1 and write the value back, effectively missing one increment operation.

To avoid race conditions, synchronization mechanisms like mutexes, semaphores, or atomic operations should be used to control access to shared resources. In the example above, a mutex could be used to protect the critical section (incrementing counter) so that only one thread can access it at a time, ensuring consistent and correct behavior.

Race conditions can be challenging to identify and debug, as they often depend on specific timing and interleaving of threads or processes. Proper synchronization techniques and careful design are crucial to prevent race conditions and ensure the correctness of concurrent programs.

### Mutex

mutex (short for mutual exclusion) is a synchronization primitive used to protect shared resources from concurrent access by multiple threads. It provides a way to enforce mutual exclusion, ensuring that only one thread can access the protected resource at a time.

A mutex typically has two states: locked and unlocked. When a thread wants to access a shared resource, it must first acquire the mutex. If the mutex is currently locked by another thread, the requesting thread will be blocked (i.e., it will wait) until the mutex becomes available. Once the thread has finished using the shared resource, it releases (or unlocks) the mutex, allowing other threads to acquire it.

Mutexes are commonly used in multithreaded programming to prevent race conditions, where multiple threads can access and modify shared data simultaneously, leading to unpredictable and incorrect results. By using a mutex, threads can synchronize their access to shared resources, ensuring that only one thread operates on the resource at a time.

Here's an example of how mutexes can be used in C:

```
#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;  // Declare a mutex

void* threadFunction(void* arg) {
    // Acquire the mutex
    pthread_mutex_lock(&mutex);

    // Critical section (protected resource access)
    printf("Thread %d entered the critical section.\n", *(int*)arg);

    // Release the mutex
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int thread1Id = 1, thread2Id = 2;

    // Initialize the mutex
    pthread_mutex_init(&mutex, NULL);

    // Create two threads
    pthread_create(&thread1, NULL, threadFunction, &thread1Id);
    pthread_create(&thread2, NULL, threadFunction, &thread2Id);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}

```

In this example, two threads are created, and each thread enters a critical section protected by the mutex. Only one thread can enter the critical section at a time, while the other thread waits for the mutex to be released. The pthread_mutex_lock() and pthread_mutex_unlock() functions are used to acquire and release the mutex, respectively.

Note that mutexes are just one type of synchronization primitive available in C programming. Depending on the requirements of your program, you might also consider other synchronization mechanisms, such as semaphores or condition variables.

<https://www.youtube.com/watch?v=1tZhmTnk-vc&ab_channel=LowLevelLearning>

### h

The reason you cannot create threads and join them in the same loop is that the pthread_join() function blocks until the specified thread terminates. If you create all the threads in a loop and then immediately join them in the same loop, the execution will be blocked until the first thread finishes, preventing the creation of subsequent threads.
