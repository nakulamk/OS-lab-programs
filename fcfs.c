

#include<stdio.h>
#include<stdlib.h>

struct pcb{
    int pid,at,bt,ct,tt,wt;
};
void main(){
    int n;
    printf("Enter the no of proscess\n");
    scanf("%d",&n);
    struct pcb p[n];
    printf("PID\tAT\tBT\n");
    for(int i= 0; i<n; ++i){
        scanf("%d%d%d", &p[i].pid, &p[i].at, &p[i].bt);
    } 
    int min,index,completed=0,curtime=0,ct[30],pid[30];
    int j=0,len=n,prev=-2,tottt=0,totwt=0;
    int *iscompleted=(int*)calloc(n,sizeof(int));

    while(completed!=n){
        min=9999,index=-1;
        for(int i=0;i<n;i++){
            if(p[i].at<=curtime && !iscompleted[i]){
                if(p[i].at<min){
                    min=p[i].at;
                    index=i;
                }
            }
        }
        if ( index != -1 ){
            p[index].ct = p[index].bt + curtime;
            p[index].tt = p[index].ct - p[index].at;
            p[index].wt = p[index].tt - p[index].bt;

            tottt += p[index].tt;
            totwt += p[index].wt;

            ct[j] = p[index].ct;
            pid[j] = p[index].pid;
            ++j;

            curtime = p[index].ct;
            ++completed;
            iscompleted[index] = 1;
        }
        else{
            if (prev == curtime - 1){
                ++ct[j-1];
                prev = curtime;
            }
            else{
                pid[j] = -1;
                ct[j] = curtime + 1;
                ++len;
                ++j;
                prev = curtime;
            }
            ++curtime;
        }
    }
    printf("PID\tAT\tBT\tCT\tTT\tWT\n");
    for(int i = 0; i<n; ++i){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tt, p[i].wt);
    }

    printf("\nGantt Chart >> \n");
    for(int i = 0; i<len; ++i)
        printf("-------");
    printf("\n");
    for(int i = 0; i<len; ++i){
        if ( pid[i] != -1 )
            printf("  P%d  |", pid[i]);
        else
            printf(" IDLE |");
    }
    printf("\n");
    for(int i = 0; i<len; ++i)
        printf("-------");
    printf("\n");
    printf("0     ");
    for(int i = 0; i<len; ++i)
        printf("%d      ", ct[i]);

    printf("\n\nAvg turn around time >> %.2f\n", (float)tottt/n);
    printf("Avg waiting time >> %.2f\n", (float)totwt/n);
}