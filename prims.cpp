#include<stdio.h>

void prims();
int adjacency[10][10],n;
int main()
{
 int i,j,m;
 printf("\nenter the no. of vertices:\t");
 scanf("%d",&n);
 printf("\nenter the cost matrix:enter -1 for infinite distance\n");
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   scanf("%d",&m);
   if(m==-1){
   	adjacency[i][j]=9999;
   }
   else{
   	adjacency[i][j]=m;
   }
  }
 }
 prims();
 return 0;
}

void prims()
{
 int i,j,u,v,min;
 int noofVertices=0,mincost=0;
 int visited[10];
 for(i=1;i<=n;i++)
 {
  visited[i]=0;
 }
 visited[1]=1;
 while(noofVertices!=n-1)
 {
  min=9999;
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(visited[i]==1)
    {
     if(adjacency[i][j]<min)
     {
      min=adjacency[i][j];
      u=i;
      v=j;
     }
    }
   }
  }
  if(visited[v]!=1)
  {
   printf("\n%d----->%d=%d\n",u,v,min);
   visited[v]=1;
   noofVertices+=1;
   mincost+=min;
  }
  adjacency[u][v]=adjacency[v][u]=9999;
 }
 printf("\nmincost=%d",mincost);
}

