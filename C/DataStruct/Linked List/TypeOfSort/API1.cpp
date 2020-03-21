#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct List{	//Hash yap�m�zdaki ba�l�klar �eklinde nitelendirebiliriz.
	int number_of_customer;	// M��teri numaras� bilgisi
	char name;	// M��teri isim bilgisi
	char surname;//m��teri soyisim bilgisi
	int index;//satir bilgisi

	
}customer;
customer *app;
int size;

void assign_value(){ // kullan�c�dan hash yap�s�n�n boyutunu al�yoruz...
	printf("Hash yapisinin boyutunu belirleyiniz:\n");
	scanf("%d",&size);
}

typedef struct table{
		

	 customer row[ 10]; // Hash yap�m�z.
}table;
table tables;

void initialise( ){// Bu fonksiyonda ilk deger atamalar�n� yap�yoruz.

	for(int i=0; i < size ;i++){
		tables.row[i].number_of_customer=-1;
		tables.row[i].index=i;
	
	}
}

int HASH(int number){ // Bu fonksiyonda hash yap�m�z�n boyutuna g�re girilen say�lar�n modunu alarak yerle�ecegi alan� belirliyoruz.
	return (number%size);
}



int search(int number){// Bu fonksiyonda , has yap�s�nda diledi�imiz bir say�y� arat�yoruz ve bulunma durumuna g�re de�er d�nd�r�yoruz. 
	int sayac=1;
	int Hadress;
	
	Hadress=HASH(number);	//G�nderilen say�y� HASH fonksiyonuna g�ndererek sat�r adresinin alarak nokta at��� bir arama i�lemi yapar. 

	for (int i=Hadress;i<size;i++){
			
	
	if(tables.row[i].number_of_customer==number){// Arad���m�z eleman baska bir elemanla cak�smaks�z�n hash yap�s�n�n istedigimiz sat�r�nda bulunursa direk bu if yap�s�na girer ve sayac� kac�nc� ad�mda buldugunu dondurur.
		return sayac;
	
		
	}
	else{// E�er ba�ka bir elemanla �ak��ma durumu var ise bu else k�sm�na girer ve ondan sonraki bo�luklara iner yada son eleman ise ba�a d�ner.

		sayac++;
		if(i==size-1){
			for(int j=0;j<Hadress;j++){
				
		if(tables.row[j].number_of_customer==number)
			return sayac;
			
			else sayac++;
			
		}
	}
			
	}
	return 0;
 

}

}



void add(int number[50] , char name[50] , char surname[50],int amount ){//Kullan�c�n�n istedigi kadar bilgileri almak icin arrayleri boyutland�r�yoruz ve amount'u kullan�c�n�n girdigi veri say�s�n� tutuyoruz.
	int Hadress;

	int i;
	
	
	for(i=0;i<amount;i++){
	Hadress=HASH(number[i]);
	while(Hadress<size){
	
	if(tables.row[Hadress].number_of_customer==-1){ //Modu al�nan say�n�n yerlesegi alan bosmu diye kontrol ediyoruz.Bo�sa bilgileri yerlestiriyoruz degilse bu k�sma girmeden devam ediyoruz.
		tables.row[Hadress].number_of_customer=number[i];
		tables.row[Hadress].name=name[i];
		tables.row[Hadress].surname=surname[i];
		tables.row[Hadress].index=Hadress;
		break;
		
		
	}
		
	else if(tables.row[Hadress].number_of_customer!=-1)
	{
	
	Hadress++;// Eger hash yap�s�ndaki moduna al�nan degerin bulundugu sat�r bo� de�ilse bir �ak��ma durumu ortaya ��k�yor. Bunun i�inde say�n�n yerle�mesi i�in bir sonraki bo� sat�ra ilerliyoruz.

	if(Hadress==size){// Eger sat�rlarda elemanlar�n �ak��a durumu varsa ve o sat�r�n alt�ndaki t�m hash sat�rlar� dolu ise  en ba�tan Hadress degerine kadar olan bolumu kontro edecek.
		
		int j=0;
		while(j<Hadress){//Ba�tan kontrol etmeye ba�lad���m�z sat�rlardan bo� olan varsa bu k�sma girecek.
			if(tables.row[j].number_of_customer==-1){ // E�er bo�sa girebilir �art� koyuyoruz.�art sa�lan�rsa bilgileri yerle�tiriyoruz.
		tables.row[j].number_of_customer=number[i];
		tables.row[j].name=name[i];
		tables.row[j].surname=surname[i];
		tables.row[j].index=j;
		j++;
		break;
		
			
		}
		 j++; // While d�ng�s� sonsuza kadar devam etmemesi i�in tabi ki j leri artt�ryoruz.
	}
		
		
					}
	}
	else printf("Tum tablolar dolu...");
									}
								}
														}

	
	
void print(){// ilk sat�rdan sonuna kadar hepsini bast�r�yoruz
	for(int i=0;i<size;i++){
		printf("%d.satirda ---> (%d var)\n",tables.row[i].index,tables.row[i].number_of_customer);
	}
}



int main(){
	// Bilgileri tutsunlar diye arrayleri belirliyoruz
	char isim[50]; 
	char soyisim[50] ;
	int number[50];
	int amount;
	int searc;
	int i=0;

	assign_value();
	printf("Kac adet sayi gireceksiniz??\n");
	scanf("%d",&amount);
	initialise( );
	while(i<amount){// kullan�c�n�n belirledigi say�da kullan�c�dan veri al�yoruz.
		printf("isim giriniz:\n");
		scanf("%s",&isim[i]);
		printf("soyisim giriniz:\n");
		scanf("%s",&soyisim[i]);
		printf("sayi giriniz:\n");
		scanf("%d",&number[i]);
		i++;
		
	}
	
	
	add(number,isim,soyisim,amount);//ekle ve yazma fonksiyonlar�n� cag�r�yoruz.
	print();
	printf("L�tfen aramak istedi�iniz sayiyi giriniz:\n");
	scanf("%d",&searc);
	if(search(searc)!=0){//bu fonksiyonda diledigimiz elemanlar� cag�r�yoruz.cag�r�lan fonksiyondan d�nen de�ere g�re bir a��klama yap�yoruz....
		printf("%d sayiniz hash yap�m�zda bulunmakta ve %d. ad�mda bulunmustur",searc,search(searc));//eger eleman bulunursa
	}
	else{
		printf("Hash yap�m�zda %d bulunamamakta",searc);//eleman bulunmazsa
	}
	
	
	return 0;
	
}


