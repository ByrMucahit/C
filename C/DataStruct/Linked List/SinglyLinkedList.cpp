#include<stdio.h>
#include<stdlib.h>
typedef struct Single_List{
	int x;
	struct Single_List *next; 
}Single;

Single  *add(Single *r , int x){
	Single *first;
	if(r==NULL){
		r=(Single*)malloc(sizeof(Single));
		r->x=x;
		r->next=NULL;
		first=r;
		return r;
	}
	else{
		while(r->next!=NULL){
			r=r->next;
		}
		r=(Single*)malloc(sizeof(Single));
		r->x=x;
		r->next=NULL;
		return r;
	}
}
Single *Looking_For(Single *r , int x){
	Single *temp;
	temp=r;
	while(temp!=NULL){
		if(temp->x==x){
			printf(" link list has a %d ",temp->x);
		}
		else{
			printf("no ,Link has  not ");
		}
	}
	
}

void List(Single *r){
	while(r!=NULL){
		printf("%4d",r->x);
		r=r->next;
	}
	printf("\n");
}

Single *remove(Single *r , int x){
	Single *temp;
	Single *iter=r;
	if(iter->x==x){
		temp=iter;
		iter=iter->next;
		free(temp);
		return iter;
	}
	while(iter->next!=NULL && iter->next->x!=x){
		iter=iter->next;
	}
	if(iter->next==NULL){
		printf("Link List has not member");
		return r;
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	return r;
}


int  main(){
	Single *a =NULL;
	int x=10;
	a=add(a,x);
	List(a);
	a=remove(a,x);
	List(a);
	
}

