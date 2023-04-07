// Write a C program to read N strings. Create two child processes, each of this should perform sorting using two different methods (bubble, selection, quicksort etc). The parent should wait until one of the child process terminates.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

#define MAX_LENGTH 50
#define MAX_STRINGS 10

void bubble_sort(char **strings, int n) {
    int i, j;
    char *temp;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(strcmp(strings[j], strings[j + 1]) > 0) {
                temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
}

void selection_sort(char **strings, int n) {
    int i, j, min_idx;
    char *temp;

    for(i = 0; i < n - 1; i++) {
        min_idx = i;
        for(j = i + 1; j < n; j++) {
            if(strcmp(strings[j], strings[min_idx]) < 0) {
                min_idx = j;
            }
        }
        temp = strings[i];
        strings[i] = strings[min_idx];
        strings[min_idx] = temp;
    }
}

int main() {
    char strings[MAX_STRINGS][MAX_LENGTH];
    char *string_pointers[MAX_STRINGS];
    int i, n;

    printf("Enter the number of strings (up to %d): ", MAX_STRINGS);
    scanf("%d", &n);

    if(n > MAX_STRINGS) {
        printf("Too many strings");
        exit(1);
    }

    printf("Enter %d strings:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%s", strings[i]);
        string_pointers[i] = strings[i];
    }

    pid_t pid_bubble = fork();

    if(pid_bubble == -1) {
        printf("Failed to create bubble sort child process");
        exit(1);
    }
    else if(pid_bubble == 0) {
        bubble_sort(string_pointers, n);
        printf("Sorted by bubble sort:\n");
        for(i = 0; i < n; i++) {
            printf("%s\n", string_pointers[i]);
        }
        exit(0);
    }

    pid_t pid_selection = fork();

    if(pid_selection == -1) {
        printf("Failed to create selection sort child process");
        exit(1);
    }
    else if(pid_selection == 0) {
        selection_sort(string_pointers, n);
        printf("Sorted by selection sort:\n");
        for(i = 0; i < n; i++) {
            printf("%s\n", string_pointers[i]);
        }
        exit(0);
    }

    pid_t pid_terminated = wait(NULL);

    if(pid_terminated == pid_bubble) {
        printf("Bubble sort terminated first\n");
    }
    else if(pid_terminated == pid_selection) {
        printf("Selection sort terminated first\n");
    }

    return 0;
}