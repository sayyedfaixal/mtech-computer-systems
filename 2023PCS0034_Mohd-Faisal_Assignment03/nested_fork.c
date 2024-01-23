#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    int p1_id = getpid();
    printf("\nGrand Parent (P1) with PID - %d\n", p1_id);
    int parent = fork();
    if (parent < 0)
    {
        printf("Error in creating a fork....");
        return -1;
    }
    else if (parent == 0)
    {
        int p2_id = getpid();
        printf("\nParent process (P2) with PID - %d created from Grand Parent (P1) - %d\n", p2_id, p1_id);
        printf("\nNow creating a grand child from (P2) - %d\n", p2_id);
        int child = fork();
        if (child < 0)
        {
            printf("Error in creating a fork....");
            return -1;
        }
        else if (child == 0)
        {
            int p3_id = getpid();
            printf("\nChild process (P3) with PID - %d created from Parent (P2) - %d\n", p3_id, p1_id);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        wait(NULL);
    }

    return 0;
}