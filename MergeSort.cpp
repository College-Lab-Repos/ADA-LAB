#include<stdio.h>
#include<time.h>
#include<stdlib.h>


#define MAXINT 2000


void delay(int n)
{
	int i;
	for(i=0;i<n;i++);
}

void combine(int a[],int low,int mid,int high)
{
 int c[150000],i,j,k;
 i=k=low;
 j=mid+1;
 while(i<=mid&&j<=high)
 {
  if(a[i]<a[j])
  {
   c[k]=a[i];
   ++k;
   ++i;
  }
  else
  {
   c[k]=a[j];
   ++k;
   ++j;
  }
 }
 if(i>mid)
 {
  while(j<=high)
  {
   c[k]=a[j];
       ++k;
   ++j;
  }
 }
 if(j>high)
 {
  while(i<=mid)
  {
   c[k]=a[i];
   ++k;
   ++i;
  }
 }
 for(i=low;i<=high;i++)
 {
  a[i]=c[i];
 }
}

void split(int a[],int low,int high)
{
 delay(5000);
 int mid;
 if(low<high)
 {
  mid=(low+high)/2;
  split(a,low,mid);
  split(a,mid+1,high);
  combine(a,low,mid,high);
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
       split(a,0,n-1);
       c2=clock();
       free(a);
       if((c2 -c1) != 0)
       {
        printf("\t%d\t%f\n",n,(double)(c2-c1)/CLK_TCK);
        datasize++;
       }
       n+=1000;
      }
     return 0; 
    }

