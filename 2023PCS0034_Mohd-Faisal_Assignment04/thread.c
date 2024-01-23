#include <stdio.h>
#include <pthread.h>

static volatile int counter = 0;
pthread_mutex_t M; // Global mutex

void *mythread(void *arg)
{
    printf("%s: begin\n", (char *)arg);
    int i;
    for (i = 0; i < 1000000; i++)
    {
        pthread_mutex_lock(&M); // Lock the mutex before accessing the shared variable
        counter = counter + 1;
        pthread_mutex_unlock(&M); // Unlock the mutex after modifying the shared variable
    }
    printf("%s: done\n", (char *)arg);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t p1, p2;
    pthread_mutex_init(&M, NULL); // Initialize the mutex
    printf("main: begin (counter = %d)\n", counter);
    pthread_create(&p1, NULL, mythread, "A");
    pthread_create(&p2, NULL, mythread, "B");
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    pthread_mutex_destroy(&M); // Destroy the mutex after use
    printf("main: done with both (counter = %d)\n", counter);
    return 0;
}

/*
We added a pthread_mutex_t named counter_mutex to protect access to the sharedCounter variable. Before each thread increments the sharedCounter, it locks the mutex using pthread_mutex_lock(), and after incrementing, it unlocks the mutex using pthread_mutex_unlock(). This ensures that only one thread can modify the sharedCounter at a time, making the program's output deterministic.
*/

/*
#include <stdio.h>
#include <pthread.h>
// A shared counter variable
static int sharedCounter = 0;
// Mutex for protecting sharedCounter
static pthread_mutex_t counterMutex = PTHREAD_MUTEX_INITIALIZER;

void *mythread(void *threadName)
{
    char *name = (char *)threadName;
    printf("%s: begin\n", name);

    for (int i = 0; i < 1000000; ++i)
    {
        // Lock the mutex before accessing the sharedCounter
        pthread_mutex_lock(&counterMutex);
        sharedCounter++;
        // Unlock the mutex after modifying the sharedCounter
        pthread_mutex_unlock(&counterMutex);
    }

    printf("%s: done\n", name);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    printf("main: begin (sharedCounter = %d)\n", sharedCounter);

    // Create two threads
    pthread_create(&thread1, NULL, mythread, "Thread A");
    pthread_create(&thread2, NULL, mythread, "Thread B");

    // Join both threads to wait for them to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("main: done with both (sharedCounter = %d)\n", sharedCounter);

    return 0;
}

*/
