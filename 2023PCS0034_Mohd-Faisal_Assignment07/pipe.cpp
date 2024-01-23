#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    char message[] = "Hey there, this is the message parent is creating and sending it to the child process via Pipe!";
    char buffer[500];


    if (pipe(pipefd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid == 0) {
        
        close(pipefd[1]); 
        read(pipefd[0], buffer, sizeof(buffer));
        printf("Child Process Received: %s\n", buffer);
        close(pipefd[0]);
    } else {

        close(pipefd[0]); 
        write(pipefd[1], message, strlen(message));
        close(pipefd[1]);
    }

    return 0;
}
