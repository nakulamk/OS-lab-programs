#include <stdio.h>
#include <stdlib.h>
int *CT, tct = 0, *gc;
void FCFS(int n, int *at, int *bt)
{
    int mat = 0, i, j, k, flag = 0, t, c;
    for (i = 0; i < n; i++)
    {
        printf("Arrival and burst time of process %d:", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        if (at[i] > mat)
            mat = at[i];
        tct += bt[i];
    }
    gc = (int *)malloc(tct * sizeof(int));
    c = 0;
    for (i = 0; i <= mat; i++)
    {
        flag = 0;
        t = i;
        for (j = 0; j < n; j++)
        {
            if (at[j] == t)
            {
                flag = 1;
                for (k = 0; k < bt[j]; k++)
                {
                    gc[c++] = j;
                }
            }
        }
        if (flag == 0 && i > c - 1)
        {
            gc[c++] = -1;
            tct += 1;
            gc = (int *)realloc(gc, tct * sizeof(int));
        }
    }
}
void main()
{
    int n, *AT, *BT, i;
    float tt = 0, tw = 0;
    int TAT, WT;
    printf("Enter the no of processes:");
    scanf("%d", &n);
    AT = (int *)malloc(n * sizeof(int));
    BT = (int *)malloc(n * sizeof(int));
    CT = (int *)malloc(n * sizeof(int));
    FCFS(n, AT, BT);
    printf("Gantt chart of FCFS algorithm with each part equal to 1 ms\n");
    for (i = 0; i < tct; i++)
    {
        CT[gc[i]] = i;
        if (gc[i] != -1)
        {
            int p = gc[i];
            p++;
            printf("|P%d", p);
        }
        else
            printf("|idle");
    }
    printf("|");
    printf("\nPID AT BT CT TT WT");
    for (i = 0; i < n; i++)
    {
        TAT = CT[i] - AT[i] + 1;
        tt += TAT;
        WT = TAT - BT[i];
        tw += WT;
        printf("\n%d   %d  %d  %d  %d  %d", i + 1, AT[i], BT[i], CT[i] + 1, TAT, WT);
    }
    printf("\nAvg turnaround time=%.2f ms and avg waiting time=%.2f ms", tt / n, tw / n);
    free(AT);
    free(BT);
    free(CT);
    free(gc);
}
