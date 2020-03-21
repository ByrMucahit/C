// C program to generate random numbers 
#include <stdio.h> 
#include <stdlib.h> 
  
// Driver program 








int main(void) 
{ 
    int dizi[10000] ,i,j,min,gecici,n=10000;
 
    
   for(int i = 0; i<n; i++) {
		
		dizi[i]=rand();
       
         
    }
    int l[10][10];
    printf("deger:%d",l[1][1]);
   
   
  

 FILE *fptr;

    // opening file in writing mode
    fptr = fopen("program.txt", "w");

    // exiting program 
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
for(i=10000;i>0;i--){

    fprintf(fptr, "%d\n", dizi[i]);
}
    fclose(fptr);
    return 0;

}
  

