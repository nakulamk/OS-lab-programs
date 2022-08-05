#include<stdio.h>
#include<stdlib.h>

int mutex=1;
int empty=3;
int full=0;
int x=0;
int wait(int s){
  return --s;
}
int siganl(int s){
  return ++s;
}
void producer(){
  mutex=wait(mutex);
  full=siganl(full);
  empty=wait(empty);
  x++;
  printf("the producer has produced the item %d\n",x);
  printf("The buffer has %d items in it\n",x);
  mutex=siganl(mutex);

}
void consumer(){
  mutex=wait(mutex);
  full=wait(full);
  empty=siganl(empty);
  x--;
  printf("the comsumer  has consumed the item %d\n",x);
  printf("The buffer has %d items in it\n",x);
  mutex=siganl(mutex);

}
void main(){
  int n;
  while(1){
    printf("1.producer\n2.consumer\n3.exit\n");
    printf("enter your choice>>");
    scanf("%d",&n);
    switch(n){
      case 1:{
        if(mutex==1 && empty!=0){
          producer();
        }
        else{
          printf("The buffer is full or the buffer is aquired by consumer!!");
        }
        break;
      }
      case 2:{
        if(mutex==1 && full!=0){
          consumer();
        }
        else{
          printf("The buffer is full or the buffer is aquired by producer!!");
        }
        break;
      }
      case 3:{
        exit(1);
      }
    }
  }
}