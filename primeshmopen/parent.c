#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

void main(int argc,char*argv){
  void *psm;
  int smid,id;

  if(argc<2){
    printf("no arguments passed\n");
    exit(2);
  }
  if(argc[1]>argc[2]){
    printf("invalid arguments\n");
    exit(2);
  }

  shmid=shm_open("OS",O_CREAT|O-O_RDWR,0666);
  ftruncate(shmid,1026);
  psm=mmap(0,1024,PROT_READ,MAP_SHARED,shmid,0);

  id=fork();
  if(id==0){
    //child proscess
    execlp("./prime","prime", argv[1],argv[2],NULL);
  }
  else{
    wait(NULL);
    printf("[parent]---- child finished execution\n");
    printf("printing the prime number\n");
    printf("[PARENT] --- %s\t",(char*)psm);
  }
  shm_unlink("OS");
}