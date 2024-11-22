#include <stdio.h>
#include <stdlib.h>
#include "myFunctions.h"


int main()
{
    //1
    char name[100]="";
    myStrCat(name,"david");
    myStrCat(name,"emad");
    printf("%s \n", name);


    //2
    char str1[] = "Hello";
    char str2[] = "Helloo";

    int result = myStrCmp(str1, str2);
    if (result == 0) {
        printf("Strings are equal\n");
    } else if (result < 0) {
        printf("str1 is less than str2\n");
    } else {
        printf("str1 is greater than str2\n");
    }

    //3
    int len = myStrLen(str1);
    printf("Length of the string: %d\n", len);


    //4
    myStrCpy(str1, str2);
    printf("Source: %s\n", str1);
    printf("Destination: %s\n", str2);

    //5
    char str3[] = "Hello, World!";
    char str4[] = "WELCOME IN C PROGRAMMING";

    printf("Original str3: %s\n", str3);
    toUpperCase(str3);
    printf("Uppercase str3: %s\n", str3);

    printf("Original str4: %s\n", str4);
    toLowerCase(str4);
    printf("Lowercase str4: %s\n", str4);

    return 0;
}
