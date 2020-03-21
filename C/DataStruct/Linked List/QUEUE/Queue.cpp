#include<stdio.h>
#define KBoyut 100

typedef struct tail{
	
	int son; // number of member
	int member[KBoyut];
}tails;

tails New_Tail;

int Tails_full(){
	if(New_Tail.son=KBoyut-1) return -1;// if function equals the -1 , program get that is full.
	else return 1;// this means that is we can add the something
	}

void main1(){
	New_Tail.son=-1; // firtly tail is empty.
	
}
int Tail_Add(int add){
	if(Tails_full()==-1){// I have to chech out that is full or empty.
	printf("you can't add anything because of tail is full. ");
	return -1;
						}
	else {
		New_Tail.son++;
		New_Tail.member[New_Tail.son]=add;
		return add;
	}
}
	int Tail_empty(){
		if(New_Tail.son==-1) return -1;
		else return 0;
	}
	
int remove_queue(){
	int remove; // it is temp for remove to member
	if(Tail_empty()==-1){
		
		printf("you can not remove anything because of queue is empty");
		
							}
	else{
		remove=New_Tail.member[0];
		int i;
		for(i=1;i<New_Tail.son;i++){
			New_Tail.member[i-1]=New_Tail.member[i];
			New_Tail.son--;
			return remove;
		}
	}
}



