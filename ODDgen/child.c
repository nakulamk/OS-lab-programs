#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<string.h>
#include<unistd.h>

void (int argc,char* argv[]){
  int shmid,id;
  void *psm;

  shmid=shmget((key_t)1122,1024,0666);
  printf("CHILD -- Key of shared memory>> %d\n", shmid);
  psm = shmat(shmid, NULL, 0666);

  int n=atoi(argv[]);

  printf("CHILD -- Printing Fibonacci >> \n");
  printf("CHILD -- ");

  for(int i=0;i<n;i++){
    sprintf(psm,"%d\t",(i*2)+1);
    psm+=strlen(psm);
    printf("%d\t",(i*2)+1);
  }
  shmctl(shmid, IPC_RMID, NULL);
}