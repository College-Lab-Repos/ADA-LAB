#include <stdio.h>
#define INF 9999

int a[10][10], d[10][10][10];

int min(int a,int b){
	return a>b?b:a;
}

void floyd(int n){
    int k=0,i,j;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++)
            d[k][i][j]=a[i][j];
    }
    for(k=1; k<=n; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                d[k][i][j] =min(d[k-1][i][j],d[k-1][i][k]+d[k-1][k][j]);
            }
        }
    }
}

int main(){
    int n,i,j;
    printf("No of vertices: ");
    scanf("%d",&n);
    printf("Enter Weight matrix(-1 if there is no edge): \n");

    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++){
            scanf("%d",&a[i][j]);
            if(a[i][j] == -1)
                a[i][j] = INF;
        }

    floyd(n);

//    printf("Distance matrix: \n");
//    for(i=1; i<=n; i++){
//        for(j=1; j<=n; j++){
//            if(d[n][i][j] >= INF)
//                printf("-1 ");
//            else                
//                printf("%d ",d[n][i][j]);
//        }
//        printf("\n");
//    }
//It is the modification to find the shortest distance between the source and destination
    int src,dest;
    printf("\nEnter the source vertex:");
    scanf("%d",&src);
    printf("\nEnter the destination vertex");
    scanf("%d",&dest);
    printf("\nEnter the shortest distance between src:%d--->dest:%d=%d",src,dest,d[n][src][dest]);
    
    return 0;
}
