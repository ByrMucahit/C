#include<stdio.h>
#include<stdlib.h>
int main(){
	int i,sayac=0,*p,dizi[100],n;
	while(1){
		printf("tam sayilar giriniz:\n"); scanf("%d",&i);
		if(i<0) break;
		else {
			if(i%3==0 && i%5==0 )
			{dizi[sayac]=i;
			sayac++;}
	}
	}
	p=(int*)malloc(sizeof(int)*sayac);
	if(*p==0)
		printf("yetersiz bellek...");
	else{
		for(i=0;i<sayac;i++)
		*(p+i)=dizi[i];
	
}
		for(i=0;i<sayac;i++)	
			printf("%d\n",*(p+i));
		
		free(p);
		return 0;

}
