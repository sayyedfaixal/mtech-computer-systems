#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    int parent_pid = getpid();
    printf("Parent Id is %d\n", parent_pid);
    for (int i = 0; i < 5; ++i)
    {
        int child_pid = fork();
        if (child_pid == 0)
        {
            printf("Child process (P%d) with PID - %d\n", i, getpid());
            break;
        }
        else if (child_pid < 0)
        {
            printf("Error in creating fork()....\ns");
            return -1;
        }
        for (int i = 0; i < 5; ++i)
        {
            // wait for all 5 process to finish
            wait(NULL);
        }
    }
    return 0;
}