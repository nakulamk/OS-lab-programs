#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
  pid_t my_pid,child_pid,parent_pid;
  child_pid=fork();
  if(child_pid<0){
    printf("Fork failed!");
    exit(0);
  }

  if(child_pid==0){
    //CHILD proscess
    my_pid=getpid();
    parent_pid=getppid();
    printf("[CHILD] my pid is %d\n",my_pid);
    printf("[CHILD] my parent pid is %d\n",parent_pid);
    printf("exiting\n");
    exit(0);
    //child will be in zombie proscess untill parent recives the exit call
  }
  else{
    //PARENT proscess
    my_pid=getpid();
    parent_pid=getppid();
    printf("[PARENT] My pid is %d\n", my_pid);
    printf("[PARENT] My parent's pid is %d\n", parent_pid);
    printf("[PARENT] Sleeping for 10 seconds.\n");
    sleep(10);//simply making parent sleep for 10sec so child exit by complete its works and it will be in zombie proscess
    printf("[PARENT] Child pid = %d has ended, but it has an entry >",my_pid);  
  }
}