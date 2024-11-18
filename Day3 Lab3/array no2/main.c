#include <stdio.h>
#include <stdlib.h>

int main()
{
    int Arr[10]={10,45,7,-5,1,8,10,14,85,12};
    int max,min;
    max =0;
    min=0;
    for(int i = 0;i<10;i++){
        if(max<Arr[i]){
            max = Arr[i];
        }
        if(min>Arr[i]){
            min = Arr[i];
        }
    }
    printf("max=%d, min=%d",max,min);
    return 0;
}
