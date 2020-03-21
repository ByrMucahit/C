#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define row_max 5

typedef struct List{//Hash yap�m�zdaki ba�l�klar �eklinde nitelendirebiliriz.
	int number_of_customer;
	char name;
	char surname;
	int index;
	int Link;
	
}customer;



typedef struct table{
		
	
	 customer row[row_max]; // Hash yap�m�z.
}table;
table tables;
int size;

void assign_value(){// kullan�c�dan hash yap�s�n�n boyutunu al�yoruz...

	printf("Hash yapisinin boyutunu belirleyiniz:\n");
	scanf("%d",&size);
}

void initialise(){// Bu fonksiyonda ilk deger atamalar�n� yap�yoruz.

	for(int i=0; i < row_max ;i++){
		tables.row[i].number_of_customer=-1;
		tables.row[i].index=-1;
		tables.row[i].Link=-1;
	
	}
}

int HASH(int number){// Bu fonksiyonda hash yap�m�z�n boyutuna g�re girilen say�lar�n modunu alarak yerle�ecegi alan� belirliyoruz.
	return (number%row_max);
}



int search(int number){// Bu fonksiyonda , has yap�s�nda diledi�imiz bir say�y� arat�yoruz ve bulunma durumuna g�re de�er d�nd�r�yoruz. 
	int sayac=1;
	int Hadress;
	
	Hadress=HASH(number);	//G�nderilen say�y� HASH fonksiyonuna g�ndererek sat�r adresinin alarak nokta at��� bir arama i�lemi yapar. 

	for (int i=Hadress;i<row_max;i++){
			
	
	if(tables.row[i].number_of_customer==number){// Arad���m�z eleman baska bir elemanla cak�smaks�z�n hash yap�s�n�n istedigimiz sat�r�nda bulunursa direk bu if yap�s�na girer ve sayac� kac�nc� ad�mda buldugunu dondurur.
		return sayac;
	
		
	}
	else{// E�er ba�ka bir elemanla �ak��ma durumu var ise bu else k�sm�na girer ve ondan sonraki bo�luklara iner yada son eleman ise ba�a d�ner.

		sayac++;
		if(i==row_max-1){
			for(int j=0;j<Hadress;j++){
				
		if(tables.row[j].number_of_customer==number)
			return sayac;
			
			else sayac++;
			
		}
	}
			
	}
 

}

}



void add(int number[50] , char name[50] , char surname[50],int amount ){//Kullan�c�n�n istedigi kadar bilgileri almak icin arrayleri boyutland�r�yoruz ve amount'u kullan�c�n�n girdigi veri say�s�n� tutuyoruz.
	int Hadress;
	int i;
	int k=1;
	
	
	for(i=0;i<amount;i++){
	Hadress=HASH(number[i]);
	
	
	if(tables.row[Hadress].number_of_customer==-1){ 			//Modu al�nan say�n�n yerlesegi alan bosmu diye kontrol ediyoruz.Bo�sa bilgileri yerlestiriyoruz degilse bu k�sma girmeden devam ediyoruz.
																		
		tables.row[Hadress].number_of_customer=number[i];
		tables.row[Hadress].name=name[i];
		tables.row[Hadress].surname=surname[i];
		tables.row[Hadress].index=Hadress;
		
		
		
		
	}
	
		
	else //E�er elemanlar aras�nda �ak��ma duruma var ise hash yap�s�n� en �stten ba�layarak gezer ve a�a��ya do�ru bo� bir sat�r var m� kontrol eder.
	{	
		printf("\n%d.Tablo dolu diger tablolara geciliyor.\n",Hadress);// Eger tablo dolu ise tablo doludur uyar�s�n� ekrana bast�r�yor...
		
		tables.row[Hadress].Link=1;//�ak��ma durumunda ilk elemana 1 de�eri atan�r bu bir adress gibidir .
	
		
		int j=0;
		
		while(j<row_max){//en bastan sona dogru bos elemana sahip sat�r var m� kontrol ediyoruz...
			if(tables.row[j].number_of_customer==-1){ // if hash stuck has not a member
		
		tables.row[j].number_of_customer=number[i];
		tables.row[j].name=name[i];
		tables.row[j].surname=surname[i];
		tables.row[j].index=j;
		k++;
		tables.row[j].Link=k;
	
		break;
			
		}
		else j++;
	}
		
	
					
	}

									
								}
														}
	

	
	
void print(){// Link degerlerine g�re ekrana bast�r�yoruz..
	for(int i=0;i<row_max;i++){
		if(tables.row[i].Link!=-1  ){
			
		printf("%d.satirda ---> (%d var)\n",tables.row[i].index,tables.row[i].number_of_customer);
	}
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
	assign_value();// ilk degeri atamak icin ilk degeri ata fonkisyonu cag�r�yoruz.
		
	printf("Kac adet sayi gireceksiniz??\n");
	scanf("%d",&amount);
	
	initialise();
	
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


