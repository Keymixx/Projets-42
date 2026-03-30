*This project has been created as part of the 42 curriculum by caaubert.*

# Codexion

## Description

Codexion is a concurrency simulation in C where coders share limited USB dongles to compile quantum code. The program orchestrates multiple threads representing coders alternating between compiling, debugging, and refactoring. The goal is to use POSIX threads and mutexes to manage resource synchronization and prevent any coder from burning out.

---

## Instructions
Compile the project using the provided Makefile

Execute the program by providing the mandatory arguments:


### Setup and Execution

```bash
make
```

```bash
./codexion number_of_coders time_to_burnout time_to_compile time_to_debug time_to_refactor number_of_compiles_required dongle_cooldown scheduler
```


## Resources

Video Reference: "Short introduction to threads (pthreads)" by CodeVault (https://www.youtube.com/watch?v=d9s_d28yJq0).

Peer Collaboration: Advice and logic validation from peers who previously completed the Philosophers project.


Blocking cases handled
Deadlock prevention: Coders acquire dongles asymmetrically; even-numbered coders take the left dongle first, while odd-numbered coders take the right dongle first.

Cooldown handling: Coders wait inside a loop using pthread_cond_timedwait until a signal confirms the requested dongle is no longer in its cooldown period.

Precise burnout detection: A dedicated monitor thread continuously checks deadlines. Upon detecting a burnout, it sends a signal to the main thread.

Log serialization: Console outputs are protected by a mutex to ensure state messages never interleave on a single line.

Thread synchronization mechanisms
Mutexes (pthread_mutex_t): Used to strictly protect the state of each individual dongle, preventing coders from duplicating or corrupting shared resources.

Condition Variables (pthread_cond_t): Manage the waiting queues. Coders rely on condition variables to wait for dongles safely rather than actively polling.

Monitor Coordination: The main thread remains blocked in a pthread_cond_wait loop. When the separate monitor thread detects a burnout, it signals this condition variable, allowing the main thread to wake up, terminate the simulation, and properly free all allocated memory.

---
