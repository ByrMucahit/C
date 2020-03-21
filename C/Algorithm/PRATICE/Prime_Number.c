#include<stdio.h>
#include<conio.h>
#include<math.h>
void asal_sayi(int x)

{
	  int i ,j,sayac=0;
	 
	  	for(j=2;j<x;j++){
	  if(x%j==0&&x>2)
	  	sayac++;
	   }
	  
if(sayac==0)

printf("asal ...");

else 


printf("asal degildir...");

}
int main(){
	
	int a;
	printf("bir a sayisi giriniz:\n");
	scanf("%d",&a);
	asal_sayi(a);
	getch();
	return 0;
	
	
	
	
}
