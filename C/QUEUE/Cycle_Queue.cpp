#include<stdio.h>
#define KBoyut 100

typedef struct Queue{
	int last; 	// When we add member to Queue , it is use as varaible
	int head; 	// when we remove member from Queue ,we use it.
	int number;	//it is include the number of member
	int member[KBoyut];
}queue;

queue New_Queue;

void defin(){
	 New_Queue.last=-1;
}

int Queue_Full(){
	if(New_Queue.last==KBoyut){
		return -1;
			}
	else return 0;
}
int Add_Queue(int add){
	if(Queue_Full()==-1){
		printf("Struct of Queue is full , it can not be add");
	}
	else {// In case of it can be add
	New_Queue.last=(New_Queue.last+1)%KBoyut;
	New_Queue.member[New_Queue.last]=add;
	New_Queue.number++;
	return 1;

return 0;

}

