/**
 * File: recv_signal.c
 * Description: Program that uses sigaction to handle SIGUSR1 and retrieve additional data sent with the signal.
 * 
 * Modified by: Alexi Castellanos
 * 
 * Brief summary of program:
 * - Registers a signal handler for SIGUSR1 using sigaction.
 * - The signal handler retrieves and prints the `sival_int` value sent with the signal.
 * - The program runs in an infinite loop, waiting for SIGUSR1 signals.
 * Date: 11/20/24
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/**
 * Signal handler for SIGUSR1
 * @param signo Signal number (SIGUSR1)
 * @param info Signal information structure containing additional data
 * @param context Context (unused)
 */
void handle_sigusr1(int signo, siginfo_t *info, void *context) {
    // Retrieve and print the value sent with the signal
    if (info != NULL) {
        printf("Received SIGUSR1 from PID: %d with value: %d\n", info->si_pid, info->si_value.sival_int);
    } else {
        printf("Received SIGUSR1 but no additional information available.\n");
    }
}

int main() {
    struct sigaction sa;

    // Configure the sigaction struct
    sa.sa_flags = SA_SIGINFO;  // Enable passing additional info to the handler
    sa.sa_sigaction = handle_sigusr1; // Assign the signal handler
    sigemptyset(&sa.sa_mask);  // No blocked signals during handler execution

    // Register the SIGUSR1 signal handler
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error registering SIGUSR1 handler");
        exit(EXIT_FAILURE);
    }

    // Print the process ID for the sender to use
    printf("Receiver process running. PID: %d\n", getpid());
    printf("Waiting for SIGUSR1 signals...\n");

    // Infinite loop to keep the program running
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
