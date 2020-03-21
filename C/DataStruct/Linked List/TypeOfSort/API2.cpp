#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define row_max 5

typedef struct List{//Hash yapýmýzdaki baþlýklar þeklinde nitelendirebiliriz.
	int number_of_customer;
	char name;
	char surname;
	int index;
	int Link;
	
}customer;



typedef struct table{
		
	
	 customer row[row_max]; // Hash yapýmýz.
}table;
table tables;
int size;

void assign_value(){// kullanýcýdan hash yapýsýnýn boyutunu alýyoruz...

	printf("Hash yapisinin boyutunu belirleyiniz:\n");
	scanf("%d",&size);
}

void initialise(){// Bu fonksiyonda ilk deger atamalarýný yapýyoruz.

	for(int i=0; i < row_max ;i++){
		tables.row[i].number_of_customer=-1;
		tables.row[i].index=-1;
		tables.row[i].Link=-1;
	
	}
}

int HASH(int number){// Bu fonksiyonda hash yapýmýzýn boyutuna göre girilen sayýlarýn modunu alarak yerleþecegi alaný belirliyoruz.
	return (number%row_max);
}



int search(int number){// Bu fonksiyonda , has yapýsýnda dilediðimiz bir sayýyý aratýyoruz ve bulunma durumuna göre deðer döndürüyoruz. 
	int sayac=1;
	int Hadress;
	
	Hadress=HASH(number);	//Gönderilen sayýyý HASH fonksiyonuna göndererek satýr adresinin alarak nokta atýþý bir arama iþlemi yapar. 

	for (int i=Hadress;i<row_max;i++){
			
	
	if(tables.row[i].number_of_customer==number){// Aradýðýmýz eleman baska bir elemanla cakýsmaksýzýn hash yapýsýnýn istedigimiz satýrýnda bulunursa direk bu if yapýsýna girer ve sayacý kacýncý adýmda buldugunu dondurur.
		return sayac;
	
		
	}
	else{// Eðer baþka bir elemanla çakýþma durumu var ise bu else kýsmýna girer ve ondan sonraki boþluklara iner yada son eleman ise baþa döner.

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



void add(int number[50] , char name[50] , char surname[50],int amount ){//Kullanýcýnýn istedigi kadar bilgileri almak icin arrayleri boyutlandýrýyoruz ve amount'u kullanýcýnýn girdigi veri sayýsýný tutuyoruz.
	int Hadress;
	int i;
	int k=1;
	
	
	for(i=0;i<amount;i++){
	Hadress=HASH(number[i]);
	
	
	if(tables.row[Hadress].number_of_customer==-1){ 			//Modu alýnan sayýnýn yerlesegi alan bosmu diye kontrol ediyoruz.Boþsa bilgileri yerlestiriyoruz degilse bu kýsma girmeden devam ediyoruz.
																		
		tables.row[Hadress].number_of_customer=number[i];
		tables.row[Hadress].name=name[i];
		tables.row[Hadress].surname=surname[i];
		tables.row[Hadress].index=Hadress;
		
		
		
		
	}
	
		
	else //Eðer elemanlar arasýnda çakýþma duruma var ise hash yapýsýný en üstten baþlayarak gezer ve aþaðýya doðru boþ bir satýr var mý kontrol eder.
	{	
		printf("\n%d.Tablo dolu diger tablolara geciliyor.\n",Hadress);// Eger tablo dolu ise tablo doludur uyarýsýný ekrana bastýrýyor...
		
		tables.row[Hadress].Link=1;//Çakýþma durumunda ilk elemana 1 deðeri atanýr bu bir adress gibidir .
	
		
		int j=0;
		
		while(j<row_max){//en bastan sona dogru bos elemana sahip satýr var mý kontrol ediyoruz...
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
	

	
	
void print(){// Link degerlerine göre ekrana bastýrýyoruz..
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
	assign_value();// ilk degeri atamak icin ilk degeri ata fonkisyonu cagýrýyoruz.
		
	printf("Kac adet sayi gireceksiniz??\n");
	scanf("%d",&amount);
	
	initialise();
	
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


