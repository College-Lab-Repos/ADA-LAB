#include <stdio.h>

int a[10][10], r[10][10][10],cycle[10];

void warshall(int n){
    int k=0,i,j;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            r[k][i][j]=a[i][j];
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
            	if(r[k-1][i][k]==1&&r[k-1][k][j]==1&&r[k-1][j][i]){
            		cycle[i]=cycle[j]=cycle[k]=1;
				}
                r[k][i][j]=r[k-1][i][j] || (r[k-1][i][k] && r[k-1][k][j]);
            }
        }
    }
}

int main(){
    int n,i,j;
    printf("Enter no of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix: ");
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            scanf("%d",&a[i][j]);
    }
        
    warshall(n);
    printf("The cycle exists between the vertices:");
    for(int i=1;i<=n;i++){
    	if(cycle[i]==1){
    		printf("%d\t",i);
		}
	}
    printf("\nTransitive Closure: \n");
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            printf("%d\t",r[n][i][j]);
        printf("\n");
    }
    return 0;
}
