#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){int dizi[100],sayac=0,i,j=0;
	FILE *fp=fopen("sayilar.txt","r+");

	if(fp==NULL){
		printf("dosyaya ulasilamadi...");
		fclose(fp);
		getch();
		return 0;
	}
	else;
	
  	while(!feof(fp)){
	for(i=0;i<100;i++)  {
	
  fscanf(fp,"%d\n",&dizi[i]);
  printf("%d\n",dizi[i]);
}
}
		
	
	fclose(fp);
	
	FILE*fp2=fopen("sayilar2.txt","w+");
    for(i=0;i<100;i++){
	int kontrol=0;
		for(int k =2 ; k<(dizi[i]/2);k++){
	
	if((dizi[i]%k)==0  ){
	kontrol=1;
	break;
	}

	
		}
			if(kontrol==0){
	fprintf(fp2,"%d\n",dizi[i]);
	printf("asal sayilar:%d\n",dizi[i]);
		
		}}
	fclose(fp2); 
	getch();
	return 0;
	
}
