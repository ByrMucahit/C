#include<stdio.h>
#include<stdlib.h>
struct dugum{
	int x;
	struct dugum *next;
	};
dugum *siraliekleme(dugum *p , int x){
	if(p->x > x){
		dugum *temp=(dugum*)malloc(sizeof(dugum));
		temp->next=p;
		temp->x=x;
		dugum *iter=p;
		while(iter->next!=p){
			iter=iter->next;
		}
		iter->next=temp;
		return temp;
	}
	dugum *iter=p;
	while(iter->next!=p && iter->next->x < x){
		iter=iter->next;
	}
	dugum *temp=(dugum*)malloc(sizeof(dugum));
	temp->x=x;
	temp->next=iter->next;
	return p;
	
	
	}
dugum *sil(dugum *r,int x){
	dugum *iter=r;
	if(iter->x==x){
		while(iter->next!=r){
			iter=iter->next;
		}
		iter->next=r->next;
		free(r);
		return iter->next;
	}
	while(iter->next!=r && iter->next->x !=x){
		iter=iter->next;
	}
	if(iter->next==r){
		printf("sayi bulunamadi...");
		return r;
	}
	dugum *temp = iter->next;
	iter->next=iter->next->next;
	free(temp);
	return r;
	
}
void bastir(dugum *root){	// tekrardan root'a esit olana kadar hepsini bastirir. 
	dugum *iter=root;
	printf("%d",iter->x);
	iter=iter->next;
	while(iter!=root){
		printf("%4d",iter->x);
		iter=iter->next;
	}
	printf("\n");
}
void ekle(dugum *r,int x){	// atayacaginiz sayiyi sona ekler.
		dugum *iter=r;
		while(iter->next!=r){
		iter=iter->next;
	}
	iter->next=(dugum*)malloc(sizeof(dugum));
	iter=iter->next;
	iter->x=x;
	iter->next=r;
}
	int main(){
		dugum *p;
		p=(dugum*)malloc(sizeof(dugum));
		p->next=p;
		ekle(p,40);
		ekle(p,30);
		ekle(p,25);
		ekle(p,60);
		p=sil(p,60);
		p=sil(p,80);
		
		printf("\n\n\n");
		bastir(p);
		p=siraliekleme(p,40);
		p=siraliekleme(p,30);
		p=siraliekleme(p,25);
		p=siraliekleme(p,60);
		bastir(p);
		return 0;	
		}
