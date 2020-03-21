#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int dizi[100],i,*p;
	p=(int*)malloc(100*sizeof(int));
	srand(time(NULL));
	printf("random sayilarimiz\n\n");
	for(i=0;i<100;i++){
		dizi[i]=rand()%100;
		printf("%4d",dizi[i]);
		
	}
	printf("\n\n\n 5. biti 0 olan sayilar \n\n\n");
	for(i=0;i<100;i++){
		if(dizi[i]&1<<5)
		continue;
		else
		*(p+i)=dizi[i];
		printf("%4d",*(p+i));
	}
	return 0;
}
