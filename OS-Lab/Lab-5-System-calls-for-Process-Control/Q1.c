// Write a C program to create a child process. Display different messages in parent process and child process. Display PID and PPID of both parent and child process.
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    pid_t pid;
    pid = fork();

    if(pid < 0) {
        printf("fork() failed");
        exit(0);
    }
    else if(pid == 0) {
        printf("I am the child process (PID=%d)\n", getpid());
        printf("I am the parent process (PPID=%d)\n", getppid());
    }
    else {
        printf("I am the parent process (PID=%d)\n", getpid());
        printf("My child process is (PID=%d)\n", pid);
    }

    return 0;
}