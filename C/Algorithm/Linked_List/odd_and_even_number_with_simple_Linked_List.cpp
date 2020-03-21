#include<stdio.h>
#include<stdlib.h>
struct node{
	int x;
	node *next;
};
node *ekle(node *r , int x){
	if(r==NULL){
		r=(node*)malloc(sizeof(node));
		r->x=x;
		r->next=NULL;
		return r;
		
	}
	node *iter=r;
	while(iter->next!=NULL){
		iter=iter->next;
		
	}
	iter->next=(node*)malloc(sizeof(node));
	iter=iter->next;
	iter->x=x;
	iter->next=NULL;
	
	return r;
	
}
void bastir(node *p){
	while(p!=NULL){
		printf("%4d",p->x);
		p=p->next;
	}
	printf("\n");
}
int main(){
	int i,dizi[100];
	FILE *fp;
	node *p=NULL,*t=NULL;
	fp=fopen("final.txt","w");
	if(fp==NULL)
		printf("dosya acilamadi.");
		
		else{
			for ( i=0;i<10;i++)
			fprintf(fp,"%d\n",i);
								
		}
		fclose(fp);
		fp=fopen("final.txt","r");
		if(fp==NULL)
			printf("dosya bulunamadi.");
		
		else{
			while(!feof(fp)){
				if(ferror(fp))
					printf("dosya okunamadi");
				else
					fscanf(fp,"%d\n",& i);
					
					
					if(i%2==0)
					t=ekle(t,i);
					else
					p=ekle(p,i);
				
				}
			
			}
		
			fclose(fp);
		
			printf("cift sayilar:\n");
				bastir(t);
				printf("\n tek sayilar \n");
				bastir(p);
		
		return 0;
}
