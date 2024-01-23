#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int parent_pid = getpid();
    printf("Parent process with PID - %d who is creating a child process.\n", parent_pid);
    int child = fork();
    if (child == 0)
    {
        int child_pid = getpid();
        printf("Child process with PID - %d created from parent PID - %d\n", child_pid, parent_pid);
    }
    else if (child < 0)
    {
        printf("Error in creating a child process...");
        return -1;
    }
    else
    {
        int status;
        wait(&status);
        printf("My child process has finished the task :)\n");
    }
}