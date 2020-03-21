
#include<stdio.h>
#include<stdlib.h>
struct node{// girdiler burada belirlenir
	int x;
	node *next;
	node *prev;
};
node *sil(node *r , int x){
	node *temp;
	node *iter=r;
	if(r->x==x){// eðer ilk eleman silinecekse
		temp=r;
		r=r->next;
		free(temp);
		return r;
		
	}
	while(iter->next!=NULL && iter->next->x!=x){
		iter=iter->next;//eðer sondaki eleman yada aradaki elemanlardan birisi silinecekse
	}
	if(iter->next==NULL){//eðer silinecek sayi yoksa
		printf("sayi bulunamadi");
		return r;
	}
	temp=iter->next;//aradaki veya sondaki eleman bulununca bu iþlem yapýlýr.
	iter->next=iter->next->next;
	free(temp);
	if(iter->next!=NULL)
	iter->next->prev=iter;
	return r;
	 
	}

void bastir(node *r){//pointer NULL'ý görene kadar bastirir.
	while(r!=NULL){
		printf("%4d",r->x);
		r=r->next;
	}
	printf("\n");
}
node *siraliekle(node *r , int x){//sirali eklerken kullanýrýz
	if(r==NULL){
		r=(node*)malloc(sizeof(node));
		r->next=NULL;
		r->prev=NULL;
		r->x=x;
		return r;
	}
	if(r->x > x){//eðer ilk elemandan önce eleman eklemek istersek.
		node *temp=(node*)malloc(sizeof(node));
		temp->x=x;
		temp->next=r;
		temp->prev=temp;
		return temp;
	}
	node *iter=r;
	while(iter->next!=NULL && iter->next->x < x ){
		iter=iter->next;// araya yada sona ekleme durumu
	}
	node *temp=(node*)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->prev=iter;
	if(temp->next!=NULL)
	temp->next->prev=temp;
	temp->x=x;
	return r;
}
int main(){
	node *r=NULL;
	r=siraliekle(r , 450);
	r=siraliekle(r , 600);
	r=siraliekle(r , 40);
	r=siraliekle(r , 75);
	r=siraliekle(r , 80);
	bastir(r);
	r=sil(r,600);
	bastir(r);
	r=sil(r,10);
	bastir(r);
	return 0;
	
		
}
