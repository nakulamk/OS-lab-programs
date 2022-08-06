#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

void main(int argc, char * argv[]){
  int shmid;
  void * psm;
  int a=0,b=1,c;
  shmid=shm_open("os",O_CREAT|O_RDWR,0666);
  ftruncate(shmid,1024);
  printf("CHILD -- ID of shared memory >> %d\n", shmid);
  psm=mmap(0,1024,PROT_WRITE,MAP_SHARED,shmid,0);
  n=atoi(argv[1]);
  printf("CHILD -- Printing fibonacci nubmers >> \n");

  //FIB LOGIC
  for(i=0;i<n;i++){
    sprintf(psm,"%d",a);
    psm+=strlen(psm);
    printf("%d\n",a);
    c=a+b;
    a=b;
    b=c;
  }
  pirntf("\n");
}  