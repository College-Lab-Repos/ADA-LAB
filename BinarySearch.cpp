#include <stdio.h>


int binary(int a[], int low, int high, int m)
{
if (high >= low) {
int mid = low + (high - low) / 2;
if (a[mid] == m)
return mid;
if(a[mid] > m)
return binary(a, low, mid - 1, m);
return binary(a, mid + 1, high, m);
}
return -1;
}

int main()
{
        int ch,n, i, key, pos = 0;
        printf("Enter the number of elements in the array: ");
        scanf("%d",&n);
        int a[n];
        printf("enter the array elements\n");
        
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
        printf("enter the element to be searched\n");
        scanf("%d",&key); 
        pos = binary(a, 0, n - 1,key);
        if(pos == -1)
        	printf("Element is not present in array");
        else 
            printf("Element is present at index %d", pos); 
			
    return 0;  
}
