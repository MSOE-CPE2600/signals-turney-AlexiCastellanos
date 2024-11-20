## Lab Week 10 -- Signals


## Overview
This lab aims to explore the use of signals as an inter-process communication mechanism in systems programming. You will learn how to register signal handlers, as well as send, suspend, and view pending signals.

---

## objectives
- Understand signal dispositions and handlers
- Explore POSIX signal types (SIGINT, SIGTERM, SIGUSR1, SIGKILL, SIGSTOP)
- Implement signal handling in C programs
- Experiment with different signal sending methods (using command line)
- Work with system signals such as SIGALRM and SIGSEGV
- Utilize sigaction to handle signals with additional information
- Create programs to demonstrate sending signals with data using sigqueue

---

## Lab Structure

Part 1: Signal Research

Part 2: Working with a Signal Handler
- Compile and run signal_handler.c to register a handler for the SIGINT signal. Test sending SIGINT using two different methods (e.g., kill command and key combinations).
- Modify the handler so it doesn't exit after handling the signal and observe its behavior.

Part 3: Signals Sent from the Operating System
- signal_alarm.c to register a signal handler for SIGALRM and trigger an alarm after 5 seconds.
- Modify signal_segfault.c to install a handler for SIGSEGV and observe what happens when dereferencing a null pointer.

Part 4: Using sigaction
- signal_sigaction.c to use sigaction to register a handler for SIGUSR1. Make the handler print the process identifier of the sender.

Part 5: Sending Data with a Signal
- recv_signal.c to register a handler for SIGUSR1 and receive additional data.
- send_signal.c to send SIGUSR1 along with a random integer using sigqueue.