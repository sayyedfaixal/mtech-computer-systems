#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
 /*
 sem_t chopstick[5] is used to declare 5 semaphore variable, one for each of the five chopsticks.
First we try to initialize each semaphore variable with initial value to 1. 
Next we create five threads which will act as the five philosophers. 
Lastly we use pthread_join  function which makes the parent program wait for each of the thread to finish its execution
 */
sem_t chopstick[5];
void * philos(void *);
void eat(int);
int main()
 {
         int i,n[5];
        //  Initialize 5 threads to create the philosophers 
         pthread_t T[5];
         for(i=0;i<5;i++)
         sem_init(&chopstick[i],0,1);
         for(i=0;i<5;i++)
         {
            n[i]=i;
            // Create 5 philosophers 
            pthread_create(&T[i],NULL,philos,(void *)&n[i]);
        }
        /*
        The pthread_join() function waits for the thread specified by
       thread to terminate.  If that thread has already terminated, then
       pthread_join() returns immediately.  The thread specified by
       thread must be joinable.
        */
        for(i=0;i<5;i++)
        {
            pthread_join(T[i],NULL);
        }
 }
void * philos(void * n)
 {
         int ph=*(int *)n;
         
        //  Printing to know which phiolosopher is trying to eat with the chopstick
         printf("Philosopher %d wants to eat\n",ph);
         
         //  Printing to know which phiolosopher has pick up the left 
         printf("Philosopher %d tries to pick left chopstick\n",ph);
         sem_wait(&chopstick[ph]);
         
         //  Printing to know which phiolosopher has pick up the left chopstick
         printf("Philosopher %d picks the left chopstick\n",ph);
         
         //  Printing to know which phiolosopher has pick up the right chopstick 
         printf("Philosopher %d tries to pick the right chopstick\n",ph);
         
         sem_wait(&chopstick[(ph+1)%5]);
         
         printf("Philosopher %d picks the right chopstick\n",ph);
        //  Perform the eat operation
         eat(ph);
         
        //  Sleep for 2 milisecond
         sleep(2);
         
        //  Printing to know which phiolosopher has finished its eating
         printf("Philosopher %d has finished eating\n",ph);
         
         sem_post(&chopstick[(ph+1)%5]);
         
        //  Printing to know which phiolosopher has leave  the right chopstick 
         printf("Philosopher %d leaves the right chopstick\n",ph);
         
         sem_post(&chopstick[ph]);
         
        //  Printing to know which phiolosopher has leave the left chopstick 
         printf("Philosopher %d leaves the left chopstick\n",ph);
 }
 void eat(int ph)
 {
         printf("Philosopher %d begins to eat\n",ph);
 }

/*
Output:
Philosopher 2 wants to eat
Philosopher 2 tries to pick left chopstick
Philosopher 2 picks the left chopstick
Philosopher 2 tries to pick the right chopstick
Philosopher 2 picks the right chopstick
Philosopher 2 begins to eat
Philosopher 3 wants to eat
Philosopher 3 tries to pick left chopstick
Philosopher 4 wants to eat
Philosopher 4 tries to pick left chopstick
Philosopher 4 picks the left chopstick
Philosopher 4 tries to pick the right chopstick
Philosopher 4 picks the right chopstick
Philosopher 4 begins to eat
Philosopher 0 wants to eat
Philosopher 0 tries to pick left chopstick
Philosopher 1 wants to eat
Philosopher 1 tries to pick left chopstick
Philosopher 1 picks the left chopstick
Philosopher 1 tries to pick the right chopstick
Philosopher 2 has finished eating
Philosopher 4 has finished eating
Philosopher 4 leaves the right chopstick
Philosopher 4 leaves the left chopstick
Philosopher 0 picks the left chopstick
Philosopher 0 tries to pick the right chopstick
Philosopher 2 leaves the right chopstick
Philosopher 3 picks the left chopstick
Philosopher 1 picks the right chopstick
Philosopher 1 begins to eat
Philosopher 2 leaves the left chopstick
Philosopher 3 tries to pick the right chopstick
Philosopher 3 picks the right chopstick
Philosopher 3 begins to eat
Philosopher 1 has finished eating
Philosopher 1 leaves the right chopstick
Philosopher 1 leaves the left chopstick
Philosopher 3 has finished eating
Philosopher 3 leaves the right chopstick
Philosopher 3 leaves the left chopstick
Philosopher 0 picks the right chopstick
Philosopher 0 begins to eat
Philosopher 0 has finished eating
Philosopher 0 leaves the right chopstick
Philosopher 0 leaves the left chopstick


...Program finished with exit code 0
Press ENTER to exit console.
*/
