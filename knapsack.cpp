#include<stdio.h>

void knapsack();
int max(int,int);
int i,j,noOfItems,maxCapacity,profit[10],weight[10],values[10][10];
int main()
{
 printf("\nenter the no. of items:\t");
 scanf("%d",&noOfItems);
 printf("\nenter the weight of the each item:\n");
 for(i=1;i<=noOfItems;i++)
 {
  scanf("%d",&weight[i]);
 }
 printf("\nenter the profit of each item:\n");
 for(i=1;i<=noOfItems;i++)
 {
  scanf("%d",&profit[i]);
 }
 printf("\nenter the knapsack's capacity:\t");
 scanf("%d",&maxCapacity);
 knapsack();
 return 0;
}

void knapsack()
{
 int x[10];
 for(i=0;i<=noOfItems;i++)
 {
  for(j=0;j<=maxCapacity;j++)
  {
   if(i==0||j==0)
   {
    values[i][j]=0;
   }
   else if(j-weight[i]<0)
   {
    values[i][j]=values[i-1][j];
   }
   else
   {
    values[i][j]=max(values[i-1][j],values[i-1][j-weight[i]]+profit[i]);
   }
  }
 }
 printf("\nthe output is:\n");
 for(i=0;i<=noOfItems;i++)
 {
  for(j=0;j<=maxCapacity;j++)
  {
   printf("%d\t",values[i][j]);
  }
  printf("\n\n");
 }
 printf("\nthe optimal solution is %d",values[noOfItems][maxCapacity]);
 printf("\nthe solution vector of weights is:\n");
 for(i=noOfItems;i>=1;i--)
 {
  if(values[i][maxCapacity]!=values[i-1][maxCapacity])
  {
   x[i]=1;
   maxCapacity-=weight[i];
  }
  else
  {
   x[i]=0;
  }
 }
 for(i=1;i<=noOfItems;i++)
 {
 	if(x[i]!=0){
 		printf("%d\t",profit[i]);
	 }
 }
}

int max(int x,int y)
{
 return x>y?x:y;
}

