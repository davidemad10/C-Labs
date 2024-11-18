#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice=0;
    printf("Please choose your favourite programming language: \n");
    printf("1- C is best programming language. \n");
    printf("2- Python is best programming language. \n");
    printf("3- Java is best programming language. \n");
    scanf(" %d",&choice);
    switch (choice){
    case 1:
        printf("C is the best programming language. \n");
        break;
    case 2:
        printf("Python is the best programming language. \n");
        break;
    case 3:
        printf("Java is the best the programming language. \n");
        break;
    default:
        printf("Wrong choice please select 1,2 or 3 \n");
        break;
    }

    return 0;
}
