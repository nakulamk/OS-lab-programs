#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>

void(int argc,char *argv[]){
  if(argc<1){
    printf("No arguments is passed\n");
    exit(2);
  }
  int shmid,id;
  void *psm;
  shmid=shmget((key_1)1122,1026,0666|IPC_CREAT);
  printf("PARENT -- Key of shared memory >> %d\n", shmid);
  psm=shmat(shmid,NULL,0666);

  id=fork();
  if(id==0){
    //CHILD PROSCESSS
    execlp("./odd","odd",argv[1],NULL);
  }

  else{
    //PARENT PROSCESS
    wait(NULL);
    printf("PARENT -- Child finished execution\n");
    printf("PARENT -- Printing fibonacci numbers >> \n");
    printf("PARENT -- %s \n", (char *) psm);
  }
  shmdt(psm);
}