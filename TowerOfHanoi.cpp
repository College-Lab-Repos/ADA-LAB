#include<stdio.h>
void tower_hanoi(int n, char src, char temp, char dest) {
  if(n == 1) {
        printf("MOVE DISC %d FROM %c to %c \n",n,src,dest);
        return ;
    }
    tower_hanoi(n - 1, src, dest, temp);
    printf("MOVE DISC %d FROM %c to %c \n",n,src,dest);
    tower_hanoi(n - 1, temp, src, dest);
}

int main() {
    int x;
    printf("Enter no of disc :");
    scanf("%d",&x);
    tower_hanoi(x, 'A', 'B', 'C');
    return 0;
}

