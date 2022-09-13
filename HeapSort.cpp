#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//This is to find the max heap of the given heap
int *a;

int temp;

void maxheap(int arr[], int size, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left] < arr[smallest])
        smallest = left;

    if (right < size && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
        maxheap(arr, size, smallest);
    }
}

void heapSort(int arr[], int size)
{

    int i;
    for (i = size / 2 - 1; i >= 0; i--)
        maxheap(arr, size, i);
    for (i = size - 1; i >= 0; i--)
    {
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        maxheap(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
//	printf("Enter the no of elements :");
//    scanf("%d", &n);
    clock_t  start,end;
    int i;
    int n=1000;
    int data=0;
    while(data!=10){
    	a=(int *)calloc(n,sizeof(int));
      for (i = 0; i < n; i++)
    {
    	a[i]=rand();
//       scanf("%d", &a[i] );
    }	
    start = clock();
    heapSort(a, n);
    end = clock();
    if(start!=end){
    	printf("n=%d\tThe time taken is %.10f\n",n,(double)(end-start)/ CLK_TCK);
    	data+=1;
	}
	n+=1000;
	}
//	printf("Enter the elements :");
//    printf("The sorted array is: \n");
//    printArray(arr, n); 
    return 0;
}
