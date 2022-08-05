#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

void main(){
  pid_t my_pid,child_pid,parent_pid;
  child_pid=fork();
  if(child_pid<0){
    printf("the child is not created \n");
    exit(0);
  }

  if(child_pid==0){
    //we are in the child proscess now
    my_pid=getpid();//this will genrate the pid of this chid 
    parent_pid=getppid();//this will genrate the parent pid of this chid 
    printf("[CHILD] my pid is %d\n",my_pid);
    printf("[CHILD] my parent pid is %d\n",parent_pid);

    printf("[CHILD] sleeping for 10 seconds\n");
    sleep(5);//we are making child to sleep for 10 seconds so that parent execute the task and call exit function
    //then the child will be in orphan state
    printf("[CHILD] i am in  orphan state adopt me\n");
    
  }
  else{
	
	printf("[PARENT] This is parent process\n");
	my_pid = getpid();
	printf("[PARENT] My pid is: %d\n",my_pid);
	
	printf("[PARENT] Exiting...\n");
	exit(0);
	
	}
}