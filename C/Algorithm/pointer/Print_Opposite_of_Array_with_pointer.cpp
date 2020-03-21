#include<stdio.h>
int main(){
	int dizi[10],*p,*q,i,temp;

		printf("10 adet bir dizi giriniz:\n");
	for(i=0;i<10;i++){
	
		scanf("%d",&dizi[i]);
		
	}
	p=&dizi[0];
	q=&dizi[9];
	for(i=0;i<6;i++){
		temp=*(p+i);
		*(p+i)=*(q-i);
		*(q-i)=temp;
		
	}
	printf("\n\n\n");
	for(i=0;i<10;i++){
		printf("%4d",dizi[i]);
	}

	
	


	
	
	return 0;
}
