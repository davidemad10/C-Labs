#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
#include <dos.h>
#include <dir.h>
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13

void SetColor(int ForgC){
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }


// Clear the console screen
void clearScreen() {
    printf("\033[2J\033[H");
}

// Display the menu and highlight the selected option
void displayMenu(int selected) {
    clearScreen();

    for (int i = 1; i <= 3; i++) {
        if (i == selected) {
            SetColor(20);
        } else {
            SetColor(7);
        }

        if (i == 1) printf("1. New\n");
        if (i == 2) printf("2. Display\n");
        if (i == 3) printf("3. Exit\n");
    }
    SetColor(7);
}

int main() {
    int selected = 1;
    int exit=0;
    int ch;

    displayMenu(selected);

    while (exit==0) {
        ch = _getch();

        if (ch == 0 || ch == 224) {
            ch = _getch();
            if (ch == UP) {
                selected = (selected == 1) ? 3 : selected - 1;
            } else if (ch == DOWN) {
                selected = (selected == 3) ? 1 : selected + 1;
            }
        } else if (ch == ENTER) {
            exit=1;
        }

        displayMenu(selected);
    }

    clearScreen();
    printf("You selected option %d\n", selected);

    return 0;
}
