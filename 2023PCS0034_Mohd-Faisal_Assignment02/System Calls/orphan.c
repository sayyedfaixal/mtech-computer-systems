#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }
    else if (pid == 0)
    {
        sleep(5); // Child process sleeps, allowing parent to terminate
        printf("Orphan Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else
    {
        printf("Parent process: PID = %d\n", getpid());
    }

    return 0;
}
