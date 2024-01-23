#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
using namespace std;

int main() {
    const char* fifoName = "myfifo";
    const char* message = "Hello, this is the message that will be read by child process";
    char buffer[500];

    mkfifo(fifoName, 0666);

    pid_t pid = fork(); 

    if (pid == 0) {
        int fd = open(fifoName, O_RDONLY);
        read(fd, buffer, sizeof(buffer));
        cout << "Child Process Received: " << buffer << endl;
        close(fd);
    } else if (pid > 0) {

        int fd = open(fifoName, O_WRONLY);
        write(fd, message, strlen(message));
        close(fd);
    } else {
        cerr << "Fork failed!" << endl;
        return 1;
    }

  
    unlink(fifoName);

    return 0;
}
