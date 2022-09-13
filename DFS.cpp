#include<stdio.h>

int adj[10][10];
int visited[10];
int n;
char label[] = {'A','B','C','D','E','F','G','H','I','J'};

void depthFirstSearch(int v){
	printf("%c ",label[v]);
	visited[v] = 1;
	int i;
	for(i=0;i<n;i++){
		if(visited[i]==0&&adj[v][i]==1){
			depthFirstSearch(i);
		}
	}
}

int main()
{
	int i,j;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	printf("Enter the adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&adj[i][j]);
		}
		visited[i]=0;
		printf("\n");
	}
	depthFirstSearch(0);
	printf("\n");
	return 0;
}


