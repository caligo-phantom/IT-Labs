// Write a C program to accept a set of strings as command line arguments. Sort the strings and display them in a child process. Parent process should display the unsorted strings only after the child displays the sorted list
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<string.h>

#define MAX_ARGS 100
#define MAX_LENGTH 50

int main(int argc, char *argv[]) {
    pid_t pid;
    int status;
    char *sorted_args[MAX_ARGS];
    int i;

    if(argc > MAX_ARGS) {
        printf("Too many arguments");
        exit(0);
    }

    pid = fork();

    if(pid < 0) {
        printf("fork() failed");
        exit(0);
    }
    else if(pid == 0) {
        for(i = 0; i < argc; i++) {
            sorted_args[i] = argv[i];
        }
        sorted_args[i] = NULL;

        qsort(sorted_args, argc, sizeof(char *), (int (*)(const void *, const void *))strcmp);

        printf("Sorted arguments:\n");
        for(i = 0; i < argc; i++) {
            printf("%s\n", sorted_args[i]);
        }
    }
    else {
        wait(&status);

        printf("\nUnsorted arguments:\n");
        for(i = 0; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }

    return 0;
}