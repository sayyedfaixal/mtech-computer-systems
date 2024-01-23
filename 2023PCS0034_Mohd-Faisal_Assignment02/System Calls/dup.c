#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("duplicate_txt_file.txt", O_WRONLY | O_CREAT);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }

    int new_fd = dup(fd);

    write(new_fd, "Hello from dup()!\n", 18);

    close(fd);
    close(new_fd);

    return 0;
}
