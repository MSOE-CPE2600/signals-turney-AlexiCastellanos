/**
 * @file signal_handler.c
 * @brief Sets a signal handler for SIGINT. The handler prints a message and allows the program to continue running.
 */

/**
 * Modified by: Alexi Castellanos
 * 
 * Brief summary of modifications:
 * - Updated the signal handler to print a message but not exit the program.
 * - Added a clean way to exit the program using SIGTERM.
 * - Enhanced comments for better code clarity.
 */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Flag to track if the program should exit
volatile bool keep_running = true;

/**
 * @brief Signal handler for SIGINT - prints a message and continues execution
 */
void handle_sigint(int signo) {
    printf("SIGINT received. Program continues running.\n");
}

/**
 * @brief Signal handler for SIGTERM - prints a message and exits the program
 */
void handle_sigterm(int signo) {
    printf("SIGTERM received. Exiting program gracefully.\n");
    keep_running = false; // Set flag to exit loop
}

int main() {

    // Register the signal handlers
    signal(SIGINT, handle_sigint);
    signal(SIGTERM, handle_sigterm);

    // Wait until a signal is received
    while (keep_running) {
        printf("Sleeping...\n");
        sleep(1);
    }

    printf("Exiting main program loop.\n");
    return 0;
}
