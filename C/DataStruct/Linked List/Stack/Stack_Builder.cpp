#include<stdio.h>
#include<stdlib.h>




typedef struct inputStack{
	
	struct inputStack *next;
	char film[100];
	float puan;
	
}input;


input *iter=NULL;

typedef struct tmpStack{
	struct inputStack *next;
	char film[100];
	float puan;
	
}tmp;


input  *Cikar(){
	input *temp=iter;
	if(temp->next==NULL);
	
		// E�erki top de�erimiz -1 olursa , ��karma i�lemi ger�ekle�emeyece�i i�in i�lem burda durur
	else{
	
	//	input * x= iter->next;	// -1 de�eri d�nmedi�i en �stteki ��karaca��m�z veri.  
		input *temp=iter->next;			// Daha pratik bir silme i�lemi i�in ge�ici de�i�kene at�l�r .
	//	iter=iter->next;			// ��karma i�lemi yap�ld�ktan sonra ��kar�lan eleman�'n�n bir �nceki eleman� bir sonraki eleman�na ba�lan�r.
	//	printf("%s'i'Cikarma islemi basar�l�\n",temp->film);
		free(temp);
		//printf("%s",x);			// free fonksiyonu ile haf�zdan silinir.
		
						// sildi�imiz datay� d�nd�r�yoruz.
}
		return temp;
}



void ekrana_bastir(int size ){
	
	input *temp=iter->next;	// ba�taki eleman� kaybetmemek i�in tekrardan farkl� bir de�i�kene at�yoruz.
	int j;
		if(temp!=NULL){
		for(j=0;j<size;j++)
		printf("%c",temp->film[j]); 
		printf("-->%.1f",temp->puan);	// eleman� bast�rd�ktan sonra ilerleme i�lemini yap�yoruz.
	}
		
			
}


void sortStack(){
	
	input *t;
	
	t=Cikar();
	printf("%.1f",t->puan);
}

void Ekle(float puan , char film[],int size ){
	if(iter==NULL){ 	//e�er top de�erimiz -1 d�nerse y���n yap�m�z�n bo� oldu�unu anl�yoruz.
		
		iter=(input*)malloc(sizeof(input));	// tek y�nl� ba��l listemiz ile yer a��yoruz ver next'ini bo� olarak g�steriyoruz.
		iter->next=NULL;
		printf("----ba�ar�yla eklendi----\n"); 
	}
		int i;
		for(i=0;i<size;i++){
		
	
		iter->film[i]=film[i];
	//	printf("%c",iter->film[i]);
		
		}
		
	//	printf("-->%.1f\n",puan);			// Yap�m�zda 2 �ye bulunmaktad�r(film , puan) burada 2 veriyie yap�m�za yerle�tiriyoruz.
		
		iter->puan=puan;
		
		input *yeni=(input*)malloc(sizeof(input));// iter'in d���nda yeni bir pointer belirleyerek  eleman eklenmesi i�in 2. alan�m�z� olu�turuyoruz .
		yeni->next=iter;	// yeni ekledi�imiz alan �ste oldu�unu varsayarak 2.ye ba�l�yoruz.
		iter=yeni;		// �uan Yeni a�t���m�z'� iter yap�yoruz.
		
		Cikar();
		ekrana_bastir(i);
		
		
} 





int main(){
	FILE *fp;
	
	fp=fopen("Filmler.txt","r");
	char dizi[300][300];
	char temp;
	float temp1;
	int b;
	int c=-1;
	char dizi22[10]={'f','e','n','e','r'};
	char dizi21[10]={'f','e','n','e','r'};
//	Ekle(3.3,dizi22,5);
//	Ekle(4.4,dizi21,5);
//	ekrana_bastir();
	
	if(fp==NULL)
	{
		printf("Your File could not be found "); // E�er ki dosyam�z bulunamazsa NULL de�eri d�ner ve i�lem devam etmez.
	}
	else{
	
		
		printf("Your File could be opened\n");	// fp adl� pointer�m�z�n de�eri Null d�nmedi�i takdirde  "Filmler.txt" den  veri okunmaktad�r. 
		while(!feof(fp)){
				c++;
				b=0;
					// �stedi�imiz �artlar� sa�lamad��� takdirde ��kmak �zere sonsuz d�ng�ye soktuk.	
			//	temp=fgetc(fp);	// getch() fonksiyonu ile karakter okuyoruz ve d�ng� boyunca karakter okumaya devam edecek.
				while(temp!=','){// okuyaca��m�z dosyada "," karakteri g�r�rse sonsuz d�ng�den ��kacak yani o sat�rda �imdilik o d�ng� sonlanacak.
				
				dizi[c][b]=temp;
				b++;
				temp=fgetc(fp);
			
					}
				
				fscanf(fp,"%f",&temp1);// d�ng�den ��kt���nda art�k char karakterlerle i�imiz bitiyor ve ondal�kl� say�lar kar��m�z� ��k�yor onu da scanf fonksiyonu ile float tipinde okuyoruz.
				
				
					temp=fgetc(fp);
					
						
					//printf("%s",dizi[c]);
				//	printf("--->%.1f\n",temp1);
					
						Ekle(temp1,dizi[c],b);
						continue;
							}
							
				
				
				
						
						
						
							}
								}
			
	
	
			

			
			
	


	
			
	


		
		
		
	


