// NON PREEMPTIVE
// SHORTEST JOB FIRST !!

#include <stdio.h>
#include <stdlib.h>
struct process
{
    int pid; // process id
    int bt;  // burst time
    int at;  // arrival time
    int wt;  // waiting time
    int tt;  // turn around time
    int et;
    struct process *next;
};
struct process *front = NULL, *new, *temp = NULL;
struct process *ganttchart;
int total_burst = 0;
int p = 0;
void runFirst()
{
    /*
        this function will reinitilize the et and rbt , wt and tt .
    */
    temp = front;
    while (temp != NULL)
    {

        temp->wt = 0;
        temp->tt = 0;
        temp->et = 0;

        temp = temp->next;
    }
}
void insert(int b, int a)
{
    temp = front;
    new = (struct process *)malloc(sizeof(struct process));
    new->pid = ++p;
    new->bt = b;
    new->at = a;

    new->wt = 0;
    new->tt = 0;
    new->et = 0;

    new->next = NULL;
    if (front == NULL)
        front = new;
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new;
    }
}
void display(int n)
{
    float avgWT = 0, avgTT = 0;
    temp = front;
    printf("\n PROCESS ID\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURNAROUND TIME");
    while (temp != NULL)
    {
        printf("\n %d \t\t %d \t\t %d \t\t %d \t\t %d", temp->pid, temp->bt, temp->at, temp->wt, temp->tt);
        avgWT += temp->wt;
        avgTT += temp->tt;
        temp = temp->next;
    }
    printf("\n Average WAITING TIME \t %f \t Average TURNAROUND TIME\t %f \n", (avgWT / n), avgTT / n);
}

void sjf()
{
   
    int time = 0;
    int min = total_burst;
    runFirst();
    temp = front;
    while (time <= total_burst)
    {
        // SCAN FOR THE SHORTEST BURST TIME whose arrival time is less than or equals to the time

        ganttchart = NULL;
        temp = front;
        min = total_burst;
        while (temp != NULL)
        {
            if (temp->et == 0)
            {
                if ((time >= temp->at) && (temp->bt < min))
                {
                    min = temp->bt;
                    ganttchart = temp;
                }
            }
            temp = temp->next;
        }
        if (ganttchart == NULL)
        {
            // no process was found ..therefore idle time
            printf("\n CPU IDLE at %d", time);
            time++;
        }
        else
        {
            printf("\n Process %d at Time %d", ganttchart->pid, time);
            time += ganttchart->bt;
            ganttchart->et += 1;
            ganttchart->wt = time - (ganttchart->at + ganttchart->bt);
            ganttchart->tt = time - (ganttchart->at);
        }
    }
}
void main()
{
    int ch, i, n, a, b;
    // INSERT ONCE ONLY ..
    // AND DISPLAY ..
    printf("Enter the no of process \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\n Enter the Burst time And Arrival Time for Process \t %d \t", p + 1);
        scanf("%d %d", &b, &a);
        insert(b, a);

        total_burst += b;
    }
    sjf();
    display(n);
}
