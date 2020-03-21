#include<stdio.h>
#include<stdlib.h>




typedef struct inputStack{
	
	struct inputStack *next;
	int top=-1 ;
	char film[100];
	float puan;
	
}input;


input *iter=NULL;

typedef struct tmpStack{
	struct tempStack *next;
	int top_temp;
	int member_temp[100];
}tmp;

void Ekle(float puan , char film[],int size ){
	if(iter==NULL){ 	//eðer top deðerimiz -1 dönerse yýðýn yapýmýzýn boþ olduðunu anlýyoruz.
		printf("----Yigin yapisi bos----\n"); 
		iter=(input*)malloc(sizeof(input));	// tek yönlü baðýl listemiz ile yer açýyoruz ver next'ini boþ olarak gösteriyoruz.
		iter->next=NULL;
	}
		int i;
		for(i=0;i<size;i++){
		
	
		iter->film[i]=film[i];
	//	printf("%c",iter->film[i]);
		}//printf("%.1f\n",puan);			// Yapýmýzda 2 üye bulunmaktadýr(film , puan) burada 2 veriyie yapýmýza yerleþtiriyoruz.
		iter->top++;
		iter->puan=puan;
		input *yeni=(input*)malloc(sizeof(input));// iter'in dýþýnda yeni bir pointer belirleyerek  eleman eklenmesi için 2. alanýmýzý oluþturuyoruz .
		yeni->next=iter;	// yeni eklediðimiz alan üste olduðunu varsayarak 2.ye baðlýyoruz.
		iter=yeni;		// Þuan Yeni açtýðýmýz'ý iter yapýyoruz.
	
	
} 

char  Cikar(){
	if(iter->next==NULL)
	return -1;	// Eðerki top deðerimiz -1 olursa , çýkarma iþlemi gerçekleþemeyeceði için iþlem burda durur
	
		char x= iter->next->film[iter->top];	// -1 deðeri dönmediði en üstteki çýkaracaðýmýz veri.  
		input *temp=iter;			// Daha pratik bir silme iþlemi için geçici deðiþkene atýlýr .
		iter=iter->next;			// çýkarma iþlemi yapýldýktan sonra çýkarýlan elemaný'nýn bir önceki elemaný bir sonraki elemanýna baðlanýr.
		free(temp);
		//printf("%s",x);			// free fonksiyonu ile hafýzdan silinir.
		iter->top--;
		return x;					// sildiðimiz datayý döndürüyoruz.
		
}

void ekrana_bastir(int size){
	printf("Yigin Elemanlarý:\n");
	input *temp=iter;	// baþtaki elemaný kaybetmemek için tekrardan farklý bir deðiþkene atýyoruz.
	int j;
	for(j=0;j<size;j++){	// temp deðiþkeni NULL deðerini görene kadar ilerlemeye devam edecek.
		printf("%c",temp->film[j]); // okunan elemanlarý bastýrýyoruz.
		printf("%.1f",temp->puan)	;// elemaný bastýrdýktan sonra ilerleme iþlemini yapýyoruz.
	}
	
}

int main(){
	FILE *fp;
	
	fp=fopen("Filmler.txt","r");
	char dizi[300];
	float puan[300];
	char temp;
	float temp1;
	int m;
	int n=0;
	char film;
	char dizi11[5]={'f','e','n','e','r'};
					

	if(fp==NULL)
	{
		printf("Your File could not be found "); // Eðer ki dosyamýz bulunamazsa NULL deðeri döner ve iþlem devam etmez.
	}
	else{
	
		
		printf("Your File could be opened\n");	// fp adlý pointerýmýzýn deðeri Null dönmediði takdirde  "Filmler.txt" den  veri okunmaktadýr. 
		while(!feof(fp)){
		
			while(1){		// Ýstediðimiz þartlarý saðlamadýðý takdirde çýkmak üzere sonsuz döngüye soktuk.	
				temp=fgetc(fp);	// getch() fonksiyonu ile karakter okuyoruz ve döngü boyunca karakter okumaya devam edecek.
		
				if(temp==','){// okuyacaðýmýz dosyada "," karakteri görürse sonsuz döngüden çýkacak yani o satýrda þimdilik o döngü sonlanacak.
				break;
								}
				dizi[m]=temp;//döngüden çýkmadýðý takdirde okuduðumuz veriler diziye eklenecek
				m++;
					}
				
				fscanf(fp,"%f",&temp1);// döngüden çýktýðýnda artýk char karakterlerle iþimiz bitiyor ve ondalýklý sayýlar karþýmýzý çýkýyor onu da scanf fonksiyonu ile float tipinde okuyoruz.
			
		
			
					int i;
				/*	for(i=0;i<m;i++){
					printf("%c",dizi[i]);
					}
					
					printf("--->%.1f\n",temp1);
					*/
					
					Ekle(temp1,dizi,m);
					
					m=0;						// O satýrda iþlemimiz bitince diziyi sýfýrlýyoruz.
					continue;
					
					
						}
				
				//	Cikar();
						}
						
						
						
						
						
							}
								
			
	
	
			

			
			
	


	
			
	


		
		
		
	


