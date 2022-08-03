// ...........................FCFS PROGRAM...................
#include<stdio.h>
#include<stdlib.h>

#define size 10

struct pro{
  int pid,burst,at,ct,tat,wt;
};

void main(){
  struct pro p[size],temp;
  int i,j=0,n,sum=0;
  int total_wt=0,total_tat=0;
  float avg_wt=0.0,avg_tat=0.0;
  printf("FCFS ALGORITHM\n");
  printf("Enter the number of proscess\n");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("Enter the arrival time of the proscess %d>>",i+1);
    scanf("%d",&p[i].at);
    printf("Enter the burst time of the proscess %d>>",i+1);
    scanf("%d",&p[i].burst);
    p[i].pid=i+1;
  }

  //USING BUBBLE SORT ALGO TO SORT THE ARRIVAL TIME 
  for(i=0;i<n;i++){
    for(j=0;j<n-1-i;j++){
      if(p[j].at>p[j+1].at){
        temp=p[j];
        p[j]=p[j+1];
        p[j+1]=temp;
      }
    }
  }

  //INIITALIZING THE ct tat and wt to 0
  for(i=0;i<n;i++){
    p[i].ct=p[i].tat=p[i].wt=0;
  }

  //TO FIND THE COMPLETION TIME
  int ct=p[0].at+p[0].burst;
  p[0].ct=ct;
  for(i=1;i<n;i++){
    ct=ct+p[i].burst;
    p[i].ct=ct;
  }

  //TO FIND THE TURN AROUND TIME and TOTAL TURN AROUND TIME
  for(i=0;i<n;i++){
    p[i].tat=p[i].ct-p[i].at;
    total_tat+=p[i].tat;
  }

  //TO FIND THE WAIT TIME AND TOTAL WAIT TIME
  for(i=0;i<n;i++){
    p[i].wt=p[i].tat-p[i].burst;
    total_wt+=p[i].wt;
  }

  printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
  for(i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].burst,p[i].ct,p[i].tat,p[i].wt);
  }

  printf("the total turn around time is %d\n",total_tat);
  printf("The Total wait time  is %d\n",total_wt);

  avg_tat=total_tat/n;     avg_wt=total_wt/n;

  printf("the avg turn around time is %.3f\n",avg_tat);
  printf("the avg wait time is %.3f\n",avg_tat);
}
