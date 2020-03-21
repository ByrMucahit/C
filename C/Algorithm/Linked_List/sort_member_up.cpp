#include<stdio.h>
#include<stdlib.h>
struct dugum{
	int x;
	struct dugum *sonra;
};
void bastir(dugum *r){
	while(r!=NULL){
		printf("%4d",r->x);
		r=r->sonra;
	}
}
dugum *eklesirali(dugum *r, int x){
	if(r==NULL){
		r=(dugum*)malloc(sizeof(dugum));
		r->sonra=NULL;
		r->x=x;
		return r;
	}
	else if(r->x > x){
			dugum *temp=(dugum*)malloc(sizeof(dugum));
			temp->sonra=r;
			temp->x=x;
			return temp;
		}
		dugum *iter=r;
	while(iter->sonra !=NULL && iter->sonra->x < x){
		iter=iter->sonra;	
	}
	dugum *temp=(dugum*)malloc(sizeof(dugum));
			temp->sonra=iter->sonra;
			iter->sonra=temp;
			temp->x=x;
			return r;
}
int main(){
	dugum *p=NULL;
	p=eklesirali(p,40);
	p=eklesirali(p,450);
	p=eklesirali(p,20);
	p=eklesirali(p,500);
	bastir(p);
	return 0;
	
}
