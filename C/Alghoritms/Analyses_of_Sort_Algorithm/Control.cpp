#include <stdio.h>
#include <stdlib.h>

void Merge(int Dizi[], int ilk, int orta, int son)
{ int tempArray[1000]; // geçici dizi tanýmlanýyor

int ilk1 = ilk; int son1 = orta; // birinci altdizinin baþlangýcý ve sonu
int ilk2 = orta + 1; int son2 = son; // ikinci altdizinin baþlangýcý ve sonu
int index = ilk1; // geçici dizinin indisi ayarlanýyor
for ( ; (ilk1 <= son1) && (ilk2 <= son2); index++) //Geçici diziye elemanlar sýralý alýnýyor
{ if (Dizi[ilk1] < Dizi[ilk2]) { tempArray[index] = Dizi[ilk1];

ilk1++; }

else { tempArray[index] = Dizi[ilk2];

ilk2++; }

}
for (; ilk1 <= son1; ilk1++, index++) // birinci altdizinin elemanlarý bitmemiþse

tempArray[index] = Dizi[ilk1];

for (; ilk2 <= son2; ilk2++, index++) // ikinci altdizinin elemanlarý bitmemiþse

tempArray[index] = Dizi[ilk2];

for (index = ilk; index <= son; index++) //gecici dizi orjinal diziye kopyalanýr(merge)
Dizi[index] = tempArray[index];

}

void Mergesort(int Dizi [], int ilk, int son)
{ if (ilk < son)

{ int orta = (ilk + son) / 2;

Mergesort(Dizi, ilk, orta); // dizi bölünüyor
Mergesort(Dizi, orta + 1, son); // dizi bölünüyor
Merge(Dizi, ilk, orta, son); // birleþtiriliyor

}

}


int main()
{
	int dizi[10000]; 
   int num,i=0,j,pivot_degeri,pivot_indisi,gecici,n=10000;
   FILE *fptr;

   if ((fptr = fopen("program.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
	while(fscanf(fptr,"%d\n", &num)!=EOF )	{
	
   	dizi[i]=num;
    
    i++;
}	
  
   fclose(fptr); 
   
Mergesort(dizi,0,n);
 

   


 return 0;

}
  
  

