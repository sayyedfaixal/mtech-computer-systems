#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("open_system.txt", O_WRONLY | O_CREAT);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    write(fd, "Hello, This is been written by  open() system call by Faisal!\n", 100);

    close(fd);

    return 0;
}
