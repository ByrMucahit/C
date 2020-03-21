#include<stdio.h>
#include<stdlib.h>
struct dugum{
	int x;
	struct dugum *sonra;
};
void ekle(dugum *ilk,int a){
	while(ilk->sonra!=NULL){
		ilk=ilk->sonra;
	}
	ilk->sonra=(dugum*)malloc(sizeof(dugum));
	ilk=ilk->sonra;
	ilk->x=a;
	ilk->sonra=NULL;
}
void bastir(dugum *r){
	while(r!=NULL){
		printf("%4d",r->x);
		r=r->sonra;
	}
}
int main(){
	dugum *p;
	p=(dugum*)malloc(sizeof(dugum));
	p->x=200;
	p->sonra=NULL;
	
	for(int i =0;i<5;i++){
		ekle(p,i*10);
	}
	
		bastir(p);
		dugum *iter=p;
		for(int i=0;i<3;i++){
			iter=iter->sonra;
		}
		dugum *temp=(dugum*)malloc(sizeof(dugum));
		temp->sonra=iter->sonra;
		iter->sonra=temp;
		temp->x=25;
		
		bastir(temp);
		
		return 0;
}
