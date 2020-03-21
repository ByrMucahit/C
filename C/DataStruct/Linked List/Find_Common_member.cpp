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
		r->next=(Single*)malloc(sizeof(Single));
		r->next->x=x;
		r->next->next=NULL;
		return first;
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

void find_common_member(Single *ilk1 , Single *ilk2){
		Single *iter=ilk2;
	while(ilk1!=NULL ){
			while(ilk2!=NULL){
				if(ilk1->x == ilk2->x){
					printf("\n%d",ilk2->x);
					
				}
			
				ilk2=ilk2->next;		
		
			}
			
		ilk2=iter;	 	
		
		ilk1=ilk1->next;
		
	}
		
		 
		
	
}

int  main(){
	Single *a =NULL;
	Single *b =NULL;
	
	a=add(a,40);
	a=add(a,50);
	a=add(a,60);
	a=add(a,70);
	a=add(a,80);	
	
	List(a);
	
	b=add(b,10);
	b=add(b,20);
	b=add(b,30);
	b=add(b,40);
	b=add(b,50);
	List(b);
	find_common_member(a,b);
}

