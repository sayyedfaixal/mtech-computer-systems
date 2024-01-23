#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct my_msg {
    long int msg_type;
    char some_text[MAX_TEXT];
};

int main() {
    int running = 1;
    int msgid;
    struct my_msg message;

    msgid = msgget((key_t)14534, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    while (running) {
        char buffer[MAX_TEXT];
        printf("Enter some text (type 'exit' to quit):\n");
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            perror("fgets");
            exit(EXIT_FAILURE);
        }
        
        // Remove newline character from input
        size_t length = strlen(buffer);
        if (length > 0 && buffer[length - 1] == '\n') {
            buffer[length - 1] = '\0';
        }

        message.msg_type = 1;
        strncpy(message.some_text, buffer, sizeof(message.some_text));

        if (msgsnd(msgid, (void *)&message, MAX_TEXT, 0) == -1) {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }

        if (strcmp(buffer, "exit") == 0) {
            running = 0;
        }
    }

    return 0;
}
