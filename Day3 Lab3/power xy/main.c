#include <stdio.h>
#include <stdlib.h>

void power(int x , int y){
    int power=1;
    for(int i=0 ; i<y ; i++){
        power*=x;
    }
    printf("The power %d of %d = %d",x,y,power);
}

int main()
{
    power(10,2);
    return 0;
}
