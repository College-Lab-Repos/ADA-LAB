#include<stdio.h>
#include<time.h>
#include<stdlib.h>


#define MAXINT 2000


void delay(int n)
{
	int i;
	for(i=0;i<n;i++);
}

void quicksort(int number[],int first,int last){
   delay(1000);
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}

   int main()
   {
     clock_t  c1,c2;
     int i,datasize=1;
     long int n=10000;
     int *a;
     while(datasize<=10)
     {
      a=(int *)calloc(n,sizeof(int));
       if(a==NULL)
       {
        printf("INSUFFICIENT MEMORY\n");
        exit(1);
       }
       for(i=0;i<=n-1;i++) a[i]=rand() % MAXINT;
       c1=clock();
       quicksort(a,0,n-1);
       c2=clock();
       free(a);
       if((c2 -c1) != 0)
       {
        printf("\tN:%d\tTIME:%f\n",n,(double)(c2-c1)/CLK_TCK);
        datasize++;
       }
       n+=10000;
      }
     return 0;
    }
