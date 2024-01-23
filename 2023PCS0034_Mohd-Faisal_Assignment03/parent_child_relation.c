#include <stdio.h>
#include <unistd.h>
int main()
{
    int parent_id = getpid();
    printf("I am parent, loging this message before forking...\n");
    printf("Process id of Parent - %d\n", parent_id);
    int child = fork();
    if (child < 0)
    {
        printf("Error in forking....\n");
        return -1;
    }
    else if (child == 0)
    {
        int child_pid = getpid();
        printf("I am child with PID - %d created from my parent PID - %d\n", child_pid, parent_id);
        printf("My parent PID - %d\n", getppid());
    }
    else
    {
        wait(NULL);
        printf("I have created a child with PID - %d\n", child);
    }
}