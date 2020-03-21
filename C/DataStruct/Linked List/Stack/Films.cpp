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
	if(iter==NULL){ 	//e�er top de�erimiz -1 d�nerse y���n yap�m�z�n bo� oldu�unu anl�yoruz.
		printf("----Yigin yapisi bos----\n"); 
		iter=(input*)malloc(sizeof(input));	// tek y�nl� ba��l listemiz ile yer a��yoruz ver next'ini bo� olarak g�steriyoruz.
		iter->next=NULL;
	}
		int i;
		for(i=0;i<size;i++){
		
	
		iter->film[i]=film[i];
	//	printf("%c",iter->film[i]);
		}//printf("%.1f\n",puan);			// Yap�m�zda 2 �ye bulunmaktad�r(film , puan) burada 2 veriyie yap�m�za yerle�tiriyoruz.
		iter->top++;
		iter->puan=puan;
		input *yeni=(input*)malloc(sizeof(input));// iter'in d���nda yeni bir pointer belirleyerek  eleman eklenmesi i�in 2. alan�m�z� olu�turuyoruz .
		yeni->next=iter;	// yeni ekledi�imiz alan �ste oldu�unu varsayarak 2.ye ba�l�yoruz.
		iter=yeni;		// �uan Yeni a�t���m�z'� iter yap�yoruz.
	
	
} 

char  Cikar(){
	if(iter->next==NULL)
	return -1;	// E�erki top de�erimiz -1 olursa , ��karma i�lemi ger�ekle�emeyece�i i�in i�lem burda durur
	
		char x= iter->next->film[iter->top];	// -1 de�eri d�nmedi�i en �stteki ��karaca��m�z veri.  
		input *temp=iter;			// Daha pratik bir silme i�lemi i�in ge�ici de�i�kene at�l�r .
		iter=iter->next;			// ��karma i�lemi yap�ld�ktan sonra ��kar�lan eleman�'n�n bir �nceki eleman� bir sonraki eleman�na ba�lan�r.
		free(temp);
		//printf("%s",x);			// free fonksiyonu ile haf�zdan silinir.
		iter->top--;
		return x;					// sildi�imiz datay� d�nd�r�yoruz.
		
}

void ekrana_bastir(int size){
	printf("Yigin Elemanlar�:\n");
	input *temp=iter;	// ba�taki eleman� kaybetmemek i�in tekrardan farkl� bir de�i�kene at�yoruz.
	int j;
	for(j=0;j<size;j++){	// temp de�i�keni NULL de�erini g�rene kadar ilerlemeye devam edecek.
		printf("%c",temp->film[j]); // okunan elemanlar� bast�r�yoruz.
		printf("%.1f",temp->puan)	;// eleman� bast�rd�ktan sonra ilerleme i�lemini yap�yoruz.
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
		printf("Your File could not be found "); // E�er ki dosyam�z bulunamazsa NULL de�eri d�ner ve i�lem devam etmez.
	}
	else{
	
		
		printf("Your File could be opened\n");	// fp adl� pointer�m�z�n de�eri Null d�nmedi�i takdirde  "Filmler.txt" den  veri okunmaktad�r. 
		while(!feof(fp)){
		
			while(1){		// �stedi�imiz �artlar� sa�lamad��� takdirde ��kmak �zere sonsuz d�ng�ye soktuk.	
				temp=fgetc(fp);	// getch() fonksiyonu ile karakter okuyoruz ve d�ng� boyunca karakter okumaya devam edecek.
		
				if(temp==','){// okuyaca��m�z dosyada "," karakteri g�r�rse sonsuz d�ng�den ��kacak yani o sat�rda �imdilik o d�ng� sonlanacak.
				break;
								}
				dizi[m]=temp;//d�ng�den ��kmad��� takdirde okudu�umuz veriler diziye eklenecek
				m++;
					}
				
				fscanf(fp,"%f",&temp1);// d�ng�den ��kt���nda art�k char karakterlerle i�imiz bitiyor ve ondal�kl� say�lar kar��m�z� ��k�yor onu da scanf fonksiyonu ile float tipinde okuyoruz.
			
		
			
					int i;
				/*	for(i=0;i<m;i++){
					printf("%c",dizi[i]);
					}
					
					printf("--->%.1f\n",temp1);
					*/
					
					Ekle(temp1,dizi,m);
					
					m=0;						// O sat�rda i�lemimiz bitince diziyi s�f�rl�yoruz.
					continue;
					
					
						}
				
				//	Cikar();
						}
						
						
						
						
						
							}
								
			
	
	
			

			
			
	


	
			
	


		
		
		
	


