#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/shm.h>

void main(int argc,char *argv[]){
  int shmid,id;
  void *psm;//genric pointer which will store any address
  if(argc<1){
    printf("NO agrgument is passsed !!!\n");
    exit(1);
  }
  shmid=shmget((key_t)1111,1024,0666|IPC_CREAT);
  //shmget it will create a shared memory for parnent and child
  //syntx shmget(unique_id,storage_capacity,permission rwx,i|IPC_CREATE)
  printf("the ID of the shared memory is %d\n",shmid);

  psm=shmat(shmid,NULL,0666);
  //shmat will attach the shared memo to the psm pointer;
  printf("proscess attached at %p\n",psm);

  id=fork();
  if(id==0){
    //CHILD PROSCESS
    execlp("./fib","fib",argv[1],NULL);
    //this will call the child to genrate and print the fib number 
    //in the shared memory
  }
  else{
    //PARENT
    wait(NULL);
    printf("PARENT -- Child completed execution\n");
    printf("PARENT -- Priting fibonacci >> \n");
    printf("PARENT  %s\n",(char*)psm);//it willl typecast the int array
    //to char and then the parent will print the elements which is 
    //in the shared memory;
    shmdt(psm);
    // shmdt will detach the memory from pointer;
  }

}