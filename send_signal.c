/**
 * File: send_signal.c
 * Description: Program that sends SIGUSR1 to a specified process with a random integer value using sigqueue.
 * 
 * Modified by: Alexi Castellanos
 * 
 * Brief summary of program:
 * - Accepts a PID as a command-line argument.
 * - Sends SIGUSR1 to the specified PID along with a random integer value.
 * - Prints the random value being sent.
 * Date: 11/20/24
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert the command-line argument to a PID
    pid_t pid = atoi(argv[1]);
    if (pid <= 0) {
        fprintf(stderr, "Error: Invalid PID provided.\n");
        exit(EXIT_FAILURE);
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random integer value to send
    int random_value = rand() % 100; // Random number between 0 and 99

    // Prepare the sigval structure to pass data
    union sigval value;
    value.sival_int = random_value;

    // Send SIGUSR1 with the random value to the specified PID
    if (sigqueue(pid, SIGUSR1, value) == -1) {
        perror("Error sending signal");
        exit(EXIT_FAILURE);
    }

    // Print the sent value
    printf("Sent SIGUSR1 to PID %d with value: %d\n", pid, random_value);

    return 0;
}
