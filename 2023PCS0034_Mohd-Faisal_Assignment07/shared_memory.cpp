#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
using namespace std;
int main() {
    key_t key = ftok("/tmp", 'X');
    int shmid = shmget(key, 1024, 0666);

    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    char* data = (char*)shmat(shmid, (void*)0, 0);

    if (data == (char*)(-1)) {
        perror("shmat");
        return 1;
    }

  cout<<"Shared memory message will be printed twice\n";
    cout << "Hey there this is the message from Shared Memory: " << data << endl;

    shmdt(data);

    return 0;
}
