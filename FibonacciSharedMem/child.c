#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>

void main(int argc,char *argv[]){
  int i,a=0,b=1,c;
  int shmid;
  void *psm;

  shmid=shmget((key_t)1111,1024,0666);
  printf("ID of shared memory %d>>\n",shmid);
  psm=shmat(shmid,NULL,0666);

  int n=atoi(argv[1]);
  printf("CHILD -- Printing fibonacci nubmers >> \n");
  for(int i=0;i<n;i++){
    sprintf(psm,"%d",a);
    // a is stored
    // into shmid(psm will be having the base add of the shmid)
    //instead of printing on stdout
    printf("%d",a);
    psm+=strlen(psm);
    c=a+b;
    a=b;
    b=c;

  }
}