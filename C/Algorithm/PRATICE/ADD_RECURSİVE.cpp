#include<stdio.h>
#include<conio.h>
int toplam(int n){;
	if(n<=1)
	return n;
	else;
	return (n+toplam(n-1));
}
int main(){
	int n,sonuc;
	printf("istediðiniz bir sayiyi giriniz:\n");
	scanf("%d",&n);
	sonuc=toplam(n);
	printf("%d",sonuc);
	getch();
	return 0;
}
