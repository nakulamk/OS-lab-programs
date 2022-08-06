#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<unistd.h>
#include<string.h>

void(int argc,char* argv[]){
  int shmid,id,count;
  void *psm;
  int min,max;
  shmid=shm_open("OS",O_RDWR,0666);
  ftruncate(shmid,1026);
  printf("CHILD -- ID of shared memory >> %d\n", shmid);
  psm=mmap(0,1026,PROT_WRITE,MAP_SHARED,shmid,0);
  //here we are typecasting the character to integer;
  min=atoi(argv[1]);
  max=atoi(argv[2]);

  printf("CHILD -- Printing prime nubmers within the range >> \n");

  //prime logic
  for(int i=min;i<=max;i++){
    count=0;
    for(int j=1;j<=i;j++){
      if(i%j==0){
        count++;
      }
    }
    if(count==2){
      sprintf(psm,"%d",i);
      psm+=strlen(psm);
      printf("%d\t",i);
    }
    
  }
  printf("\n\n");
}