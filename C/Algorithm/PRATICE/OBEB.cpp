#include<stdio.h>
#include<conio.h>
int obeb(int x , int y,int i ){
	int  sonuc;
	if(y>=i){
		if(x%y==0){
		x=x/y;
		return(x,y,y) ;}
		else if(x%i==0&&y%i==0)		
			sonuc=i;
			
		else if(x%i!=0 || y%i!=0){
		
		sonuc=obeb(x,y,i-1);
		return sonuc;}
		else{
		printf("aralarýnda asaldýr...");
		return (obeb(x,y,0));
			}
		
}
}
int main(){
	int sonuc,x,y,i,bs,ks;
	printf("obeblerini bulmak istediginiz 2 tam sayiyi giriniz:\n");
	scanf("%d",&x);
	scanf("%d",&y);
	if(x>y){
		bs=x;
		ks=y;
		i=ks;
	sonuc=obeb(bs,ks,i);	
	}
	else
	{
		bs=y;
		ks=x;
		i=ks;
		sonuc=obeb(bs,ks,i);
	}
	
	printf("%d---%d----%d",bs,ks,sonuc);
	if(sonuc==1)
	printf("\naralarýnda asaldýr...");
	getch();
	return 0;
		}

