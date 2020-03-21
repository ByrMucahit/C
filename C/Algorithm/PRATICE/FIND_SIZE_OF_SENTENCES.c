#include<stdio.h>
#include<conio.h>
#include<string.h>
 	
 int main(){
 	char isim[200];
 	int i; 
 
	
	printf("kelime ya da  harf giriniz:");
	gets(isim);
	int uzunluk=0;
	for(i=0;isim[i]!='\0';i++){
	if(isim[i]==' ')
	uzunluk++;	

	
	}
printf("girdiginiz kelime sayisi : %d",uzunluk+1);

	getch();
	return 0;
	
		
	
	
}
