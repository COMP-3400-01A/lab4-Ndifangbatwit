#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>



int main(int argc, const char* argv[]) {
    if (argc == 1) {
        printf("ERROR: no arguments\n");
        return 1;
    }

    int count = argc - 1;

    if (count % 2 == 1) {
        /* Odd number of arguments: one middle argument */
        int middle = count / 2 + 1;

        char *args[] = {
            "echo",
            (char *)argv[middle],
            NULL
        };

        execv("/bin/echo", args);

        perror("exec");
        return 1;
    } else {
        /* Even number of arguments: two middle arguments */
        int middle1 = count / 2;
        int middle2 = middle1 + 1;

        char *args[] = {
            "echo",
            (char *)argv[middle1],
            (char *)argv[middle2],
            NULL
        };

        execv("/bin/echo", args);

        perror("exec");
        return 1;
    }
}
