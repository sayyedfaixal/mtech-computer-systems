#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *create_file(void *arg)
{
    FILE *file = fopen("threadt2.txt", "w");
    if (file == NULL)
    {
        perror("Error creating file");
        exit(EXIT_FAILURE);
    }
    fclose(file);

    return NULL;
}

void *write_to_file(void *arg)
{
    FILE *file = fopen("threadt2.txt", "w");
    if (file == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Hello, I am writing in the file created by you.\n");
    fclose(file);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    if (pthread_create(&t2, NULL, create_file, NULL) != 0)
    {
        perror("Thread creation failed");
        return EXIT_FAILURE;
    }

    if (pthread_create(&t1, NULL, write_to_file, NULL) != 0)
    {
        perror("Thread creation failed");
        return EXIT_FAILURE;
    }

    if (pthread_join(t2, NULL) != 0)
    {
        perror("Thread join failed");
        return EXIT_FAILURE;
    }

    if (pthread_join(t1, NULL) != 0)
    {
        perror("Thread join failed");
        return EXIT_FAILURE;
    }

    printf("File created and text written successfully!\n");

    return 0;
}