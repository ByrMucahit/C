#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct List{	//Hash yapýmýzdaki baþlýklar þeklinde nitelendirebiliriz.
	int number_of_customer;	// Müþteri numarasý bilgisi
	char name;	// Müþteri isim bilgisi
	char surname;//müþteri soyisim bilgisi
	int index;//satir bilgisi

	
}customer;
customer *app;
int size;

void assign_value(){ // kullanýcýdan hash yapýsýnýn boyutunu alýyoruz...
	printf("Hash yapisinin boyutunu belirleyiniz:\n");
	scanf("%d",&size);
}

typedef struct table{
		

	 customer row[ 10]; // Hash yapýmýz.
}table;
table tables;

void initialise( ){// Bu fonksiyonda ilk deger atamalarýný yapýyoruz.

	for(int i=0; i < size ;i++){
		tables.row[i].number_of_customer=-1;
		tables.row[i].index=i;
	
	}
}

int HASH(int number){ // Bu fonksiyonda hash yapýmýzýn boyutuna göre girilen sayýlarýn modunu alarak yerleþecegi alaný belirliyoruz.
	return (number%size);
}



int search(int number){// Bu fonksiyonda , has yapýsýnda dilediðimiz bir sayýyý aratýyoruz ve bulunma durumuna göre deðer döndürüyoruz. 
	int sayac=1;
	int Hadress;
	
	Hadress=HASH(number);	//Gönderilen sayýyý HASH fonksiyonuna göndererek satýr adresinin alarak nokta atýþý bir arama iþlemi yapar. 

	for (int i=Hadress;i<size;i++){
			
	
	if(tables.row[i].number_of_customer==number){// Aradýðýmýz eleman baska bir elemanla cakýsmaksýzýn hash yapýsýnýn istedigimiz satýrýnda bulunursa direk bu if yapýsýna girer ve sayacý kacýncý adýmda buldugunu dondurur.
		return sayac;
	
		
	}
	else{// Eðer baþka bir elemanla çakýþma durumu var ise bu else kýsmýna girer ve ondan sonraki boþluklara iner yada son eleman ise baþa döner.

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



void add(int number[50] , char name[50] , char surname[50],int amount ){//Kullanýcýnýn istedigi kadar bilgileri almak icin arrayleri boyutlandýrýyoruz ve amount'u kullanýcýnýn girdigi veri sayýsýný tutuyoruz.
	int Hadress;

	int i;
	
	
	for(i=0;i<amount;i++){
	Hadress=HASH(number[i]);
	while(Hadress<size){
	
	if(tables.row[Hadress].number_of_customer==-1){ //Modu alýnan sayýnýn yerlesegi alan bosmu diye kontrol ediyoruz.Boþsa bilgileri yerlestiriyoruz degilse bu kýsma girmeden devam ediyoruz.
		tables.row[Hadress].number_of_customer=number[i];
		tables.row[Hadress].name=name[i];
		tables.row[Hadress].surname=surname[i];
		tables.row[Hadress].index=Hadress;
		break;
		
		
	}
		
	else if(tables.row[Hadress].number_of_customer!=-1)
	{
	
	Hadress++;// Eger hash yapýsýndaki moduna alýnan degerin bulundugu satýr boþ deðilse bir çakýþma durumu ortaya çýkýyor. Bunun içinde sayýnýn yerleþmesi için bir sonraki boþ satýra ilerliyoruz.

	if(Hadress==size){// Eger satýrlarda elemanlarýn çakýþa durumu varsa ve o satýrýn altýndaki tüm hash satýrlarý dolu ise  en baþtan Hadress degerine kadar olan bolumu kontro edecek.
		
		int j=0;
		while(j<Hadress){//Baþtan kontrol etmeye baþladýðýmýz satýrlardan boþ olan varsa bu kýsma girecek.
			if(tables.row[j].number_of_customer==-1){ // Eðer boþsa girebilir þartý koyuyoruz.Þart saðlanýrsa bilgileri yerleþtiriyoruz.
		tables.row[j].number_of_customer=number[i];
		tables.row[j].name=name[i];
		tables.row[j].surname=surname[i];
		tables.row[j].index=j;
		j++;
		break;
		
			
		}
		 j++; // While döngüsü sonsuza kadar devam etmemesi için tabi ki j leri arttýryoruz.
	}
		
		
					}
	}
	else printf("Tum tablolar dolu...");
									}
								}
														}

	
	
void print(){// ilk satýrdan sonuna kadar hepsini bastýrýyoruz
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
	while(i<amount){// kullanýcýnýn belirledigi sayýda kullanýcýdan veri alýyoruz.
		printf("isim giriniz:\n");
		scanf("%s",&isim[i]);
		printf("soyisim giriniz:\n");
		scanf("%s",&soyisim[i]);
		printf("sayi giriniz:\n");
		scanf("%d",&number[i]);
		i++;
		
	}
	
	
	add(number,isim,soyisim,amount);//ekle ve yazma fonksiyonlarýný cagýrýyoruz.
	print();
	printf("Lütfen aramak istediðiniz sayiyi giriniz:\n");
	scanf("%d",&searc);
	if(search(searc)!=0){//bu fonksiyonda diledigimiz elemanlarý cagýrýyoruz.cagýrýlan fonksiyondan dönen deðere göre bir açýklama yapýyoruz....
		printf("%d sayiniz hash yapýmýzda bulunmakta ve %d. adýmda bulunmustur",searc,search(searc));//eger eleman bulunursa
	}
	else{
		printf("Hash yapýmýzda %d bulunamamakta",searc);//eleman bulunmazsa
	}
	
	
	return 0;
	
}


