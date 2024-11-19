#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
void gotoxy1(int x,int y){
COORD coord;
coord.X = y+3;
coord.Y = x+3;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int main()
{
  int N;
  int oddNumber = 0;




  while (oddNumber != 1){
   printf("Enter Odd Number: \n");
   scanf("%d",&N);

  if( N % 2 !=0 && N>0){
    oddNumber = 1;
  }
  else{
    printf("NOT AN ODD NUMBER!");
  }
  }



  int x = 0, y=((N-1)/2)*5;
   Sleep(300);
   gotoxy1(x,y);
        printf("%d",1);

  for(int i = 1;i<(N*N);i++){

    if(i % N != 0){
       if(x != 0) {x-=5;}
       else {x = (N-1)*5;}
       if(y != 0) {y-=5;}
       else {y = (N-1)*5;}

       Sleep(300);
       gotoxy1(x,y);
        printf("%d",i+1);

    }
    else{
        if(x==(N-1)*5) {x=0;}
        else {x+=5;}
Sleep(300);
        gotoxy1(x,y);
        printf("%d",i+1);


    }
  }


    return 0;
}
