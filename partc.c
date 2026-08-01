#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>



int main(int argc, const char* argv[]) {
    if (argc != 3) {
        printf("ERROR: no arguments\n");
        return 1;
    }

    const char *word = argv[1];
    const char *filename = argv[2];

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        /* Child process */

        char *args[] = {
            "grep",
            "-s",
            "-q",
            (char *)word,
            (char *)filename,
            NULL
        };

        execv("/usr/bin/grep", args);

        perror("exec");
        exit(1);
    }

    /* Parent process */

    int status;
    wait(&status);

    if (WIFEXITED(status)) {
        int exit_status = WEXITSTATUS(status);

        if (exit_status == 0) {
            printf("FOUND: %s\n", word);
            return 0;
        }

        if (exit_status == 1) {
            printf("NOT FOUND: %s\n", word);
            return 0;
        }

        if (exit_status == 2) {
            printf("ERROR: %s doesn't exist\n", filename);
            return 2;
        }
    }

    return 1;
}
