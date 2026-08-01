#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <ctype.h>


// TODO: Include more header files (read the manpages to find out more!)

int main(int argc, const char* argv[]) {
    if (argc == 1) {
        printf("ERROR: No arguments\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (i > 1) {
            printf(",");
        }

        for (int j = 0; argv[i][j] != '\0'; j++) {
            printf("%c", toupper(argv[i][j]));
        }
    }

    printf("\n");

    return 0;
}
