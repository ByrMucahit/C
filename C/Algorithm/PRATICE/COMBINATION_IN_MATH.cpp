
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 int comb(int fac1 , int fac2)
{
	int sonuc=1,i,j,sonuc1=1,kombinasyon=1;
	for(i=1;fac1>=i;i++){
		
	sonuc1*=i	;
	}
		for(j=1;fac2>=j;j++){
			
			sonuc*=j;
			
		
	}
	kombinasyon=sonuc1/sonuc;
	
	return kombinasyon;
}
int main(){
	int a,b;
	printf("a degeri giriniz:\n");
	scanf("%d",&a);
	printf("b degerini giriniz:\n");
	scanf("%d",&b);

	comb(a,b);
	printf("%d",comb(a,b));
	getch();
	
	
	
	
	
}
