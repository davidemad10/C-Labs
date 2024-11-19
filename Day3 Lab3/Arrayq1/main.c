#include <stdio.h>
#include <stdlib.h>
#define SIZE 12
#define ROWS 4

int main()
{
    printf("Enter the array elemnent \n");
    int arr[SIZE]={0};
    for(int i = 0;i<SIZE;i++){
        scanf("%d",&arr[i]);
    }
    for(int i = 0;i<ROWS;i++){
        printf("\n");
        for(int j = 0;j<(SIZE/ROWS);j++){
            printf("%d \t",arr[(i*(SIZE/ROWS))+j]);
        }
    }
    return 0;
}
