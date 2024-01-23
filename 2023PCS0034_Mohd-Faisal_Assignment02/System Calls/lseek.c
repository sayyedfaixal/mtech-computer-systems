#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("lseek.txt", O_RDWR);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    lseek(fd, 7, SEEK_SET); // Move the file pointer to the 7th byte
    write(fd, "Seek!", 5);

    close(fd);

    return 0;
}
