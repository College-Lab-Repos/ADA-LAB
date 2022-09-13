#include<stdio.h>

void kruskals();
int c[10][10],n;
int main()
{
 int i,j,m;
 printf("\nenter the no. of vertices:\t");
 scanf("%d",&n);
 printf("\nenter the cost matrix: enter -1 for infinite distance\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
  	scanf("%d",&m);
  	if(m==-1){
  		c[i][j]=9999;
    }
	else{
    	c[i][j]=m;
    }
  }
 }
 kruskals();
return 0;
}

void kruskals()
{
 int i,j,u,v,a,b,min;
 int noofVertices=0,mincost=0;
 int parent[10];
 for(i=1;i<=n;i++)
 {
  parent[i]=0;
 }
 while(noofVertices!=n-1)
 {
  min=9999;
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
     if(c[i][j]<min)
     {
      min=c[i][j];
      u=a=i;
      v=b=j;
     }
   }
  }
  while(parent[u]!=0)
  {
   u=parent[u];
  }
  while(parent[v]!=0)
  {
   v=parent[v];
  }
  if(a!=b){
  	if(u==v){
  	printf("\nThe vertices causing the cycle are %d , %d , %d\n",u,a,b);
  }
  }
  
  if(u!=v)
  {
   printf("\n%d----->%d=%d\n",a,b,min);
   parent[v]=u;
   noofVertices+=1;
   mincost+=min;
  }
  c[a][b]=c[b][a]=9999;
 }
 printf("\nmincost=%d",mincost);
}

