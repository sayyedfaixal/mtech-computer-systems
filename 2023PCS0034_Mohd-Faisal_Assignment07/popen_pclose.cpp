#include <stdio.h>

int main() {
    FILE *fp;
    char buffer[1024];
  printf("Pringint the inode which displays the index number (inode) of each file and directory."
  "\n");
    fp = popen("ls -i", "r");
    if (fp == NULL) {
        perror("popen");
        return 1;
    }

    printf("Printing the output of the child process \n");
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    printf("Now,Close the pipe and wait for the child process to finish\n");
    pclose(fp);
    return 0;
}
