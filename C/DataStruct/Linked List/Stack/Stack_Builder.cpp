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
	
		// Eðerki top deðerimiz -1 olursa , çýkarma iþlemi gerçekleþemeyeceði için iþlem burda durur
	else{
	
	//	input * x= iter->next;	// -1 deðeri dönmediði en üstteki çýkaracaðýmýz veri.  
		input *temp=iter->next;			// Daha pratik bir silme iþlemi için geçici deðiþkene atýlýr .
	//	iter=iter->next;			// çýkarma iþlemi yapýldýktan sonra çýkarýlan elemaný'nýn bir önceki elemaný bir sonraki elemanýna baðlanýr.
	//	printf("%s'i'Cikarma islemi basarýlý\n",temp->film);
		free(temp);
		//printf("%s",x);			// free fonksiyonu ile hafýzdan silinir.
		
						// sildiðimiz datayý döndürüyoruz.
}
		return temp;
}



void ekrana_bastir(int size ){
	
	input *temp=iter->next;	// baþtaki elemaný kaybetmemek için tekrardan farklý bir deðiþkene atýyoruz.
	int j;
		if(temp!=NULL){
		for(j=0;j<size;j++)
		printf("%c",temp->film[j]); 
		printf("-->%.1f",temp->puan);	// elemaný bastýrdýktan sonra ilerleme iþlemini yapýyoruz.
	}
		
			
}


void sortStack(){
	
	input *t;
	
	t=Cikar();
	printf("%.1f",t->puan);
}

void Ekle(float puan , char film[],int size ){
	if(iter==NULL){ 	//eðer top deðerimiz -1 dönerse yýðýn yapýmýzýn boþ olduðunu anlýyoruz.
		
		iter=(input*)malloc(sizeof(input));	// tek yönlü baðýl listemiz ile yer açýyoruz ver next'ini boþ olarak gösteriyoruz.
		iter->next=NULL;
		printf("----baþarýyla eklendi----\n"); 
	}
		int i;
		for(i=0;i<size;i++){
		
	
		iter->film[i]=film[i];
	//	printf("%c",iter->film[i]);
		
		}
		
	//	printf("-->%.1f\n",puan);			// Yapýmýzda 2 üye bulunmaktadýr(film , puan) burada 2 veriyie yapýmýza yerleþtiriyoruz.
		
		iter->puan=puan;
		
		input *yeni=(input*)malloc(sizeof(input));// iter'in dýþýnda yeni bir pointer belirleyerek  eleman eklenmesi için 2. alanýmýzý oluþturuyoruz .
		yeni->next=iter;	// yeni eklediðimiz alan üste olduðunu varsayarak 2.ye baðlýyoruz.
		iter=yeni;		// Þuan Yeni açtýðýmýz'ý iter yapýyoruz.
		
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
		printf("Your File could not be found "); // Eðer ki dosyamýz bulunamazsa NULL deðeri döner ve iþlem devam etmez.
	}
	else{
	
		
		printf("Your File could be opened\n");	// fp adlý pointerýmýzýn deðeri Null dönmediði takdirde  "Filmler.txt" den  veri okunmaktadýr. 
		while(!feof(fp)){
				c++;
				b=0;
					// Ýstediðimiz þartlarý saðlamadýðý takdirde çýkmak üzere sonsuz döngüye soktuk.	
			//	temp=fgetc(fp);	// getch() fonksiyonu ile karakter okuyoruz ve döngü boyunca karakter okumaya devam edecek.
				while(temp!=','){// okuyacaðýmýz dosyada "," karakteri görürse sonsuz döngüden çýkacak yani o satýrda þimdilik o döngü sonlanacak.
				
				dizi[c][b]=temp;
				b++;
				temp=fgetc(fp);
			
					}
				
				fscanf(fp,"%f",&temp1);// döngüden çýktýðýnda artýk char karakterlerle iþimiz bitiyor ve ondalýklý sayýlar karþýmýzý çýkýyor onu da scanf fonksiyonu ile float tipinde okuyoruz.
				
				
					temp=fgetc(fp);
					
						
					//printf("%s",dizi[c]);
				//	printf("--->%.1f\n",temp1);
					
						Ekle(temp1,dizi[c],b);
						continue;
							}
							
				
				
				
						
						
						
							}
								}
			
	
	
			

			
			
	


	
			
	


		
		
		
	


