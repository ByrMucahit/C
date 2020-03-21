#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int x;
	node *next;
};
node *siraliekle(node *p , int x){
	if(p==NULL){
		p=(node*)malloc(sizeof(node));
		p->x=x;
		p->next=NULL;
		return p;
	}
	if(p->x > x){
		node *temp=(node*)malloc(sizeof(node));
		temp->x=x;
		temp->next=p->next;
		p->next=temp;
		return temp;
		
	}
	node *iter=p;
	while(iter->next!=NULL && iter->next->x < x){
		iter=iter->next;
	}
	node *temp=(node*)malloc(sizeof(node));
	temp->x=x;
	temp->next=iter->next;
	iter->next=temp;
	return p;
}
void bastir(node *p){
	node *iter=p;
	while(iter!=NULL){
		printf("%5d",iter->x);
		iter=iter->next;
	}
	printf("\n");
}
int main(){
	node *p=NULL;
	int a;
	char kr;
	do{
		printf("lütfen int veri tipinde sayi giriniz:\n");
		scanf("%d",&a);
		p=siraliekle(p,a);
		printf("sayi girmeye devam etmek istiyor musunuz?(e/h)\n");
		kr=getch();
		if(kr=='h' || kr=='H') break;
		
	}while(1);
	printf("girdiginz sayilarin siralanmis hali:\n");
	bastir(p);
	return 0;
}
