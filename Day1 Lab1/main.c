#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 10;
    char y = 'D';
    float z = 10.5;
    char s;

    printf("x=%d y=%c z=%0.2f\n\n",x, y ,z);
    printf("Please Enter char to convert it to ASCII\n");
    scanf(" %c",&s);
    printf("your char is: %c\n",s);
    printf("the ASCII For your char is:%d\n",s);
    printf("octal=%o hexa=%x\n",x,x);
    return 0;
}
