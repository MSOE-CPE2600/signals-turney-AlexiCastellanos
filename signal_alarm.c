/**
 * File: signal_alarm.c
 * Description Program that schedules an alarm and handles SIGALRM with a custom signal handler.
 * 
 * Modified by: Alexi Castellanos
 * 
 * Brief summary of program:
 * - Sets an alarm for 5 seconds using the `alarm()` system call.
 * - Registers a custom signal handler for SIGALRM.
 * - The handler prints a message when the alarm signal is received.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/**
 *  Signal handler for SIGALRM
 * @param signo Signal number (SIGALRM)
 */
void handle_sigalrm(int signo) {
    printf("Alarm received! Signal number: %d\n", signo);
}

int main() {
    // Register the signal handler for SIGALRM
    if (signal(SIGALRM, handle_sigalrm) == SIG_ERR) {
        perror("Error setting signal handler");
        exit(EXIT_FAILURE);
    }

    // Schedule an alarm for 5 seconds
    printf("Setting an alarm for 5 seconds...\n");
    alarm(5);

    // Wait for the signal
    printf("Waiting for the alarm...\n");
    pause(); // Wait for any signal

    // Program continues after the signal
    printf("Program exiting after handling the alarm.\n");

    return 0;
}
