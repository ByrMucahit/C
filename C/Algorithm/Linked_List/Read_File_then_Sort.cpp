#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node{
	int x;
	node *next;
	node *prev;
};
void bastir(node *r){
	while(r!=NULL){
		printf("%4d",r->x);
		r=r->next;
	}
	printf("\n");
}
node *siraliekle(node *r , int *x){
	if(r==NULL){
		r=(node*)malloc(sizeof(node));
		r->x=*(x);
		r->next=NULL;
		r->prev=NULL;
		return r;
	}
	if(r->x > *(x)) {
		node *temp=(node*)malloc(sizeof(node));
		temp->x=*(x);
		temp->next=r;
		temp->prev=temp;
		return temp;
	}
	node *iter=r;
	while(iter->next != NULL && iter->next->x < *(x)){
		iter=iter->next;
	}
	node *temp=(node*)malloc(sizeof(node));
	temp->next=iter->next;
	iter->next=temp;
	temp->prev=iter;
	if(temp->next !=NULL)
		temp->next->prev=temp;
	temp->x=*(x);
	return r;
}
int main(){
	srand(time(NULL));
	int *p,i,n;
	printf("kac adet sayi gireceksiniz belirtiniz:\n");	scanf("%d",&n);//kac adet sayi istiyorsan gir
	p=(int*)malloc(n*sizeof(int));
	FILE *fp=fopen("tamsayilar.txt","w");
	if(fp==NULL) printf("dosya açilamadi");
	for(i=0;i<n;i++){
	*(p+i)=rand()%100;// random olarak sayilari atadýk
	fprintf(fp,"%4d",*(p+i));//sayilari dosyaya yazdýrdýk
						}
	printf("tamsayilar.txt'e yazilan sayilar:\n");//yazdýrdýgýmýz sayilari bastiralim
	for(i=0;i<n;i++){
	printf("%4d",*(p+i));
						}

	fclose(fp);
	fp=fopen("tamsayilar.txt","r");
	if(fp==NULL) printf("\n---dosya bulunamadi---");
	printf("\n");
	for(i=0;i<=n;i++){
		fscanf(fp,"tamsayilar.txt",*(p+i));
		}
	printf("tamsayilar.txt dosyaysindan okunan sayilar:\n");
	for(i=0;i<=n;i++){//dosyadan okudugumuz sayilari tekrardan ekrana yazdýrdýk
		printf("%4d",*(p+i));
		
	}
	fclose(fp);
	node *root=NULL ;
	printf("\n\n\n");
	for(i=0;i<n;i++){
	
	root=siraliekle(root,(p+i));
		
	}
	printf("okunan sayilarin siralanmis hali :\n");

		bastir(root);
	
	return 0;	
}
