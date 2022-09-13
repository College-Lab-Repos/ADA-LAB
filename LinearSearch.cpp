#include<stdio.h>
#include<stdlib.h>


int search(int a[], int, int);


int main()
{
        int ch,n, i, key, pos = 0;
        printf("How many Elements are present In The Array: ");
        scanf("%d",&n);
        int a[n];
        printf("enter the array elements\n");
       
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
        printf("enter the element to be searched\n");
        scanf("%d",&key); 
	    pos = search(a, n, key);
    	if(pos == -1)
         	printf("Element is not present in array");
        else 
            printf("Element is present at index %d", pos);   
			
	return 0; 
}
 
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}


