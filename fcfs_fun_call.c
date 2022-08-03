#include<stdio.h>
#include<stdlib.h>
struct process{
  int pid,at,bt,ct,tt,wt;
};
float tot_wt=0;
float tot_tt=0;
//we are selecting the fc arriving time using bubble sort;
void sort(struct process a[10],int n){
  int i,j;
  struct process temp;
  for(i=0;i<n;i++){
    for(j=0;j<n-1-i;j++){
      if(a[j].at>a[j+1].at){
        temp=a[j];
        a[j]=a[j+1];
        a[j+1]=temp;
      }
    }
  }
  for(i=0;i<n;i++){
    a[i].ct=a[i].tt=a[i].wt=0;
  }
}

//function to find total time
void findtt(struct process a[],int n){
  for(int i=0;i<n;i++){
    a[i].tt = a[i].ct - a[i].at;
    tot_tt=tot_tt+a[i].tt;
  }
}

//To find Wait time
void findwt(struct process a[],int n){
  for (int i = 0; i < n; i++){
    a[i].wt = a[i].tt - a[i].bt;
    tot_wt=tot_wt+a[i].wt;
  }
}
void findavg(struct process a[],int n){
  sort(a,n);
  int ct=a[0].at+a[0].bt;
  a[0].ct=ct;
  for(int i=1;i<n;i++){
    ct=ct+a[i].bt;
    a[i].ct=ct;
  }
  findtt(a,n);
  findwt(a,n);
  printf("PID\tAT\tBT\tCT\tTT\tWT\n");
  for (int i = 0; i < n; i++){
    printf("%d\t%d\t%d\t%d\t%d\t%d\n", a[i].pid, a[i].at, a[i].bt, a[i].ct, a[i].tt, a[i].wt);
  }
  printf("Average Turn Around time is %.3f\n",tot_tt/n);
  printf("Average Waiting time is %.3f\n",tot_wt/n);
}
void main(){
  int i,n;
  struct process a[10];
  printf("enter the number of process\n");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    a[i].pid=i+1;
    printf("enter the proscess %d arrival time",(i+1));
    scanf("%d",&a[i].at);
    printf("enter the proscess %d burst time",(i+1));
    scanf("%d",&a[i].bt);
  }
  findavg(a,n);
}