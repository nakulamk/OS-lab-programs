// Program to implement Round Robin Scheduling algorithm
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct
{
    int id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turn_around_time;
    int remaining_time;
    int finished_index;
} process_t;
process_t processes[10];
int n;
int arrival_comparator(const process_t *a, const process_t *b)
{
    return a->arrival_time > b->arrival_time;
}
int finished_comparator(const process_t *a, const process_t *b)
{
    return a->finished_index > b->finished_index;
}
void schedule_rr(int tq)
{
    int i, finished_jobs = 0;
    float twt = 0, ttt = 0;
    qsort(processes, n, sizeof(process_t), arrival_comparator);
    int cur_time = processes[0].arrival_time;
    while (finished_jobs < n)
    {
        for (i = 0; i < n && processes[i].arrival_time <= cur_time; i++)
        {
            if (processes[i].remaining_time != 0)
            {
                if (processes[i].remaining_time <= tq)
                {
                    printf("Scheduling process %d and finishing\n", processes[i].id);
                    cur_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    processes[i].turn_around_time = cur_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turn_around_time - processes[i].burst_time;
                    processes[i].finished_index = finished_jobs++;
                    twt += processes[i].waiting_time;
                    ttt += processes[i].turn_around_time;
                    int flag = 1, j;
                    for (j = 0; j < n && processes[j].arrival_time <= cur_time; j++)
                        if (processes[j].remaining_time != 0)
                        {
                            flag = 0;
                            break;
                        }
                    if (flag && finished_jobs < n)
                    {
                        // Jump to next processes arrival time
                        cur_time = processes[j].arrival_time;
                    }
                }
                else
                {
                    printf("Scheduling process %d...\n", processes[i].id);
                    processes[i].remaining_time -= tq;
                    cur_time += tq;
                }
            }
        }
    }

    qsort(processes, n, sizeof(process_t), finished_comparator);
    // Print table
    printf("\nId\tAT\tBT\tWT\tTT\n");
    for (i = 0; i < n; i++)
        printf("%d\t%d\t%d\t%d\t%d\n", processes[i].id, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turn_around_time);

    printf("Average waiting time: %f\n", twt / ((float)n));
    printf("Average turnaround time: %f\n", ttt / ((float)n));
}
int main()
{
    int i;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter process details\nArrival time\tBurst time\n");
    for (i = 0; i < n; i++)
    {
        processes[i].id = i + 1;
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    int tq;
    printf("Enter time quanta to use : ");
    scanf("%d", &tq);
    schedule_rr(tq);
}
