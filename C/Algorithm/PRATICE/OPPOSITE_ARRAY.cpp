#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void diziyiterscevir(int *pointer[]){
	int i;
	printf("\n\n\ndizinin ters hali :\n");
	for(i=9;i>=0;i--){
		printf("%4d",*pointer[i]);
	}
}
int main(){int i,*p[10],dizi[10];
	srand(time(NULL));
	for(i=0;i<10;i++){
		dizi[i]=rand()%10;
		printf("%4d",dizi[i]);
		p[i]=&dizi[i];
		
	}
	diziyiterscevir(p);
	return 0;
	
	
	
}
