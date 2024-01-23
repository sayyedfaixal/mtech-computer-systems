#include <stdio.h>
#include <stdlib.h>
struct Process
{
    int id;
    int arrival_time;
    int burst_time;
    int priority;
};
void MLFQ(struct Process processes[], int num_processes)
{
    int time_quantum[3] = {4, 6, 8};
    int current_queue = 0;
    printf("MLFQ Scheduling:\n");
    while (1)
    {
        int remaining_processes = 0;
        for (int i = 0; i < num_processes; i++)
        {
            if (processes[i].burst_time > 0)
            {
                remaining_processes = 1;
                int time_slice = (processes[i].burst_time < time_quantum[current_queue])
                                     ? processes[i].burst_time
                                     : time_quantum[current_queue];
                processes[i].burst_time -= time_slice;
                printf("Process %d in Queue %d executed for %d units.\n", processes[i].id, current_queue, time_slice);
                if (processes[i].burst_time > 0 && current_queue < 2)
                {
                    printf("Process %d moved to a lower-priority queue.\n", processes[i].id);
                    current_queue++;
                }
            }
        }
        if (!remaining_processes)
        {
            break;
        }
        current_queue = (current_queue + 1) % 3;
    }
}
int main()
{
    struct Process processes[] = {
        {1, 0, 20, 0},
        {2, 2, 10, 1},
        {3, 4, 8, 2},
        {4, 6, 6, 0},
        {5, 8, 12, 1},
    };
    int num_processes = sizeof(processes) / sizeof(processes[0]);
    MLFQ(processes, num_processes);
    return 0;
}
