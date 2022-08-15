/*  C program to implemnt Preemptive Priority CPU scheduling algorithm
    Name of the program: PriorityPreemptive.c
*/

#include <stdio.h>

struct Process
{
    int PID, Priority;
    unsigned int ArrivalTime;
    unsigned int BurstTime;
    unsigned int StartTime;
    unsigned int CompletionTime;
    unsigned int TurnAroundTime;
    unsigned int WaitingTime;
    unsigned int ResponseTime;
} P[10];

unsigned int BurstTimeRemaining[10];

void ProcessDetails(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process-ID: ");
        scanf("%d", &P[i].PID);
        printf("Enter Arrival Time: ");
        scanf("%d", &P[i].ArrivalTime);
        printf("Enter CPU Burst Time: ");
        scanf("%d", &P[i].BurstTime);
        printf("Enter Process Priority: ");
        scanf("%d", &P[i].Priority);
        BurstTimeRemaining[i] = P[i].BurstTime;
    }
}

void SelectProcess(int n)
{
    int t, count = 0, ShortProcess;
    float TotalWaitingTime = 0, TotalTurnAroundTime = 0, AvgWaitingTime, AvgTurnAroundTime;

    // we initialize the burst time of a process with maximum
    P[9].Priority = 10000; // 9

    for (t = 0; count != n; t++)
    {
        ShortProcess = 9; // 9
        for (int i = 0; i < n; i++)
            if (P[ShortProcess].Priority > P[i].Priority && P[i].ArrivalTime <= t && P[i].BurstTime > 0)
                ShortProcess = i;

        if (ShortProcess == 9)
        {
            printf("Idle %d", t + 1);
        }

        P[ShortProcess].BurstTime = P[ShortProcess].BurstTime - 1;
        printf("|P%d(1) %d", P[ShortProcess].PID, (t + 1));

        // if any process is completed
        if (P[ShortProcess].BurstTime == 0)
        {
            // If one process is completed, count increases by 1
            count++;
            P[ShortProcess].WaitingTime = t + 1 - P[ShortProcess].ArrivalTime - BurstTimeRemaining[ShortProcess];
            P[ShortProcess].TurnAroundTime = t + 1 - P[ShortProcess].ArrivalTime;

            // total calculation
            TotalWaitingTime += P[ShortProcess].WaitingTime;
            TotalTurnAroundTime += P[ShortProcess].TurnAroundTime;
        }
    }

    AvgWaitingTime = TotalWaitingTime / n;
    AvgTurnAroundTime = TotalTurnAroundTime / n;
    // Printing of the results
    printf("|\n\nID WT TAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\n", P[i].PID, P[i].WaitingTime, P[i].TurnAroundTime);
    }

    printf("Avg waiting time is: %f\n", AvgWaitingTime);
    printf("Avg turn around time is: %f", AvgTurnAroundTime);
    ;
}

int main()
{
    int n;
    printf("Enter number of process: ");
    scanf("%d", &n);
    ProcessDetails(n);
    printf("Gantt Chart:\n\n");
    SelectProcess(n);
}
