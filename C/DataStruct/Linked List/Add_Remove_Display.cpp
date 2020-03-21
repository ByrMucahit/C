#include<stdio.h>
#include<stdlib.h>//because of use malloc
#include<string.h>
#include<ctype.h>
typedef struct list{
    char harf;
	int frekans;
	struct list *next;
}list;


// LISTEYE ELEMAN EKLE
list *ekle(list *iter, char b , int a){
		list * temp;
		temp=iter;
		list *ilk;

		/*
		else if(strcmp(c, b)<0){
		
			list *temp=(list*)malloc(sizeof(list));
			temp->next=ilk;
			temp->frekans=a;
			temp->harf=b;
			return temp;
		
			}*/  
			
			while(iter->next!=NULL/* && strcmp(iter->harf,b)>0*/){
				iter=iter->next;
			}
			iter->next=(list*)malloc(sizeof(list));
			iter=iter->next;
			iter->frekans=a;
			iter->harf=b;
			iter->next=NULL;
			return ilk;
		
		
		
			}
		
		


	

list *arama(list *r , char b ){
	list *gecici=r;
	while(gecici!=NULL){
		if(b==gecici->harf){
			return gecici;
							}
		else return NULL;
						}
		
	
								}


//LISTEYI EKRANA BASTIR
void bastir(list *r){
	list *gecici;
	gecici=r;
	if(gecici==NULL){
		printf("liste bos");
	}
	else{
		while(gecici!=NULL){
		printf("%4d--%c",gecici->frekans,gecici->harf);
		gecici=gecici->next;
							}
		}			
						}
//ELEMAN SIL
list *sil(list *r , char c){
	list *iter=r;
	list*temp;
	if(iter->harf==c){// silinecek karakter ilk elemanda ise
		temp=iter;
		iter=iter->next;
		free(temp);
		return iter;
	}
	while(iter->next!=NULL && iter ->next->harf!=c){// eðer sondaki veya aradaki elemanlardan biri silinecekse
		iter=iter->next;
	}
	if(iter->next==NULL){//silinecek eleman yoksa
		printf("sayi bulunamadi");
		return r;
		
	}
	temp=iter->next;
	iter->next=iter->next->next;
	free(temp);
	return iter;
	
}



int main(){
	//dosya okuma
	
	FILE *fp;
	fp=fopen("veri.txt","r");
	if(fp==NULL){
		printf("Dosya acilamadi");
		return 0;
	}

list *temp=NULL;
list *ilk;
char d;
char m;
int i;
int r;
list * iter;
while(!feof(fp)){
		if(temp==NULL ){
				
			//baðýl list boþsa 
			fscanf(fp,"%c",&d);
			temp=(list*)malloc(sizeof(list));
			temp->frekans=0;
			temp->harf=d;
			temp->next=NULL;
			printf("ilk elemaný ekleme isleminiz basarili");
			ilk=temp;
			iter=temp;				
		}
		
	else if(i< 12){
	fscanf(fp,"%c",&d);
		if(d!=','){
		temp=ekle(temp,d, 0);
	
		}
}
	

	 else if(i>=12 ){
		fscanf(fp,"%d",&r);
		if(d!=','){
		
		iter->frekans=r;
		iter=iter->next;

}
}
	



//islem baslangýcý	
	list * root=temp;
	list *kontrol;
while(1){
	int a;
	printf("\nyapmak istediðiniz islemi seciniz? :\n1. eleman ekleme, \n2. eleman arama ,\n3. eleman silme,\n4. elemanlari gor,\n5. exit\n");
	scanf("%d",&a);

	if(a==1){
		int k ; 
		char b;
		printf("istediginiz harfi giriniz...");
		scanf("\n%c",&b);
		printf("istediginiz sayi giriniz...");
		scanf("\n%d",&k);
		printf("\n...Girdiginiz karakter kontrol edliyor...");
		kontrol=arama(root,b);
		
		
	
		if(kontrol!=NULL){
			printf("\naradiginiz harf vardýr ve %c'dir\n",kontrol->harf);
			
		}
		else {
		printf("\nGirdiginiz karakter daha once girilmemis ,simdi ekliyoruz\n ");	
		
		root=ekle(root , b , k);
		printf("\n---basariyla eklendi---");
	}
		
	}
	else if(a==2){
		char b;
		
		printf("aranacak harfi giriniz...");
		scanf("\n%c",&b);
		root=arama(root,b);
		if(root!=NULL){
			printf("\naradiginiz harf vardýr ve %c'dir\n",root->harf);
			printf("\n EKLEME YAPAMIYORUZ UZGUNUZ");
			
		}
		else printf("naradiginiz eleman yoktur\n");
	}
	else if(a==3){
		char c;
		printf("lütfen silmek istediginiz karakteri giriniz:");
		scanf("\n%c",&c);
		root=sil(root,c);
		printf("%c karkateri silinmistir",root->harf);
		
	}
	else if(a==4){
		bastir(root);	
		}
	else if(a==5){
		printf("hoscakalin",a);
		return 0;
}
}
fclose(fp);	
	return 0;
	
	}
}
