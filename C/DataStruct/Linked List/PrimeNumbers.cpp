#include<stdio.h>
#define KBoyut 100

typedef struct queue{
	int las;
	int member[KBoyut];
	
}queues;

queues new_queue;



int queue_full_check(){
	if(new_queue.las==KBoyut-1){	// if queue stack is full , it returns the -1 .
		return -1;
	}
	else return 1; // if return the without -1 , we can get the queue stack is empty so we can add something.
}

int add_queue(int add){
	if(queue_full_check()==-1){
		printf("You can't add anything'");
		return -1;
	}
	else {
		new_queue.las++;
		new_queue.member[new_queue.las]=add;
		return add;
	}
}

int remove_queue_check(){
	if(new_queue.las==-1){
		return -1;
	}
	else return 0;
}
int remove_queue(){
	if(remove_queue_check()==-1){
		return -1;
	}
	else {
		int remove = new_queue.member[0];
		for(int i=1;i<new_queue.las;i++){
			new_queue.member[i-1]=new_queue.member[i];
		}
		new_queue.las--;
		return remove;
	}
}


int main(){
	int sayac=0;
	new_queue.las=-1;
	for (int i=0;i<10;i++){
		
		for(int j=1;j<(i/2);j++){
			if(i % j ==0 || i<2){
			
					
					printf("\n%d is not prine numbers",i);
					
					}
					else if (i%j!=0){
						int a= add_queue(i);
						printf("\n%d was added",a);
						sayac++;
						
					}
			}
			
			}
		
	



	for ( int i=0;i<sayac;i++){
		printf("\n--->%d",new_queue.member[i]);
		
	}
	int b= remove_queue();
	printf("\n%d was removed",b);
	sayac--;
	for ( int i=0;i<sayac;i++){
		printf("\n--->%d",new_queue.member[i]);
		
	}
	return 0;

}
