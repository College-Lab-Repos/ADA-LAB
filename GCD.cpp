#include<stdio.h>

int GCD(int,int);

int main(int argc,char **argv){
	int m,n;
	printf("Enter the first Number: ");
	scanf("%d",&m);
    printf("Enter the second Number: ");
    scanf("%d",&n);
    m=GCD(m,n);
    
    printf("The GCD OF THE THOSE TWO NUMBERS %d",m);
    return 0;
}

int GCD(int m,int n){
	if(m==0){
		return n;
	}
	if(n==0){
		return m;
	}
	
	return GCD(n,m%n);
}
