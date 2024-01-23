#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 5

struct ThreadArgs
{
    int *array;
    int length;
};

void *calculate_sum(void *arg)
{
    struct ThreadArgs *args = (struct ThreadArgs *)arg;
    int *array = args->array;
    int length = args->length;

    int sum = 0;
    for (int i = 0; i < length; ++i)
    {
        sum += array[i];
    }

    int *result = malloc(sizeof(int));
    *result = sum;

    return result;
}

int main()
{
    int numbers[ARRAY_SIZE] = {10, 20, 30, 40, 50};

    pthread_t t;
    struct ThreadArgs args;
    args.array = numbers;
    args.length = ARRAY_SIZE;

    if (pthread_create(&t, NULL, calculate_sum, &args) != 0)
    {
        perror("Thread creation failed");
        return EXIT_FAILURE;
    }

    int *result;
    if (pthread_join(t, (void **)&result) != 0)
    {
        perror("Thread join failed");
        return EXIT_FAILURE;
    }

    printf("Sum of array elements: %d\n", *result);
    free(result);

    return 0;
}
