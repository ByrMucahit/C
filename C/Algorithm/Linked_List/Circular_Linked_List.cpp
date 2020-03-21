#include<stdio.h>
#include<stdlib.h>
struct dugum{
	int x;
	struct dugum *sonra;
};
void bastir(dugum *r){
	
	dugum *iter = r;
	printf("%d",iter->x);
	iter=iter->sonra;
	while(iter!=r){
		printf("%4d",iter->x);
		iter=iter->sonra;
	}
	printf("\n");
}
dugum *eklesirali(dugum *r, int x){
	if(r==NULL){
		r=(dugum*)malloc(sizeof(dugum));
		r->sonra=r;
		r->x=x;
		return r;
	}
	if(r->x > x){
			dugum *temp=(dugum*)malloc(sizeof(dugum));
			temp->sonra=r;
			temp->x=x;
			dugum *iter=r;
				while(iter->sonra!=r){
					iter=iter->sonra;}
			iter->sonra=temp;
			return temp;
		}
		dugum *iter=r;
	while(iter->sonra !=r && iter->sonra->x < x){
		iter=iter->sonra;	
	}
	dugum *temp=(dugum*)malloc(sizeof(dugum));
			temp->sonra=iter->sonra;
			iter->sonra=temp;
			temp->x=x;
			return r;
}
dugum *sil(dugum *r,int x){
	dugum *temp;
	dugum *iter=r;
	if(iter->x==x){
		while(iter->sonra!=r){
			iter=iter->sonra;
		}
		iter->sonra=r->sonra;
		free(r);
		return iter->sonra;		
	}
	while(iter->sonra!=r && iter->sonra->x!=x){
		iter=iter->sonra;
		
	}
	if(iter->sonra==r){
		printf("sayi bulunamadi");
		return r;
	}
	temp=iter->sonra;
	iter->sonra=iter->sonra->sonra;
	free(temp);
	return r;
	}
int main(){
	dugum *p=NULL;
	p=eklesirali(p,40);
	p=eklesirali(p,450);
	p=eklesirali(p,20);
	p=eklesirali(p,60);
	p=eklesirali(p,80);
	p=sil(p,20);
	bastir(p);
	p=sil(p,10);
	bastir(p);
	p=eklesirali(p,500);
	
	bastir(p);
	return 0;
}
