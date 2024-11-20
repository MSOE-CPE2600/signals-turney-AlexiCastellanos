/**
 * File: signal_sigaction.c
 * @brief Program that uses sigaction to handle SIGUSR1 and retrieve sender details.
 * 
 * Modified by: Alexi Castellanos
 * 
 * Brief summary of program:
 * - Registers a signal handler for SIGUSR1 using sigaction.
 * - The handler prints the PID of the sender process and any additional data.
 * - The program runs in an infinite loop, waiting for SIGUSR1 signals.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/**
 * @brief Signal handler for SIGUSR1
 * @param signo Signal number (SIGUSR1)
 * @param info Signal information structure containing sender details and value
 * @param context Context (unused)
 */
void handle_sigusr1(int signo, siginfo_t *info, void *context) {
    if (info != NULL) {
        printf("Received SIGUSR1 from PID: %d\n", info->si_pid);
        printf("Signal value: %d\n", info->si_value.sival_int);
    } else {
        printf("Received SIGUSR1 but no additional information available.\n");
    }
}

int main() {
    struct sigaction sa;

    // Configure sigaction structure
    sa.sa_flags = SA_SIGINFO;  // Enable extended signal information
    sa.sa_sigaction = handle_sigusr1; // Set the custom signal handler
    sigemptyset(&sa.sa_mask);  // No signals are blocked during handler execution

    // Register the signal handler for SIGUSR1
    if (sigaction(SIGUSR1, &sa, NULL) == -1) {
        perror("Error setting up sigaction");
        exit(EXIT_FAILURE);
    }

    // Print process ID for the sender to use
    printf("Process ready to receive SIGUSR1. PID: %d\n", getpid());
    printf("Waiting for signals...\n");

    // Infinite loop to keep the program running
    while (1) {
        pause(); // Wait for signals
    }

    return 0;
}
