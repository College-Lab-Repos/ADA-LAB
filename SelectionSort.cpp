#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAXINT 2000

void delay(int n)
{
	int i;
	for(i=0;i<n;i++);
}
void selection(int *a,int n)
{
    delay(1000);
    int i,j,temp,min;
    for(i=0;i<n-1;i++)
    {
         min=a[i];
        for(j=i+1;j<n;j++)
        {
          if(a[j]<min)
          {
            min=j;
          }
        }
     temp=a[i];a[i]=a[j];a[j]=temp;
    }
}

int main()
{
     clock_t  c1,c2;
     int i,datasize=1;
     long int n=1000;
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
       selection(a,n);
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

