#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;
#define NUM_PROCESSES 5
struct Process
{
    int pid;
    int tickets;
};
int lotteryScheduling(struct Process processes[], int numProcesses)
{
    int totalAvailableTickets = 0;
    int winningTicket, accumulatedTickets = 0;
    for (int i = 0; i < numProcesses; i++)
    {
        totalAvailableTickets += processes[i].tickets;
    }

    cout << "random number : " << rand() << endl;
    winningTicket = rand() % totalAvailableTickets;
    cout << "winningTicket : " << winningTicket << endl;
    for (int i = 0; i < numProcesses; i++)
    {
        accumulatedTickets += processes[i].tickets;
        if (winningTicket < accumulatedTickets)
        {
            return processes[i].pid;
        }
    }
    return -1;
}
int main()
{
    srand(time(NULL));
    struct Process processes[NUM_PROCESSES];
    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        processes[i].pid = i + 1;
        processes[i].tickets = rand() % 10 + 1;
    }
    printf("Processes and their lottery tickets:\n");
    for (int i = 0; i < NUM_PROCESSES; i++)
    {
        printf("Process %d: Tickets = %d\n", processes[i].pid, processes[i].tickets);
    }
    int winner = lotteryScheduling(processes, NUM_PROCESSES);
    if (winner != -1)
    {
        printf("Winner: Process %d\n", winner);
    }
    else
    {
        printf("Error: No process selected as the winner.\n");
    }

    return 0;
}
