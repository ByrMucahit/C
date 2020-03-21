#include<stdio.h>
#include<stdlib.h>

typedef struct Event{
	
	int x;
	struct Event *prev;
	struct Event *next;
}event;

event *remove(event *r  , int x){
	event *temp;
	event *iter=r;
	if(iter->x==x){
		temp=iter;
		iter->prev=NULL;
		iter->next=iter->next->next;
		free(temp);
		return r;
	}
	while(iter->next!=NULL && iter->next->x!=x){
		iter=iter->next;
	}
	if(iter->next==NULL){
		printf("Link has not that you search");
		return r;
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	if(iter->next!=NULL){
		iter->next->prev=iter;
	}
	return r;
}

void print(event *r){
	while(r!=NULL){
		printf("%4d",r->x);
		r=r->next;
	}
	printf("\n");
}

event *add(event *r , int x){
	if(r==NULL){
		r=(event*)malloc(sizeof(event));
		r->next=NULL;
		r->prev=NULL;
		r->x=x;
		return r;
	}
	else {
		event *iter;
		iter=r;
		while(iter->next!=NULL){
			iter=iter->next;
		}
		iter->next=(event*)malloc(sizeof(event));
		iter->next->next=NULL;
		iter->next->prev=r;
		iter->next->x=x;
		return r;
	}
}

int main(){
	event *r=NULL;
	int x=10;
	
	r=add(r,x);
	print(r);
	r=add(r,2*x);
	r=add(r,4*x);
	r=add(r,6*x);
	r=add(r,8*x);	
	print(r);
	r=remove(r,60);
	print(r);
}
