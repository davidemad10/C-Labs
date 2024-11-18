#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number=0;
    int sum=0;
    printf("Please Enter Number: (The app will exit if you sum exceeds 100) \n");
    for(int i=0;i<=100;i++){
        scanf(" %d",&number);
        sum+=number;
        printf("Current sum: %d\n", sum);
        if(sum>=100){
            printf("your numbers sum exceeds 100");
            break;
        }

    }
    return 0;
}
