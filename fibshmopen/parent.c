#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/mman.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argc, char * argv[]){
  if(argc<1){
    printf("No arguments passed !! \n");
    exit(2);
  }

  int shmid,id;
  void *psm;

  shmid=shm_open("os",O_CREAT,0666);
  /*Parameters:
  name: The first parameter specifies the name of the shared-memory object. 
  Processes that wish to access this shared memory must refer to the 
  object by this name.

  O_CREAT | O_RDWR : The subsequent parameters specify that the shared-memory 
  object is to be created if it does not yet exist (O_CREAT) and that the object is 
  open for reading and writing (O_RDWR).

  The last parameter establishes the directory permissions of the 
  shared-memory object.*/

  printf("PARENT -- ID of shared memory >> %d\n", shmid);
  ftruncate(shmid,1024);
  //The second argument is the size you want to truncate the file to. Use 0 if you want to truncate it completely
  psm = mmap(0, 1024, PROT_WRITE, MAP_SHARED, shmid, 0);
  /*1.0
  2. length:
  This is the number of bytes which to be mapped.3. protect:
  This argument is used to control what kind of access is permitted.
  4.flagsThis argument is used to control the nature of the map. Following are some common values of the flags:
  MAP_SHARED: This flag is used to share the mapping with all other processes, which are mapped to this object.
  Changes made to the mapping region will be written back to the file.
  5. filedes:
  This is the file descriptor which has to be mapped.
  6.0*/
  id=fork();
  if(id==0){
    // CHILD
    execlp("./fib","fib",argv[1],NULL);
  }
  else{
    wait(NULL);
    printf("PARENT -- Child finished execution\n");
    printf("PARENT -- Printing Fibonacci >> \n");
    printf("parent ... %s\n",(char*)psm);
  }
  shm_unlink("OS");
}
    