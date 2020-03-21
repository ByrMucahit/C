#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
 struct dugum{
	int x;
	struct dugum *sonra;
	
};
void ekle(dugum *r,int x){
	while(r->sonra!=NULL){
		r=r->sonra;
	}
	r->sonra=(dugum*)malloc(sizeof(dugum));
	r=r->sonra;
	r->x=x;
	r->sonra=NULL;
}
void bastir(dugum *r){
	while(r!=NULL){
	printf("%4d",r->x);
	r=r->sonra;
}
}
int main(){
	int i ,n,a;
	dugum *p;
	printf("kac adet sayi giriceksiniz belirtiniz:\n");
	scanf("%d",&n);
	p=(dugum*)malloc(sizeof(dugum));
	p->x=500;
	p->sonra=NULL;
	dugum *tasi=p;
	for(i=0;i<n;i++){
	ekle(tasi,i*10);
	
	}


	
	printf("\n");
	bastir(p);
	dugum *carry=p;
	for(i=0;i<2;i++){
		carry=carry->sonra;
	}
	dugum *temp=(dugum*)malloc(sizeof(dugum*));
	temp->sonra=carry->sonra;
	carry->sonra=temp;
	temp->x=100;
	bastir(p);

			
			

	
	
	return 0;
}
