#include<stdio.h>
#include<conio.h>
#include<string.h>

 int main(){
 	
 char metin[200],kelime[200];
	int i,j;
		printf("metin giriniz:\n");
	gets(metin);
	
	printf("bir kelime giriniz:\n");
	gets(kelime);
	

	int sayac=0;
for(i=0;metin[i]!='\0';i++){
	for(j=0;kelime[j]!='\0';j++){
	
	
if(metin[i]==' ')
sayac++;

if(metin[i]==kelime[j])
{
		printf("hangi pozisyonda : %d",sayac+1);
break;
}

else if(metin[i]!=kelime[j]){
printf("error");
break;	
}

}

}

	


	getch();
	return 0;
}
