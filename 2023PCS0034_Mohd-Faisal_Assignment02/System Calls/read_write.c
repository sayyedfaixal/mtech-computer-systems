#include <stdio.h>
#include <unistd.h>

int main()
{
    char buffer[100];
    ssize_t bytes_read;

    printf("Enter a message: ");
    bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));

    printf("Read %ld bytes: %s\n", bytes_read, buffer);

    write(STDOUT_FILENO, "Hello, ", 7);
    write(STDOUT_FILENO, buffer, bytes_read);

    return 0;
}
