/**
 * File: signal_segfault.c
 * Description: Program that dereferences a null pointer causing a segmentation fault,
 * modified to handle SIGSEGV gracefully using a custom signal handler.
 *
 * Modified by: Alexi Castellanos
 * 
 * Brief summary of modifications:
 * - Added a signal handler to catch and handle SIGSEGV.
 * - The program now gracefully exits after a segmentation fault is encountered.
 * Date: 11/20/24
 */

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// Signal handler for SIGSEGV
void handle_sigsegv(int signo) {
    printf("SIGSEGV caught: Segmentation fault detected. Exiting program gracefully.\n");
    exit(EXIT_FAILURE); // Exit with failure status
}

int main(int argc, char* argv[]) {
    // Register the SIGSEGV handler
    signal(SIGSEGV, handle_sigsegv);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer (this will cause SIGSEGV)
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}
